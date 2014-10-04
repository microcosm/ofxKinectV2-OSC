#include "ofxKinectV2OSC.h"

void ofxKinectV2OSC::setup(int port, ofTrueTypeFont &_font) {
	isDebugEnabled = false;
	font = _font;
	receiver.setup(port);
	mapper.mapTo(&skeletons);
}

void ofxKinectV2OSC::update() {
	while(receiver.hasWaitingMessages()) {
		receiver.getNextMessage(&lastMessage);
		logger.log(lastMessage);
		mapper.map(lastMessage);
	}
}

vector<Skeleton>* ofxKinectV2OSC::getSkeletons() {
	return &skeletons;
}

void ofxKinectV2OSC::drawDebug() {
	if(isDebugEnabled) {
		string debug = buildDebugString();
		font.drawString(debug, 220, 40);
	}
}

void ofxKinectV2OSC::toggleDebug() {
	isDebugEnabled = !isDebugEnabled;
}

string ofxKinectV2OSC::buildDebugString() {
	string debug = "DEBUG\n";
	if(logger.size() == 0) {
		debug.append("\nNo data received... try re-initiating the source");
	} else {
		debug.append(parseLogger());
	}
	return debug;
}

string ofxKinectV2OSC::parseLogger() {
	string parsed = "";
	for (int i = 0; i < logger.size(); i++) {
		parsed.append("\n" + logger.getLine(i));
	}
	return parsed;
}