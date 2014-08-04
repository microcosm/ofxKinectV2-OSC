#include "ofxThinKinectV2.h"

void ofxThinKinectV2::setup(int port) {
	receiver.setup(port);
}

void ofxThinKinectV2::update() {
	while(receiver.hasWaitingMessages()) {
		receiver.getNextMessage(&lastMessage);
		lastParsedMessage = parse(lastMessage);
		logger.log(lastParsedMessage);
	}
}

void ofxThinKinectV2::drawDebug() {
	for (int i = 0; i < logger.size(); i++) {
		ofDrawBitmapString(logger.getLine(i), 40, i * 20);
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