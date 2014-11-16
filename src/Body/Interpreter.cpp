#include "Interpreter.h"

ofRectangle Interpreter::leftHandRange(Joint* spineShoulder, Joint* leftShoulder) {
    ofRectangle result = handRange(spineShoulder, leftShoulder);
    result.x = result.x - estimatedSpan.x;
    return result;
}

ofRectangle Interpreter::rightHandRange(Joint* spineShoulder, Joint* rightShoulder) {
    return handRange(spineShoulder, rightShoulder);
}

ofRectangle Interpreter::handRange(Joint* spineShoulder, Joint* shoulder) {
    
    float distance = shoulder->distanceTo(spineShoulder);
    estimatedSpan.x = distance * 4;
    estimatedSpan.y = distance * 6;
    
    return ofRectangle(
        shoulder->x(),
        shoulder->y() - estimatedSpan.y * 0.5,
        estimatedSpan.x,
        estimatedSpan.y);
}