#include "Parser.h"

void Parser::setMessage(ofxOscMessage messageToParse) {
	message = messageToParse;
	tokenize(message.getAddress());
}

string Parser::parseBodyId() {
	return addressTokens[1];
}

Hand Parser::parseHand() {
	hand.setState(parseHandState());
	hand.setConfidence(parseHandConfidence());
	hand.setPosition(parseHandPosition());
	return hand;
}

Joint Parser::parseJoint() {
	joint.setType(parseJointType());
	joint.setPoint(parseJointPoint());
	joint.setTrackingState(parseJointTrackingState());
	return joint;
}

bool Parser::isBody() {
	return addressTokens[0] == "bodies";
}

bool Parser::isJoint() {
	return addressTokens[2] == "joints";
}

bool Parser::isHand() {
	return addressTokens[2] == "hands";
}

HandState Parser::parseHandState() {
	string state = message.getArgAsString(0);
	if(state == "Open") return OPEN;
	else if(state == "Closed") return CLOSED;
	return UNKNOWN;
}

HandConfidence Parser::parseHandConfidence() {
	string confidence = message.getArgAsString(1);
	if(confidence == "High") return HIGH;
	return LOW;
}

HandPosition Parser::parseHandPosition() {
	string position = addressTokens[3];
	if(position == "Left") return LEFT;
	return RIGHT;
}

string Parser::parseJointType() {
	return addressTokens[3];
}

ofVec3f Parser::parseJointPoint() {
	ofVec3f point;
	point.x = message.getArgAsFloat(0);
	point.y = message.getArgAsFloat(1);
	point.z = message.getArgAsFloat(2);
	return orient(point);
}

TrackingState Parser::parseJointTrackingState() {
	string trackingState = message.getArgAsString(3);
	if(trackingState == "Tracked") return TRACKED;
	else if(trackingState == "Inferred") return INFERRED;
	else return NOT_TRACKED;
}

void Parser::tokenize(string address) {
	istringstream iss(address);
	string token;
	addressTokens.clear();
	while(getline(iss, token, '/')) {
		if(token != ""){
			addressTokens.push_back(token);
		}
	}
}

ofVec3f Parser::orient(ofVec3f &point){
	point.x = ofMap(point.x, -1, 1, 0, ofGetWidth());
	point.y = ofMap(point.y, -1, 1, ofGetHeight(), 0);
	point.z = ofMap(point.z, 0, 2, 30, 10);
	return point;
}