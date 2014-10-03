#include "ofApp.h"

void ofApp::setup(){
	smallFont.loadFont("selena.otf", 16); //http://openfontlibrary.org/en/font/selena
	largeFont.loadFont("selena.otf", 48);

	kinect.setup(12345);
	kinect.loadFont(smallFont);

	drawDebug = false;
	drawJoints = drawBones = true;

	ofSetLineWidth(8);
	ofSetFrameRate(60);
}

void ofApp::update(){
	kinect.update();
}

void ofApp::draw(){

	ofBackground(ofColor::darkGray);
	if(drawDebug) kinect.drawDebug();
	
	vector<Skeleton>* skeletons = kinect.getSkeletons();
	for(int i = 0; i < skeletons->size(); i++) {
		skeleton = &skeletons->at(i);
		if(drawBones) skeleton->drawBones();
		if(drawJoints) skeleton->drawJoints();
	}

	string commands = "COMMANDS\n\n";
	commands.append("d = debug\n");
	commands.append("j = joints\n");
	commands.append("b = bones\n");

	ofSetColor(ofColor::white);
	smallFont.drawString(commands, 20, 40);
	largeFont.drawString("fps:\n" + ofToString(ofGetFrameRate()), 20, ofGetHeight() - 100);
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
