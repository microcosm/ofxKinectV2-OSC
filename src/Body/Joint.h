#pragma once
#include "ofMain.h"

enum SmoothingTechnique {
	NO_SMOOTHING,
	SIMPLE_MOVING_AVERAGE
};

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
	void setSmoothing(SmoothingTechnique _smoothing);

	string getType();
	ofVec3f getPoint();
	TrackingState getTrackingState();
	SmoothingTechnique getSmoothing();
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
	SmoothingTechnique smoothing;
};