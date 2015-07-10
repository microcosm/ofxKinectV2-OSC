#pragma once
#include "ofMain.h"
#include "DataTransform/Logger.h"
#include "DataTransform/Mapper.h"
#include "Body/Skeleton.h"
#include "Draw/BodyRenderer.h"

////////
//#include "FeatureTracker/ofxKinectFeatures.h"


class ofxKinectV2OSC {
public:
    void setup(int port, ofTrueTypeFont &_font);
    void setup(int port);
	void update();
	void setSmoothing(SmoothingTechnique technique);
    void setFont(ofTrueTypeFont _font);
	vector<Skeleton>* getSkeletons();
    Skeleton* getNearestSkeleton();
    bool hasSkeletons();
    void parseOscMessages();
    void clearStaleSkeletons();
	void drawDebug();
	void toggleDebug();
    
    
    
    //////
    void beginRecord(string filename) {
        file = new ofFile(filename, ofFile::WriteOnly);
        recording = true;
    }
    
    void endRecording() {
        file->close();
        recording = false;
    }

    void setReceiveFromKinect() {
        isRecorded = false;
        
    }
    void setReceiveFromFile(string filename) {
        isRecorded = true;
        buffer = ofBufferFromFile(filename); // reading into the buffer
        currentLine = buffer.getNextLine();
    }
    

protected:
	string buildDebugString();
	string parseLogger();

	ofxOscReceiver receiver;
	ofxOscMessage lastMessage;
	string lastParsedMessage;
	Logger logger;
	Mapper mapper;
	vector<Skeleton> skeletons;
	ofTrueTypeFont font;
	bool isDebugEnabled;
    
    
    
    
    ///////
    //ofxKinectFeatures featureTracker;
    //void displayOscMessage(ofxOscMessage &m);
    bool isRecorded;
    
    //void readNextLineFromFile();
    
    ofBuffer buffer;
    
    void displayOscMessage(ofxOscMessage &m)
    {
        string display = "Osc : " + m.getAddress() + " : ";
        for (int i = 0; i < m.getNumArgs(); i++)
        {
            if      (m.getArgType(i) == OFXOSC_TYPE_INT32) {
                display += "(i) "+ofToString(m.getArgAsInt32(i))+",";
            }
            else if (m.getArgType(i) == OFXOSC_TYPE_INT64) {
                display += "(i) "+ofToString(m.getArgAsInt64(i))+",";
            }
            else if (m.getArgType(i) == OFXOSC_TYPE_FLOAT) {
                display += "(f) "+ofToString(m.getArgAsFloat(i))+",";
            }
            else if (m.getArgType(i) == OFXOSC_TYPE_STRING) {
                display += "(s) "+ofToString(m.getArgAsString(i))+",";
            }
            else if (m.getArgType(i) == OFXOSC_TYPE_BLOB) {
                display += "(blob) "+ofToString(m.getArgAsBlob(i))+",";
            }
        }
        ofLog(OF_LOG_NOTICE, display);
    }
    
    
    string currentLine;
    ofFile *file;
    int frame;
    bool recording = false;
    
    
    void readNextLineFromFile()
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
    
    void processLine()
    {
        vector<string> line = ofSplitString(currentLine, ",");
        if (line.size() < 2)
        {
            buffer.getFirstLine();
            return;
        }

        string address = ofToString(line[1]);
        
        ofxOscMessage newMsg;
        newMsg.setAddress(address);

        for (int i=2; i<line.size(); i+=2) {
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

};