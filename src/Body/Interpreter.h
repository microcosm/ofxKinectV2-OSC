#pragma once
#include "ofMain.h"
#include "Joint.h"

class Interpreter {
public:
    ofRectangle leftHandRange(Joint* spineShoulder, Joint* leftShoulder);
    ofRectangle rightHandRange(Joint* spineShoulder, Joint* rightShoulder);
    ofVec2f leftHandNormal(Joint* leftHand, Joint* spineShoulder, Joint* leftShoulder);
    ofVec2f rightHandNormal(Joint* rightHand, Joint* spineShoulder, Joint* rightShoulder);
protected:
    ofRectangle handRange(Joint* spineShoulder, Joint* shoulder);
    ofVec2f normalise(Joint* joint, ofRectangle range);
    ofVec2f estimatedSpan;
};