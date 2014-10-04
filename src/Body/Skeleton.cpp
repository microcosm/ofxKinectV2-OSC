#include "Skeleton.h"

void Skeleton::init(string bodyId) {
	this->bodyId = bodyId;
}

void Skeleton::setHand(Hand &hand) {
	if(hand.isLeft()) {
		leftHand = hand;
	} else {
		rightHand = hand;
	}
}

void Skeleton::setJoint(Joint &joint) {
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
	this->thumbRight = joint;
}

void Skeleton::setSpineBase(Joint &joint) {
	this->spineBase = joint;
}

void Skeleton::setSpineMid(Joint &joint) {
	this->spineMid = joint;
}

void Skeleton::setNeck(Joint &joint) {
	this->neck = joint;
}

void Skeleton::setHead(Joint &joint) {
	this->head = joint;
}

void Skeleton::setShoulderLeft(Joint &joint) {
	this->shoulderLeft = joint;
}

void Skeleton::setElbowLeft(Joint &joint) {
	this->elbowLeft = joint;
}

void Skeleton::setWristLeft(Joint &joint) {
	this->wristLeft = joint;
}

void Skeleton::setHandLeft(Joint &joint) {
	this->handLeft = joint;
}

void Skeleton::setShoulderRight(Joint &joint) {
	this->shoulderRight = joint;
}

void Skeleton::setElbowRight(Joint &joint) {
	this->elbowRight = joint;
}

void Skeleton::setWristRight(Joint &joint) {
	this->wristRight = joint;
}

void Skeleton::setHandRight(Joint &joint) {
	this->handRight = joint;
}

void Skeleton::setHipLeft(Joint &joint) {
	this->hipLeft = joint;
}

void Skeleton::setKneeLeft(Joint &joint) {
	this->kneeLeft = joint;
}

void Skeleton::setAnkleLeft(Joint &joint) {
	this->ankleLeft = joint;
}

void Skeleton::setFootLeft(Joint &joint) {
	this->footLeft = joint;
}

void Skeleton::setHipRight(Joint &joint) {
	this->hipRight = joint;
}

void Skeleton::setKneeRight(Joint &joint) {
	this->kneeRight = joint;
}

void Skeleton::setAnkleRight(Joint &joint) {
	this->ankleRight = joint;
}

void Skeleton::setFootRight(Joint &joint) {
	this->footRight = joint;
}

void Skeleton::setSpineShoulder(Joint &joint) {
	this->spineShoulder = joint;
}

void Skeleton::setHandTipLeft(Joint &joint) {
	this->handTipLeft = joint;
}

void Skeleton::setThumbLeft(Joint &joint) {
	this->thumbLeft = joint;
}

void Skeleton::setHandTipRight(Joint &joint) {
	this->handTipRight = joint;
}

Hand Skeleton::getLeftHand() {
	return this->leftHand;
}

Hand Skeleton::getRightHand() {
	return this->rightHand;
}

string Skeleton::getBodyId() {
	return this->bodyId;
}

Joint Skeleton::getThumbRight() {
	return this->thumbRight;
}

Joint Skeleton::getSpineBase() {
	return this->spineBase;
}

Joint Skeleton::getSpineMid() {
	return this->spineMid;
}

Joint Skeleton::getNeck() {
	return this->neck;
}

Joint Skeleton::getHead() {
	return this->head;
}

Joint Skeleton::getShoulderLeft() {
	return this->shoulderLeft;
}

Joint Skeleton::getElbowLeft() {
	return this->elbowLeft;
}

Joint Skeleton::getWristLeft() {
	return this->wristLeft;
}

Joint Skeleton::getHandLeft() {
	return this->handLeft;
}

Joint Skeleton::getShoulderRight() {
	return this->shoulderRight;
}

Joint Skeleton::getElbowRight() {
	return this->elbowRight;
}

Joint Skeleton::getWristRight() {
	return this->wristRight;
}

Joint Skeleton::getHandRight() {
	return this->handRight;
}

Joint Skeleton::getHipLeft() {
	return this->hipLeft;
}

Joint Skeleton::getKneeLeft() {
	return this->kneeLeft;
}

Joint Skeleton::getAnkleLeft() {
	return this->ankleLeft;
}

Joint Skeleton::getFootLeft() {
	return this->footLeft;
}

Joint Skeleton::getHipRight() {
	return this->hipRight;
}

Joint Skeleton::getKneeRight() {
	return this->kneeRight;
}

Joint Skeleton::getAnkleRight() {
	return this->ankleRight;
}

Joint Skeleton::getFootRight() {
	return this->footRight;
}

Joint Skeleton::getSpineShoulder() {
	return this->spineShoulder;
}

Joint Skeleton::getHandTipLeft() {
	return this->handTipLeft;
}

Joint Skeleton::getThumbLeft() {
	return this->thumbLeft;
}

Joint Skeleton::getHandTipRight() {
	return this->handTipRight;
}