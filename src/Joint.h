#pragma once
#include "ofMain.h"

class Joint {
public:
	void setType(string _type);
	void setPoint(ofVec3f _point);
	void setTrackingState(string _trackingState);

	string getType();
	ofVec3f getPoint();
	string getTrackingState();

protected:
	string type, trackingState;
	ofVec3f point;
};