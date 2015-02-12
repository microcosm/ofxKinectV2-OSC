#include "ofxKinectV2OSC.h"

void ofxKinectV2OSC::setup(int port, ofTrueTypeFont &_font) {
	isDebugEnabled = false;
	setFont(_font);
	receiver.setup(port);
	mapper.mapTo(&skeletons);
}

void ofxKinectV2OSC::update() {
	parseOscMessages();
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