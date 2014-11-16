#pragma once
#include "ofMain.h"

enum TrackingState {
	TRACKED, NOT_TRACKED, INFERRED
};

class Joint {
public:
    float x();
    float y();
    float z();
	void setType(string _type);
	void setPoint(ofVec3f _point);
	void setTrackingState(TrackingState _trackingState);

	string getType();
	ofVec3f getPoint();
	TrackingState getTrackingState();
    float distanceTo(Joint* other);
	
	bool isTracked();
	bool isInferred();
	bool isNotTracked();

protected:
	string type;
	TrackingState trackingState;
	ofVec3f point;
};