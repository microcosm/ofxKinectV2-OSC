#include "Mapper.h"

void Mapper::mapTo(vector<Skeleton>* skeletons) {
	this->skeletons = skeletons;
}

void Mapper::map(ofxOscMessage message) {
	tokenize(message.getAddress());
	if(isBody()) {
		Skeleton* skeleton = getSkeleton(addressTokens[1]);
		Joint joint = getJoint(message);
		skeleton->setJoint(joint);
	}
}

void Mapper::refresh() {
	skeletons->clear();
}

void Mapper::tokenize(string address) {
	istringstream iss(address);
	string token;
	addressTokens.clear();
	while(getline(iss, token, '/')) {
		if(token != ""){
			addressTokens.push_back(token);
		}
	}
}

bool Mapper::isBody() {
	return addressTokens[0] == "bodies";
}

Skeleton* Mapper::getSkeleton(string id) {
	for(int i = 0; i < skeletons->size(); i++) {
		if(skeletons->at(i).getBodyId() == id) {
			return &skeletons->at(i);
		}
	}
	return newSkeleton(id);
}

Skeleton* Mapper::newSkeleton(string id) {
	Skeleton skeleton;
	skeleton.init(id);
	skeletons->push_back(skeleton);
	return &skeletons->at(skeletons->size()-1);
}

Joint Mapper::getJoint(ofxOscMessage &message) {
	Joint joint;
	joint.setType(getType(message));
	joint.setPoint(getPoint(message));
	joint.setTrackingState(getTrackingState(message));
	return joint;
}

string Mapper::getType(ofxOscMessage &message) {
	return addressTokens[3];
}

ofVec3f Mapper::getPoint(ofxOscMessage &message) {
	ofVec3f point;
	point.x = message.getArgAsFloat(0);
	point.y = message.getArgAsFloat(1);
	point.z = message.getArgAsFloat(2);
	return orient(point);
}

string Mapper::getTrackingState(ofxOscMessage &message) {
	return message.getArgAsString(3);
}

ofVec3f Mapper::orient(ofVec3f &point){
	point.x = ofMap(point.x, -1, 1, 0, ofGetWidth());
	point.y = ofMap(point.y, -1, 1, ofGetHeight(), 0);
	point.z = ofMap(point.z, 0, 2, 30, 10);
	return point;
}