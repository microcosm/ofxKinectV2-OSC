#pragma once
#include "ofMain.h"
#include "Joint.h"

class Interpreter {
public:
    ofRectangle leftHandRange(Joint* spineShoulder, Joint* leftShoulder);
    ofRectangle rightHandRange(Joint* spineShoulder, Joint* rightShoulder);
    ofVec3f leftHandNormal(Joint* leftHand, Joint* spineShoulder, Joint* leftShoulder);
    ofVec3f rightHandNormal(Joint* rightHand, Joint* spineShoulder, Joint* rightShoulder);
protected:
    ofRectangle handRange(Joint* spineShoulder, Joint* shoulder);
    ofVec3f normalise(Joint* joint, ofRectangle range, float torsoDistance, bool reverseX=false);
    ofVec2f estimatedSpan;
};