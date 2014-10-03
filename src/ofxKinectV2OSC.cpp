#include "ofxKinectV2OSC.h"

void ofxKinectV2OSC::setup(int port) {
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
	string debug = "DEBUG\n";

	if(logger.size() == 0) {
		debug.append("\nNo data received... try re-initiating the source");
	} else {
		for (int i = 0; i < logger.size(); i++) {
			debug.append("\n" + logger.getLine(i));
		}
	}

	font.drawString(debug, 220, 40);
}

void ofxKinectV2OSC::loadFont(ofTrueTypeFont &_font) {
	font = _font;
}