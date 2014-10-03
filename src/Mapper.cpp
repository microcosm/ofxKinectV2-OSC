#include "Mapper.h"

void Mapper::mapTo(vector<Skeleton>* skeletons) {
	this->skeletons = skeletons;
}

void Mapper::map(ofxOscMessage &_message) {
	message = _message;
	tokenize(message.getAddress());
	if(isBody()) {
		Skeleton* skeleton = getSkeleton(addressTokens[1]);
		if(isJoint()) {
			skeleton->setJoint(parseJoint());
		} else if(isHand()) {
			skeleton->setHand(parseHand());
		}
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

bool Mapper::isJoint() {
	return addressTokens[2] == "joints";
}

bool Mapper::isHand() {
	return addressTokens[2] == "hands";
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

Hand Mapper::parseHand() {
	Hand hand;
	hand.setState(parseHandState());
	hand.setConfidence(parseHandConfidence());
	hand.setPosition(parseHandPosition());
	return hand;
}

HandState Mapper::parseHandState() {
	string state = message.getArgAsString(0);
	if(state == "Open") return OPEN;
	else if(state == "Closed") return CLOSED;
	return UNKNOWN;
}

HandConfidence Mapper::parseHandConfidence() {
	string confidence = message.getArgAsString(1);
	if(confidence == "High") return HIGH;
	return LOW;
}

HandPosition Mapper::parseHandPosition() {
	string position = addressTokens[3];
	if(position == "Left") return LEFT;
	return RIGHT;
}

Joint Mapper::parseJoint() {
	Joint joint;
	joint.setType(parseJointType());
	joint.setPoint(parseJointPoint());
	joint.setTrackingState(parseJointTrackingState());
	return joint;
}

string Mapper::parseJointType() {
	return addressTokens[3];
}

ofVec3f Mapper::parseJointPoint() {
	ofVec3f point;
	point.x = message.getArgAsFloat(0);
	point.y = message.getArgAsFloat(1);
	point.z = message.getArgAsFloat(2);
	return orient(point);
}

TrackingState Mapper::parseJointTrackingState() {
	string trackingState = message.getArgAsString(3);
	if(trackingState == "Tracked") return TRACKED;
	else if(trackingState == "Inferred") return INFERRED;
	else return NOT_TRACKED;
}

ofVec3f Mapper::orient(ofVec3f &point){
	point.x = ofMap(point.x, -1, 1, 0, ofGetWidth());
	point.y = ofMap(point.y, -1, 1, ofGetHeight(), 0);
	point.z = ofMap(point.z, 0, 2, 30, 10);
	return point;
}