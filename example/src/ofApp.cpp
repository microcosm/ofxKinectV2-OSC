#include "ofApp.h"

void ofApp::setup(){
	kinect.setup(12345);
	ofSetLineWidth(8);
}

void ofApp::update(){
	kinect.update();
}

void ofApp::draw(){
	kinect.drawDebug();
	vector<Skeleton>* skeletons = kinect.getSkeletons();

	for(int i = 0; i < skeletons->size(); i++) {
		skeleton = &skeletons->at(i);
		skeleton->draw();
	}
}

void ofApp::keyPressed(int key){

}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
