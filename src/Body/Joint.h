#pragma once
#include "ofMain.h"

enum SmoothingTechnique {
	NO_SMOOTHING,
	SIMPLE_MOVING_AVERAGE
};

enum TrackingState {
	TRACKED, NOT_TRACKED, INFERRED
};

static int MAX_POINT_HISTORY = 3;

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
	void clone(Joint* other, SmoothingTechnique technique);
    float distanceTo(Joint* other);
	
	bool isTracked();
	bool isInferred();
	bool isNotTracked();

protected:
	void trimHistory();
	ofVec3f currentPoint();
	ofVec3f simpleMovingAveragePoint();
	string type;
	TrackingState trackingState;
	deque<ofVec3f> pointHistory;
	ofVec3f calcPoint;
	SmoothingTechnique smoothing;
};