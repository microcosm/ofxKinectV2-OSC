#pragma once
#include "ofMain.h"
#include "DataTransform/Logger.h"
#include "DataTransform/Mapper.h"
#include "Body/Skeleton.h"

class ofxKinectV2OSC {
public:
	void setup(int port, ofTrueTypeFont &_font);
	void update();
	vector<Skeleton>* getSkeletons();
    void parseOscMessages();
    void clearStaleSkeletons();
	void drawDebug();
	void toggleDebug();

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
};