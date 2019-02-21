#pragma once
#include "ofMain.h"
#include "DataTransform/Logger.h"
#include "DataTransform/Mapper.h"
#include "Body/Skeleton.h"
#include "Draw/BodyRenderer.h"


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
    void beginRecord(string filename);
    void endRecording();
    void setReceiveFromKinect();
    void setReceiveFromFile(string filename);

protected:
    
    string buildDebugString();
	string parseLogger();
    void readNextLineFromFile();
    void processLine();

	ofxOscReceiver receiver;
	ofxOscMessage lastMessage;
	string lastParsedMessage;
	Logger logger;
	Mapper mapper;
	vector<Skeleton> skeletons;
	ofTrueTypeFont font;
	bool isDebugEnabled;
    bool isRecorded;
    ofBuffer buffer;
    string currentLine;
    ofFile *file;
    int frame;
    bool recording;
};