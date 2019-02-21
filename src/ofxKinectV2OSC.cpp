#include "ofxKinectV2OSC.h"

void ofxKinectV2OSC::setup(int port, ofTrueTypeFont &_font) {
    setFont(_font);
    setup(port);
    isRecorded = false;
}

void ofxKinectV2OSC::setup(int port) {
    isDebugEnabled = false;
    receiver.setup(port);
    mapper.mapTo(&skeletons);
}

void ofxKinectV2OSC::update() {
    if (isRecorded) {
        readNextLineFromFile();
    }
    else {
        parseOscMessages();
    }
    clearStaleSkeletons();
}

void ofxKinectV2OSC::setSmoothing(SmoothingTechnique technique) {
	mapper.setSmoothing(technique);
}

void ofxKinectV2OSC::setFont(ofTrueTypeFont _font) {
    font = _font;
    if(!font.isLoaded()) {
        isDebugEnabled = true;
    }
}

vector<Skeleton>* ofxKinectV2OSC::getSkeletons() {
    return &skeletons;
}

Skeleton* ofxKinectV2OSC::getNearestSkeleton() {
    Skeleton* nearestSkeleton;
    for(int i = 0; i < skeletons.size(); i++) {
        if(i == 0 || skeletons.at(i).isCloserThan(nearestSkeleton)) {
            nearestSkeleton = &skeletons.at(i);
        }
    }
    return nearestSkeleton;
}

bool ofxKinectV2OSC::hasSkeletons() {
    return skeletons.size() > 0;
}

void ofxKinectV2OSC::parseOscMessages() {
    while(receiver.hasWaitingMessages()) {
		receiver.getNextMessage(&lastMessage);
        
        if (recording) {
            string nextLine;
            nextLine = ofToString(ofGetFrameNum())+","+lastMessage.getAddress()+",";
            
            for (int i = 0; i < lastMessage.getNumArgs(); i++)
            {
                if      (lastMessage.getArgType(i) == OFXOSC_TYPE_INT32) {
                    nextLine += "i,"+ofToString(lastMessage.getArgAsInt32(i))+",";
                }
                else if (lastMessage.getArgType(i) == OFXOSC_TYPE_INT64) {
                    nextLine += "i,"+ofToString(lastMessage.getArgAsInt64(i))+",";
                }
                else if (lastMessage.getArgType(i) == OFXOSC_TYPE_FLOAT) {
                    nextLine += "f,"+ofToString(lastMessage.getArgAsFloat(i))+",";
                }
                else if (lastMessage.getArgType(i) == OFXOSC_TYPE_STRING) {
                    nextLine += "s,"+ofToString(lastMessage.getArgAsString(i))+",";
                }
                else if (lastMessage.getArgType(i) == OFXOSC_TYPE_BLOB) {
                    nextLine += "b,"+ofToString(lastMessage.getArgAsBlob(i))+",";
                }
            }

            *file << nextLine.substr(0, nextLine.length()-1) + "\n";
        }
        
		logger.log(lastMessage);
		mapper.map(lastMessage);
	}
}

void ofxKinectV2OSC::clearStaleSkeletons() {
    for(int i = 0; i < skeletons.size(); i++) {
        Skeleton* skeleton = &skeletons.at(i);
        skeleton->update();
        if(skeleton->isStale()) {
            skeletons.erase(skeletons.begin() + i);
        }
    }
}

void ofxKinectV2OSC::drawDebug() {
	if(isDebugEnabled) {
		string debug = buildDebugString();
        if(font.isLoaded()) {
            font.drawString(debug, 220, 40);
        } else {
            ofDrawBitmapString(debug, 60, 60);
        }
	}
}

void ofxKinectV2OSC::toggleDebug() {
	isDebugEnabled = !isDebugEnabled;
}

string ofxKinectV2OSC::buildDebugString() {
	string debug = "DEBUG\n";
    if(!font.isLoaded()) {
        debug.append("\nFont not loaded correctly... see ofApp() and copy the font into the bin/data directory\n");
    }
    
	if(logger.size() == 0) {
		debug.append("\nNo data received... try re-initiating the source");
	} else {
		debug.append(parseLogger());
	}
	return debug;
}

string ofxKinectV2OSC::parseLogger() {
	string parsed = "";
	for (int i = 0; i < logger.size(); i++) {
		parsed.append("\n" + logger.getLine(i));
	}
	return parsed;
}

void ofxKinectV2OSC::beginRecord(string filename) {
    file = new ofFile(filename, ofFile::WriteOnly);
    recording = true;
}

void ofxKinectV2OSC::endRecording() {
    file->close();
    recording = false;
}

void ofxKinectV2OSC::setReceiveFromKinect() {
    isRecorded = false;
}

void ofxKinectV2OSC::setReceiveFromFile(string filename) {
    isRecorded = true;
    buffer = ofBufferFromFile(filename); // reading into the buffer
    currentLine = buffer.getNextLine();
}

void ofxKinectV2OSC::readNextLineFromFile()
{
    frame = ofToInt(ofSplitString(currentLine, ",")[0]);
    processLine();
    bool isDone = false;
    while (!isDone)
    {
        currentLine = buffer.getNextLine();
        int nextFrame = ofToInt(ofSplitString(currentLine, ",")[0]);
        if (nextFrame != frame || buffer.isLastLine()) {
            isDone = true;
        }
        else {
            processLine();
        }
    }
}

void ofxKinectV2OSC::processLine()
{
    vector<string> line = ofSplitString(currentLine, ",");
    if (line.size() < 2)
    {
        buffer.getFirstLine();
        return;
    }
    
    // send fake osc message
    ofxOscMessage newMsg;
    newMsg.setAddress(ofToString(line[1]));
    for (int i=2; i<line.size(); i+=2)
    {
        string type = line[i];
        if (type =="i"){
            newMsg.addIntArg(ofToInt(line[i+1]));
        }
        else if (type == "f") {
            newMsg.addFloatArg(ofToFloat(line[i+1]));
        }
        else if (type == "s") {
            newMsg.addStringArg(ofToString(line[i+1]));
        }
    }    
    logger.log(newMsg);
    mapper.map(newMsg);
}
