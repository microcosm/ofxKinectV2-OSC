#pragma once
#include "ofMain.h"
#include "ofxKinectV2OSC.h"

class BodyRenderer {
public:
	void setup(vector<Skeleton>* _skeletons);
	
	void toggleHands();
	void toggleBones();
	void toggleJoints();

	void draw();
	void drawHands();
	void drawHand(Hand &hand, Joint &handJoint);

	void drawBones();
	void drawBone(Joint &joint1, Joint &joint2);

	void drawJoints();
	void drawJoint(Joint &joint);

	void drawTorso();
	void drawRightArm();
	void drawLeftArm();
	void drawRightLeg();
	void drawLeftLeg();

protected:
	TrackingState combinedTrackingState(Joint &joint1, Joint &joint2);

	vector<Skeleton>* skeletons;
	Skeleton* skeleton;

	bool isDrawHandsEnabled, isDrawBonesEnabled, isDrawJointsEnabled;
};