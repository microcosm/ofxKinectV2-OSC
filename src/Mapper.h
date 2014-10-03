#pragma once
#include "ofMain.h"
#include "Skeleton.h"
#include "Joint.h"
#include "Hand.h"
#include "ofxOscReceiver.h"

class Mapper {
public:
	void mapTo(vector<Skeleton>* skeletons);
	void map(ofxOscMessage &_message);
	void refresh();

protected:
	void tokenize(string message);
	bool isBody();
	bool isJoint();
	bool isHand();

	Skeleton* getSkeleton(string id);
	Skeleton* newSkeleton(string id);

	Hand parseHand();
	HandState parseHandState();
	HandConfidence parseHandConfidence();
	HandPosition parseHandPosition();

	Joint parseJoint();
	string parseJointType();
	ofVec3f parseJointPoint();
	TrackingState parseJointTrackingState();

	ofVec3f orient(ofVec3f &point);
	
	vector<Skeleton>* skeletons;
	vector<string> addressTokens;
	ofxOscMessage message;
};