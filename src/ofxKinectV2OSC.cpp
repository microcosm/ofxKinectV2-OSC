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
	for (int i = 0; i < logger.size(); i++) {
		ofDrawBitmapString(logger.getLine(i), 40, i * 20);
	}
}