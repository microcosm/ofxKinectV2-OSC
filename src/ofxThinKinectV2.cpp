#include "ofxThinKinectV2.h"

void ofxThinKinectV2::setup(int port) {
	receiver.setup(port);
	mapper.mapTo(&skeletons);
}

void ofxThinKinectV2::update() {
	while(receiver.hasWaitingMessages()) {
		receiver.getNextMessage(&lastMessage);
		logger.log(lastMessage);
		mapper.map(lastMessage);
	}
}

vector<Skeleton>* ofxThinKinectV2::getSkeletons() {
	return &skeletons;
}

void ofxThinKinectV2::drawDebug() {
	for (int i = 0; i < logger.size(); i++) {
		ofDrawBitmapString(logger.getLine(i), 40, i * 20);
	}
}