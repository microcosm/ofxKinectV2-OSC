#include "ofApp.h"

void ofApp::setup(){
	thinKinect.setup(12345);
}

void ofApp::update(){
	thinKinect.update();
}

void ofApp::draw(){
	thinKinect.drawDebug();
	vector<Skeleton>* skeletons = thinKinect.getSkeletons();

	for(int i = 0; i < skeletons->size(); i++) {
		drawSkeleton(&skeletons->at(i));
	}
}

void ofApp::drawSkeleton(Skeleton* skeleton) {
	drawJoint(orient(skeleton->getThumbRight()));
	drawJoint(orient(skeleton->getSpineBase()));
	drawJoint(orient(skeleton->getSpineMid()));
	drawJoint(orient(skeleton->getNeck()));
	drawJoint(orient(skeleton->getHead()));
	drawJoint(orient(skeleton->getShoulderLeft()));
	drawJoint(orient(skeleton->getElbowLeft()));
	drawJoint(orient(skeleton->getWristLeft()));
	drawJoint(orient(skeleton->getHandLeft()));
	drawJoint(orient(skeleton->getShoulderRight()));
	drawJoint(orient(skeleton->getElbowRight()));
	drawJoint(orient(skeleton->getWristRight()));
	drawJoint(orient(skeleton->getHandRight()));
	drawJoint(orient(skeleton->getHipLeft()));
	drawJoint(orient(skeleton->getKneeLeft()));
	drawJoint(orient(skeleton->getAnkleLeft()));
	drawJoint(orient(skeleton->getFootLeft()));
	drawJoint(orient(skeleton->getHipRight()));
	drawJoint(orient(skeleton->getKneeRight()));
	drawJoint(orient(skeleton->getAnkleRight()));
	drawJoint(orient(skeleton->getFootRight()));
	drawJoint(orient(skeleton->getSpineShoulder()));
	drawJoint(orient(skeleton->getHandTipLeft()));
	drawJoint(orient(skeleton->getThumbLeft()));
	drawJoint(orient(skeleton->getHandTipRight()));
}

ofVec3f ofApp::orient(ofVec3f point){
	point.x = ofMap(point.x, -1, 1, 0, ofGetWidth());
	point.y = ofMap(point.y, -1, 1, ofGetHeight(), 0);
	point.z = ofMap(point.z, 0, 2, 30, 10);
	return point;
}

void ofApp::drawJoint(ofVec3f point){
	ofCircle(point.x, point.y, point.z);
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
