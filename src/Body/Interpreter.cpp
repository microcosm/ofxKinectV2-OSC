#include "Interpreter.h"

ofRectangle Interpreter::leftHandRange(Joint* spineShoulder, Joint* leftShoulder) {
    ofRectangle result = handRange(spineShoulder, leftShoulder);
    result.x -= estimatedSpan.x;
    return result;
}

ofRectangle Interpreter::rightHandRange(Joint* spineShoulder, Joint* rightShoulder) {
    return handRange(spineShoulder, rightShoulder);
}

ofVec2f Interpreter::leftHandNormal(Joint* leftHand, Joint* spineShoulder, Joint* leftShoulder) {
    ofRectangle range = leftHandRange(spineShoulder, leftShoulder);
    return normalise(leftHand, range);
}

ofVec2f Interpreter::rightHandNormal(Joint* rightHand, Joint* spineShoulder, Joint* rightShoulder) {
    ofRectangle range = rightHandRange(spineShoulder, rightShoulder);
    return normalise(rightHand, range);
}

ofRectangle Interpreter::handRange(Joint* spineShoulder, Joint* shoulder) {
    float distance = shoulder->distanceTo(spineShoulder);
    estimatedSpan.x = distance * 3.5;
    estimatedSpan.y = distance * 4.7;
    
    return ofRectangle(
        spineShoulder->x(),
        shoulder->y() - estimatedSpan.y * 0.57,
        estimatedSpan.x,
        estimatedSpan.y);
}

ofVec2f Interpreter::normalise(Joint *joint, ofRectangle range) {
    ofVec2f normal;
    normal.x = ofMap(joint->x(), range.x, range.x + range.width, 0, 1, true);
    normal.y = ofMap(joint->y(), range.y, range.y + range.height, 0, 1, true);
    return normal;
}