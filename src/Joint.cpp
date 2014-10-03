#include "Joint.h"

void Joint::setType(string _type) {
	type = _type;
}

void Joint::setPoint(ofVec3f _point) {
	point = _point;
}

void Joint::setTrackingState(string _trackingState) {
	trackingState = _trackingState;
}

string Joint::getType() {
	return type;
}

ofVec3f Joint::getPoint() {
	return point;
}

string Joint::getTrackingState() {
	return trackingState;
}