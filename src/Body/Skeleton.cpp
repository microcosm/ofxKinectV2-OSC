#include "Skeleton.h"

void Skeleton::init(string _bodyId) {
	bodyId = _bodyId;
    resetFreshness();
}

void Skeleton::update() {
    freshness--;
}

void Skeleton::resetFreshness() {
    freshness = MAX_FRESHNESS;
}

bool Skeleton::isStale() {
    return freshness == 0;
}

void Skeleton::setHand(Hand hand) {
	if(hand.isLeft()) {
		setLeftHand(hand);
	} else {
		setRightHand(hand);
	}
}

void Skeleton::setLeftHand(Hand &hand) {
	leftHand = hand;
    resetFreshness();
}

void Skeleton::setRightHand(Hand &hand) {
	rightHand = hand;
    resetFreshness();
}

void Skeleton::setJoint(Joint joint) {
	string jointType = joint.getType();

	if (jointType == "ThumbRight") {
		setThumbRight(joint);
	} else if (jointType == "SpineBase") {
		setSpineBase(joint);
	} else if (jointType == "SpineMid") {
		setSpineMid(joint);
	} else if (jointType == "Neck") {
		setNeck(joint);
	} else if (jointType == "Head") {
		setHead(joint);
	} else if (jointType == "ShoulderLeft") {
		setShoulderLeft(joint);
	} else if (jointType == "ElbowLeft") {
		setElbowLeft(joint);
	} else if (jointType == "WristLeft") {
		setWristLeft(joint);
	} else if (jointType == "HandLeft") {
		setHandLeft(joint);
	} else if (jointType == "ShoulderRight") {
		setShoulderRight(joint);
	} else if (jointType == "ElbowRight") {
		setElbowRight(joint);
	} else if (jointType == "WristRight") {
		setWristRight(joint);
	} else if (jointType == "HandRight") {
		setHandRight(joint);
	} else if (jointType == "HipLeft") {
		setHipLeft(joint);
	} else if (jointType == "KneeLeft") {
		setKneeLeft(joint);
	} else if (jointType == "AnkleLeft") {
		setAnkleLeft(joint);
	} else if (jointType == "FootLeft") {
		setFootLeft(joint);
	} else if (jointType == "HipRight") {
		setHipRight(joint);
	} else if (jointType == "KneeRight") {
		setKneeRight(joint);
	} else if (jointType == "AnkleRight") {
		setAnkleRight(joint);
	} else if (jointType == "FootRight") {
		setFootRight(joint);
	} else if (jointType == "SpineShoulder") {
		setSpineShoulder(joint);
	} else if (jointType == "HandTipLeft") {
		setHandTipLeft(joint);
	} else if (jointType == "ThumbLeft") {
		setThumbLeft(joint);
	} else if (jointType == "HandTipRight") {
		setHandTipRight(joint);
	}
}

void Skeleton::setThumbRight(Joint &joint) {
	thumbRight = joint;
    resetFreshness();
}

void Skeleton::setSpineBase(Joint &joint) {
	spineBase = joint;
    resetFreshness();
}

void Skeleton::setSpineMid(Joint &joint) {
	spineMid = joint;
    resetFreshness();
}

void Skeleton::setNeck(Joint &joint) {
	neck = joint;
    resetFreshness();
}

void Skeleton::setHead(Joint &joint) {
	head = joint;
    resetFreshness();
}

void Skeleton::setShoulderLeft(Joint &joint) {
	shoulderLeft = joint;
    resetFreshness();
}

void Skeleton::setElbowLeft(Joint &joint) {
	elbowLeft = joint;
    resetFreshness();
}

void Skeleton::setWristLeft(Joint &joint) {
	wristLeft = joint;
    resetFreshness();
}

void Skeleton::setHandLeft(Joint &joint) {
	handLeft = joint;
    resetFreshness();
}

void Skeleton::setShoulderRight(Joint &joint) {
	shoulderRight = joint;
    resetFreshness();
}

