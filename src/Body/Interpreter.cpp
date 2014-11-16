#include "Interpreter.h"

ofRectangle Interpreter::leftHandRange(Joint* spineShoulder, Joint* leftShoulder) {
    float estimatedSpan = leftShoulder->distanceTo(spineShoulder) * 4;
    
    return ofRectangle(
        spineShoulder->x() - estimatedSpan,
        leftShoulder->y() - estimatedSpan,
        estimatedSpan,
        estimatedSpan * 2);
}

ofRectangle Interpreter::rightHandRange(Joint* spineShoulder, Joint* rightShoulder) {
    float estimatedSpan = spineShoulder->distanceTo(rightShoulder) * 4;
    
    return ofRectangle(
        rightShoulder->x(),
        rightShoulder->y() - estimatedSpan,
        estimatedSpan,
        estimatedSpan * 2);
}