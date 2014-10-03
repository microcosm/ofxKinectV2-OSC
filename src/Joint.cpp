#include "Joint.h"

void Joint::setType(string _type) {
	type = _type;
}

void Joint::setPoint(ofVec3f _point) {
	point = _point;
}

void Joint::setTrackingState(string _trackingState) {
	if(_trackingState == "Tracked") trackingState = TRACKED;
	else if(_trackingState == "Inferred") trackingState = INFERRED;
	else trackingState = NOT_TRACKED;
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

bool Joint::isTracked() {
	return trackingState == TRACKED;
}

bool Joint::isInferred() {
	return trackingState == INFERRED;
}

bool Joint::isNotTracked() {
	return trackingState == NOT_TRACKED;
}