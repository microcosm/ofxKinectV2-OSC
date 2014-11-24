#pragma once
#include "ofMain.h"

enum TrackingState {
	TRACKED, NOT_TRACKED, INFERRED
};

static int MAX_POINT_HISTORY = 5;

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
	void clone(Joint* other);
    float distanceTo(Joint* other);
	
	bool isTracked();
	bool isInferred();
	bool isNotTracked();

protected:
	void trimHistory();
	ofVec3f currentPoint();
	string type;
	TrackingState trackingState;
	deque<ofVec3f> pointHistory;
};