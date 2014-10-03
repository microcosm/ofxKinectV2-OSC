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
	ofDrawBitmapString("DEBUG", 170, 20);

	if(logger.size() == 0) {
		ofDrawBitmapString("No data received... try re-initiating the source", 170, 40);
	} else {
		for (int i = 0; i < logger.size(); i++) {
			ofDrawBitmapString(logger.getLine(i), 170, 60 + i * 20);
		}
	}
}