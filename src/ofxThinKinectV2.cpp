#include "ofxThinKinectV2.h"
#define DEBUG_BUFFER_SIZE 40

void ofxThinKinectV2::setup(int port) {
	receiver.setup(port);
}

void ofxThinKinectV2::update() {
	while(receiver.hasWaitingMessages()) {
		ofxOscMessage m;
		receiver.getNextMessage(&m);
		log(parse(m));
	}
}

void ofxThinKinectV2::drawDebug() {
	for (int i = 0; i < buffer.size(); i++) {
		ofDrawBitmapString(buffer[i], 40, i * 20);
	}
}

string ofxThinKinectV2::parse(ofxOscMessage message) {
	string result;
	result = message.getAddress();
	result += ": [";

	for(int i = 0; i < message.getNumArgs(); i++) {
		result += " " + message.getArgTypeName(i) + ":";

		switch(message.getArgType(i)) {
			case OFXOSC_TYPE_INT32:
				result += ofToString(message.getArgAsInt32(i));
				break;
			case OFXOSC_TYPE_FLOAT:
				result += ofToString(message.getArgAsFloat(i));
				break;
			case OFXOSC_TYPE_STRING:
				result += message.getArgAsString(i);
				break;
			default:
				result += "unknown";
		}
		result += " ";
	};
	return result + "]";
}

void ofxThinKinectV2::log(string parsedMessage) {
	buffer.insert(buffer.begin(), parsedMessage);
	if(buffer.size() > DEBUG_BUFFER_SIZE) {
		buffer.pop_back();
	}
}