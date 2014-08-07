#pragma once
#include "ofMain.h"
#include "Skeleton.h"
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
	ofVec3f getPoint(ofxOscMessage message);void assign(Skeleton* skeleton, string jointType, ofVec3f point);
	
	vector<Skeleton>* skeletons;
	vector<string> addressTokens;
};