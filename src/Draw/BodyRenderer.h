#pragma once
#include "ofMain.h"
#include "ofxKinectV2OSC.h"

class BodyRenderer {
public:
    virtual void setup(vector<Skeleton>* _skeletons);
    virtual void setup(vector<Skeleton>* _skeletons, ofTrueTypeFont _font);
    void draw();
    void drawSkeleton(Skeleton* _skeleton);
    void loadFont(ofTrueTypeFont _font);
	
	void toggleHands();
    void toggleBones();
    void toggleJoints();
    void toggleRanges();
    void hideAll();
    void showAll();
    
	void drawHands();
	virtual void drawHand(Hand hand, Joint handJoint);

	void drawBones();
    void drawTorso();
    void drawRightArm();
    void drawLeftArm();
    void drawRightLeg();
    void drawLeftLeg();
	virtual void drawBone(Joint joint1, Joint joint2);

	void drawJoints();
	virtual void drawJoint(Joint joint);
    
    void drawRanges();
    virtual void drawRange(ofRectangle range, Joint hand, ofVec2f normal);

    

protected:
	TrackingState combinedTrackingState(Joint &joint1, Joint &joint2);

	vector<Skeleton>* skeletons;
	Skeleton* skeleton;
    ofTrueTypeFont font;
    string normalReport;

	bool isDrawHandsEnabled, isDrawBonesEnabled, isDrawJointsEnabled, isDrawRangesEnabled, isFontEnabled;
};