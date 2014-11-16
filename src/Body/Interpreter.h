#pragma once
#include "ofMain.h"
#include "Joint.h"

class Interpreter {
public:
    ofRectangle leftHandRange(Joint* spineShoulder, Joint* leftShoulder);
    ofRectangle rightHandRange(Joint* spineShoulder, Joint* rightShoulder);
protected:
    ofRectangle handRange(Joint* spineShoulder, Joint* shoulder);
    ofVec2f estimatedSpan;
};