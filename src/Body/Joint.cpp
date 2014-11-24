#include "Joint.h"

float Joint::x() {
    return currentPoint().x;
}

float Joint::y() {
    return currentPoint().y;
}

float Joint::z() {
    return currentPoint().z;
}

void Joint::setType(string _type) {
	type = _type;
}

void Joint::setPoint(ofVec3f _point) {
	pointHistory.push_front(_point);
	trimHistory();
}

void Joint::setTrackingState(TrackingState _trackingState) {
	trackingState = _trackingState;
}

void Joint::setSmoothing(SmoothingTechnique _smoothing) {
	smoothing = _smoothing;
}

string Joint::getType() {
	return type;
}

ofVec3f Joint::getPoint() {
	return currentPoint();
}

TrackingState Joint::getTrackingState() {
	return trackingState;
}

SmoothingTechnique Joint::getSmoothing() {
	return smoothing;
}

void Joint::clone(Joint* other) {
	setPoint(other->getPoint());
	setType(other->getType());
	setTrackingState(other->getTrackingState());
	setSmoothing(other->getSmoothing());
}

float Joint::distanceTo(Joint* other) {
    return currentPoint().distance(other->getPoint());
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

void Joint::trimHistory() {
	if(pointHistory.size() > MAX_POINT_HISTORY) {
		pointHistory.pop_back();
	}
}

ofVec3f Joint::currentPoint() {
	return pointHistory.at(0);
}