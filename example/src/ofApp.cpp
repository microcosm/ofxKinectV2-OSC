#include "ofApp.h"

void ofApp::setup(){
	kinect.setup(12345);
	ofSetLineWidth(8);
	drawDebug = false;
	drawJoints = drawBones = true;
	font.loadFont("selena.otf", 48); //http://openfontlibrary.org/en/font/selena
	ofSetFrameRate(60);
}

void ofApp::update(){
	kinect.update();
}

void ofApp::draw(){
	if(drawDebug) {
		font.drawString("fps:\n" + ofToString(ofGetFrameRate()), 20, ofGetHeight() - 100);
		kinect.drawDebug();
	}
	
	vector<Skeleton>* skeletons = kinect.getSkeletons();

	for(int i = 0; i < skeletons->size(); i++) {
		skeleton = &skeletons->at(i);
		if(drawBones) skeleton->drawBones();
		if(drawJoints) skeleton->drawJoints();
	}

	string instructions = "";
	instructions.append("d = draw debug\n");
	instructions.append("j = draw joints\n");
	instructions.append("b = draw bones\n");

	ofDrawBitmapString(instructions, 20, 20);
}

void ofApp::keyPressed(int key){
	if(key == 'd') drawDebug = !drawDebug;
	if(key == 'j') drawJoints = !drawJoints;
	if(key == 'b') drawBones = !drawBones;
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