void Skeleton::setElbowRight(Joint &joint) {
	elbowRight = joint;
    resetFreshness();
}

void Skeleton::setWristRight(Joint &joint) {
	wristRight = joint;
    resetFreshness();
}

void Skeleton::setHandRight(Joint &joint) {
	handRight = joint;
    resetFreshness();
}

void Skeleton::setHipLeft(Joint &joint) {
	hipLeft = joint;
    resetFreshness();
}

void Skeleton::setKneeLeft(Joint &joint) {
	kneeLeft = joint;
    resetFreshness();
}

void Skeleton::setAnkleLeft(Joint &joint) {
	ankleLeft = joint;
    resetFreshness();
}

void Skeleton::setFootLeft(Joint &joint) {
	footLeft = joint;
    resetFreshness();
}

void Skeleton::setHipRight(Joint &joint) {
	hipRight = joint;
    resetFreshness();
}

void Skeleton::setKneeRight(Joint &joint) {
	kneeRight = joint;
    resetFreshness();
}

void Skeleton::setAnkleRight(Joint &joint) {
	ankleRight = joint;
    resetFreshness();
}

void Skeleton::setFootRight(Joint &joint) {
	footRight = joint;
    resetFreshness();
}

void Skeleton::setSpineShoulder(Joint &joint) {
	spineShoulder = joint;
    resetFreshness();
}

void Skeleton::setHandTipLeft(Joint &joint) {
	handTipLeft = joint;
    resetFreshness();
}

void Skeleton::setThumbLeft(Joint &joint) {
	thumbLeft = joint;
    resetFreshness();
}

void Skeleton::setHandTipRight(Joint &joint) {
	handTipRight = joint;
    resetFreshness();
}

Hand Skeleton::getLeftHand() {
	return leftHand;
}

Hand Skeleton::getRightHand() {
	return rightHand;
}

string Skeleton::getBodyId() {
	return bodyId;
}

Joint Skeleton::getThumbRight() {
	return thumbRight;
}

Joint Skeleton::getSpineBase() {
	return spineBase;
}

Joint Skeleton::getSpineMid() {
	return spineMid;
}

Joint Skeleton::getNeck() {
	return neck;
}

Joint Skeleton::getHead() {
	return head;
}

Joint Skeleton::getShoulderLeft() {
	return shoulderLeft;
}

Joint Skeleton::getElbowLeft() {
	return elbowLeft;
}

Joint Skeleton::getWristLeft() {
	return wristLeft;
}

Joint Skeleton::getHandLeft() {
	return handLeft;
}

Joint Skeleton::getShoulderRight() {
	return shoulderRight;
}

Joint Skeleton::getElbowRight() {
	return elbowRight;
}

Joint Skeleton::getWristRight() {
	return wristRight;
}

Joint Skeleton::getHandRight() {
	return handRight;
}

Joint Skeleton::getHipLeft() {
	return hipLeft;
}

Joint Skeleton::getKneeLeft() {
	return kneeLeft;
}

Joint Skeleton::getAnkleLeft() {
	return ankleLeft;
}

Joint Skeleton::getFootLeft() {
	return footLeft;
}

Joint Skeleton::getHipRight() {
	return hipRight;
}

Joint Skeleton::getKneeRight() {
	return kneeRight;
}

Joint Skeleton::getAnkleRight() {
	return ankleRight;
}

Joint Skeleton::getFootRight() {
	return footRight;
}

Joint Skeleton::getSpineShoulder() {
	return spineShoulder;
}

Joint Skeleton::getHandTipLeft() {
	return handTipLeft;
}

Joint Skeleton::getThumbLeft() {
	return thumbLeft;
}

Joint Skeleton::getHandTipRight() {
    return handTipRight;
}

ofRectangle Skeleton::getLeftHandRange() {
    return interpreter.leftHandRange(&shoulderLeft, &spineShoulder);
}

ofRectangle Skeleton::getRightHandRange() {
    return interpreter.rightHandRange(&spineShoulder, &shoulderRight);
}