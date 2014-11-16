#pragma once
#include "ofMain.h"
#include "ofxKinectV2OSC.h"

class BodyRenderer {
public:
    void setup(vector<Skeleton>* _skeletons);
    void draw();
	
	void toggleHands();
    void toggleBones();
    void toggleJoints();
    void toggleRanges();
    
	void drawHands();
	void drawHand(Hand hand, Joint handJoint);

	void drawBones();
    void drawTorso();
    void drawRightArm();
    void drawLeftArm();
    void drawRightLeg();
    void drawLeftLeg();
	void drawBone(Joint joint1, Joint joint2);

	void drawJoints();
	void drawJoint(Joint joint);
    
    void drawRanges();
    void drawRange(ofRectangle range);

    

protected:
	TrackingState combinedTrackingState(Joint &joint1, Joint &joint2);

	vector<Skeleton>* skeletons;
	Skeleton* skeleton;

	bool isDrawHandsEnabled, isDrawBonesEnabled, isDrawJointsEnabled, isDrawRangesEnabled;
};