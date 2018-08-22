#include "BodyRenderer.h"

void BodyRenderer::setup(vector<Skeleton>* _skeletons) {
    skeletons = _skeletons;
    isDrawHandsEnabled = isDrawJointsEnabled = isDrawBonesEnabled = true;
    isDrawRangesEnabled = isFontEnabled = false;
}

void BodyRenderer::setup(vector<Skeleton>* _skeletons, ofTrueTypeFont _font) {
    setup(_skeletons);
    loadFont(_font);
}

void BodyRenderer::draw() {
    ofPushStyle();
    ofSetLineWidth(8);
    for(int i = 0; i < skeletons->size(); i++) {
        drawSkeleton(&skeletons->at(i));
    }
    ofPopStyle();
}

void BodyRenderer::drawSkeleton(Skeleton* _skeleton) {
    skeleton = _skeleton;
    if (isDrawHandsEnabled)  drawHands();
    if (isDrawBonesEnabled)  drawBones();
    if (isDrawJointsEnabled) drawJoints();
    if (isDrawRangesEnabled) drawRanges();
}

void BodyRenderer::loadFont(ofTrueTypeFont _font) {
    font = _font;
    if(font.isLoaded()) {
        isFontEnabled = true;
    }
}

void BodyRenderer::toggleHands() {
	isDrawHandsEnabled = !isDrawHandsEnabled;
}

void BodyRenderer::toggleBones() {
	isDrawBonesEnabled = !isDrawBonesEnabled;
}

void BodyRenderer::toggleJoints() {
    isDrawJointsEnabled = !isDrawJointsEnabled;
}

void BodyRenderer::toggleRanges() {
    isDrawRangesEnabled = !isDrawRangesEnabled;
}

void BodyRenderer::hideAll() {
    isDrawHandsEnabled = false;
    isDrawBonesEnabled = false;
    isDrawJointsEnabled = false;
    isDrawRangesEnabled = false;
}

void BodyRenderer::showAll() {
    isDrawHandsEnabled = true;
    isDrawBonesEnabled = true;
    isDrawJointsEnabled = true;
    isDrawRangesEnabled = true;
}

void BodyRenderer::drawHands() {
	drawHand(skeleton->getLeftHand(), skeleton->getHandLeft());
	drawHand(skeleton->getRightHand(), skeleton->getHandRight());
}

void BodyRenderer::drawHand(Hand hand, Joint handJoint) {
	if(hand.isConfidentlyDetected()) {
        ofFill();
		if(hand.isOpen()) ofSetColor(ofColor::green);
		else ofSetColor(ofColor::red);
		ofCircle(handJoint.getPoint(), 25);
	}
}

void BodyRenderer::drawBones() {
	drawTorso();
    drawRightArm();
    drawLeftArm();
    drawRightLeg();
    drawLeftLeg();
}

void BodyRenderer::drawTorso(){
    drawBone(skeleton->getHead(), skeleton->getNeck());
    drawBone(skeleton->getNeck(), skeleton->getSpineShoulder());
    drawBone(skeleton->getSpineShoulder(), skeleton->getSpineMid());
    drawBone(skeleton->getSpineMid(), skeleton->getSpineBase());
    drawBone(skeleton->getSpineShoulder(), skeleton->getShoulderRight());
    drawBone(skeleton->getSpineShoulder(), skeleton->getShoulderLeft());
    drawBone(skeleton->getSpineBase(), skeleton->getHipRight());
    drawBone(skeleton->getSpineBase(), skeleton->getHipLeft());
}

void BodyRenderer::drawRightArm(){
    drawBone(skeleton->getShoulderRight(), skeleton->getElbowRight());
    drawBone(skeleton->getElbowRight(), skeleton->getWristRight());
    drawBone(skeleton->getWristRight(), skeleton->getHandRight());
    drawBone(skeleton->getHandRight(), skeleton->getHandTipRight());
    drawBone(skeleton->getWristRight(), skeleton->getThumbRight());
}

