#pragma once
#include "ofMain.h"
#include "../Body/Skeleton.h"
#include "ofxOscReceiver.h"

class Parser {
public:
    Parser();
	void setMessage(ofxOscMessage messageToParse);

	string parseBodyId();
	Hand parseHand();
	Joint parseJoint();

	bool isBody();
	bool isJoint();
	bool isHand();

protected:
	HandState parseHandState();
	HandConfidence parseHandConfidence();
	HandPosition parseHandPosition();

	string parseJointType();
	ofVec3f parseJointPoint();
	TrackingState parseJointTrackingState();

	void tokenize(string address);
	ofVec3f orient(ofVec3f &point);

	Hand hand;
	Joint joint;
    
    int width, height;

	vector<string> addressTokens;
	ofxOscMessage message;
};