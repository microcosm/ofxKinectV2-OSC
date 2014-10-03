#pragma once
#include "ofMain.h"
#include "Skeleton.h"
#include "Joint.h"
#include "Hand.h"
#include "ofxOscReceiver.h"

class Mapper {
public:
	void mapTo(vector<Skeleton>* skeletons);
	void map(ofxOscMessage message);
	void refresh();

protected:
	void tokenize(string message);
	bool isBody();
	bool isJoint();
	bool isHand();

	Skeleton* getSkeleton(string id);
	Skeleton* newSkeleton(string id);

	Hand getHand(ofxOscMessage &message);
	HandState getHandState(ofxOscMessage &message);
	HandConfidence getHandConfidence(ofxOscMessage &message);
	HandPosition getHandPosition(ofxOscMessage &message);

	Joint getJoint(ofxOscMessage &message);
	string getJointType(ofxOscMessage &message);
	ofVec3f getJointPoint(ofxOscMessage &message);
	string getJointTrackingState(ofxOscMessage &message);

	ofVec3f orient(ofVec3f &point);
	
	vector<Skeleton>* skeletons;
	vector<string> addressTokens;
};