void BodyRenderer::drawLeftArm(){
    drawBone(skeleton->getShoulderLeft(), skeleton->getElbowLeft());
    drawBone(skeleton->getElbowLeft(), skeleton->getWristLeft());
    drawBone(skeleton->getWristLeft(), skeleton->getHandLeft());
    drawBone(skeleton->getHandLeft(), skeleton->getHandTipLeft());
    drawBone(skeleton->getWristLeft(), skeleton->getThumbLeft());
}

void BodyRenderer::drawRightLeg(){
    drawBone(skeleton->getHipRight(), skeleton->getKneeRight());
    drawBone(skeleton->getKneeRight(), skeleton->getAnkleRight());
    drawBone(skeleton->getAnkleRight(), skeleton->getFootRight());
}

void BodyRenderer::drawLeftLeg(){
    drawBone(skeleton->getHipLeft(), skeleton->getKneeLeft());
    drawBone(skeleton->getKneeLeft(), skeleton->getAnkleLeft());
    drawBone(skeleton->getAnkleLeft(), skeleton->getFootLeft());
}

void BodyRenderer::drawBone(Joint joint1, Joint joint2){
    
    TrackingState trackingState = combinedTrackingState(joint1, joint2);
    
    if(trackingState == TRACKED) {
        ofSetLineWidth(10);
        ofSetColor(ofColor::white);
		ofLine(joint1.getPoint(), joint2.getPoint());
    } else if(trackingState == INFERRED) {
        ofSetLineWidth(1);
        ofSetColor(ofColor::gray);
		ofLine(joint1.getPoint(), joint2.getPoint());
    }
}

void BodyRenderer::drawJoints() {
    drawJoint(skeleton->getThumbRight());
    drawJoint(skeleton->getSpineBase());
    drawJoint(skeleton->getSpineMid());
    drawJoint(skeleton->getNeck());
    drawJoint(skeleton->getHead());
    drawJoint(skeleton->getShoulderLeft());
    drawJoint(skeleton->getElbowLeft());
    drawJoint(skeleton->getWristLeft());
    drawJoint(skeleton->getHandLeft());
    drawJoint(skeleton->getShoulderRight());
    drawJoint(skeleton->getElbowRight());
    drawJoint(skeleton->getWristRight());
    drawJoint(skeleton->getHandRight());
    drawJoint(skeleton->getHipLeft());
    drawJoint(skeleton->getKneeLeft());
    drawJoint(skeleton->getAnkleLeft());
    drawJoint(skeleton->getFootLeft());
    drawJoint(skeleton->getHipRight());
    drawJoint(skeleton->getKneeRight());
    drawJoint(skeleton->getAnkleRight());
    drawJoint(skeleton->getFootRight());
    drawJoint(skeleton->getSpineShoulder());
    drawJoint(skeleton->getHandTipLeft());
    drawJoint(skeleton->getThumbLeft());
    drawJoint(skeleton->getHandTipRight());
}

void BodyRenderer::drawJoint(Joint joint) {
	if(joint.getTrackingState() == TRACKED || joint.getTrackingState() == INFERRED) {
		ofSetColor(ofColor::lightGray);
		ofFill();
		ofCircle(joint.getPoint(), 10);
	}
}

void BodyRenderer::drawRanges() {
    ofSetColor(ofColor::purple);
    ofNoFill();
    ofSetLineWidth(1);
    drawRange(skeleton->getLeftHandRange(), skeleton->getHandLeft(), skeleton->getLeftHandNormal());
    drawRange(skeleton->getRightHandRange(), skeleton->getHandRight(), skeleton->getRightHandNormal());
}

void BodyRenderer::drawRange(ofRectangle range, Joint hand, ofVec2f normal) {
    ofRect(range);
    if(isFontEnabled) {
        normalReport = ofToString(normal.x) + ", " + ofToString(normal.y);
        font.drawString(normalReport, hand.x(), hand.y() - 50);
    }
}

TrackingState BodyRenderer::combinedTrackingState(Joint &joint1, Joint &joint2) {
	if (joint1.isTracked() && joint2.isTracked()) return TRACKED;
    if (joint1.isInferred() && joint2.isTracked()) return INFERRED;
    if (joint1.isTracked() && joint2.isInferred()) return INFERRED;
    return NOT_TRACKED;
}