#include "Joint.h"

float Joint::x() {
    return point.x;
}

float Joint::y() {
    return point.y;
}

float Joint::z() {
    return point.z;
}

void Joint::setType(string _type) {
	type = _type;
}

void Joint::setPoint(ofVec3f _point) {
	point = _point;
}

void Joint::setTrackingState(TrackingState _trackingState) {
	trackingState = _trackingState;
}

string Joint::getType() {
	return type;
}

ofVec3f Joint::getPoint() {
	return point;
}

TrackingState Joint::getTrackingState() {
	return trackingState;
}

float Joint::distanceTo(Joint* other) {
    return point.distance(other->getPoint());
}

bool Joint::isTracked() {
	return trackingState == TRACKED;
}

bool Joint::isInferred() {
	return trackingState == INFERRED;
}

bool Joint::isNotTracked() {
	return trackingState == NOT_TRACKED;
}