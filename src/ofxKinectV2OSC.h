#pragma once
#include "ofMain.h"
#include "Logger.h"
#include "Mapper.h"
#include "Skeleton.h"

class ofxKinectV2OSC {
public:
	void setup(int port);
	void update();
	vector<Skeleton>* getSkeletons();
	void drawDebug();
protected:
	ofxOscReceiver receiver;
	ofxOscMessage lastMessage;
	string lastParsedMessage;
	Logger logger;
	Mapper mapper;
	vector<Skeleton> skeletons;
};