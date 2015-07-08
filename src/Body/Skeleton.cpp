#include "Skeleton.h"

void Skeleton::init(string _bodyId) {
	bodyId = _bodyId;
    resetFreshness();
}

void Skeleton::setSmoothing(SmoothingTechnique technique) {
	smoothing = technique;
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

bool Skeleton::isCloserThan(Skeleton* other) {
    return spineShoulder.z() > other->getSpineShoulder().z();
}

void Skeleton::setHand(Hand hand) {
	if(hand.isLeft()) {
		setLeftHand(hand);
	} else {
		setRightHand(hand);
	}
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
    return interpreter.leftHandRange(&spineShoulder, &shoulderLeft);
}

ofRectangle Skeleton::getRightHandRange() {
    return interpreter.rightHandRange(&spineShoulder, &shoulderRight);
}

ofVec3f Skeleton::getLeftHandNormal() {
    return interpreter.leftHandNormal(&handLeft, &spineShoulder, &shoulderLeft);
}

ofVec3f Skeleton::getRightHandNormal() {
    return interpreter.rightHandNormal(&handRight, &spineShoulder, &shoulderRight);
}

void Skeleton::setLeftHand(Hand &hand) {
    leftHand.clone(&hand);
    resetFreshness();
}

void Skeleton::setRightHand(Hand &hand) {
    rightHand.clone(&hand);
    resetFreshness();
}

void Skeleton::setThumbRight(Joint &joint) {
    thumbRight.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setSpineBase(Joint &joint) {
    spineBase.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setSpineMid(Joint &joint) {
    spineMid.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setNeck(Joint &joint) {
    neck.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setHead(Joint &joint) {
    head.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setShoulderLeft(Joint &joint) {
    shoulderLeft.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setElbowLeft(Joint &joint) {
    elbowLeft.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setWristLeft(Joint &joint) {
    wristLeft.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setHandLeft(Joint &joint) {
    handLeft.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setShoulderRight(Joint &joint) {
    shoulderRight.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setElbowRight(Joint &joint) {
    elbowRight.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setWristRight(Joint &joint) {
    wristRight.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setHandRight(Joint &joint) {
    handRight.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setHipLeft(Joint &joint) {
    hipLeft.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setKneeLeft(Joint &joint) {
    kneeLeft.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setAnkleLeft(Joint &joint) {
    ankleLeft.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setFootLeft(Joint &joint) {
    footLeft.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setHipRight(Joint &joint) {
    hipRight.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setKneeRight(Joint &joint) {
    kneeRight.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setAnkleRight(Joint &joint) {
    ankleRight.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setFootRight(Joint &joint) {
    footRight.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setSpineShoulder(Joint &joint) {
    spineShoulder.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setHandTipLeft(Joint &joint) {
    handTipLeft.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setThumbLeft(Joint &joint) {
    thumbLeft.clone(&joint, smoothing);
    resetFreshness();
}

void Skeleton::setHandTipRight(Joint &joint) {
    handTipRight.clone(&joint, smoothing);
    resetFreshness();
}