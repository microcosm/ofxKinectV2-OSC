#pragma once
#include "ofMain.h"
#include "Skeleton.h"
#include "Joint.h"
#include "ofxOscReceiver.h"

class Mapper {
public:
	void mapTo(vector<Skeleton>* skeletons);
	void map(ofxOscMessage message);
	void refresh();

protected:
	void tokenize(string message);
	bool isBody();

	Skeleton* getSkeleton(string id);
	Skeleton* newSkeleton(string id);

	Joint getJoint(ofxOscMessage &message);
	string getType(ofxOscMessage &message);
	ofVec3f getPoint(ofxOscMessage &message);
	string getTrackingState(ofxOscMessage &message);

	ofVec3f orient(ofVec3f &point);
	
	vector<Skeleton>* skeletons;
	vector<string> addressTokens;
};