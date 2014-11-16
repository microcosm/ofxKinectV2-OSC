#include "Interpreter.h"

ofRectangle Interpreter::leftHandRange(Joint* spineShoulder, Joint* leftShoulder) {
    float estimatedSpan = abs(leftShoulder->x() - spineShoulder->x()) * 4;
    
    return ofRectangle(
        spineShoulder->x() - estimatedSpan,
        leftShoulder->y() - estimatedSpan,
        estimatedSpan,
        estimatedSpan * 2);
}

ofRectangle Interpreter::rightHandRange(Joint* spineShoulder, Joint* rightShoulder) {
    float estimatedSpan = abs(spineShoulder->x() - rightShoulder->x()) * 4;
    
    return ofRectangle(
        spineShoulder->x(),
        spineShoulder->y() - estimatedSpan,
        estimatedSpan,
        estimatedSpan * 2);
}