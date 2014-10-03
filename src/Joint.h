#pragma once
#include "ofMain.h"

enum TrackingState {
	TRACKED, NOT_TRACKED, INFERRED
};

class Joint {
public:
	void setType(string _type);
	void setPoint(ofVec3f _point);
	void setTrackingState(string _trackingState);

	string getType();
	ofVec3f getPoint();
	TrackingState getTrackingState();
	
	bool isTracked();
	bool isInferred();
	bool isNotTracked();

protected:
	string type;
	TrackingState trackingState;
	ofVec3f point;
};