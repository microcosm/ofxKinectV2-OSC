#include "Skeleton.h"

void Skeleton::init(string bodyId) {
	this->bodyId = bodyId;
}

void Skeleton::draw() {
	this->drawJoints();
}

void Skeleton::drawJoints() {
	drawJoint(orient(getThumbRight()));
	drawJoint(orient(getSpineBase()));
	drawJoint(orient(getSpineMid()));
	drawJoint(orient(getNeck()));
	drawJoint(orient(getHead()));
	drawJoint(orient(getShoulderLeft()));
	drawJoint(orient(getElbowLeft()));
	drawJoint(orient(getWristLeft()));
	drawJoint(orient(getHandLeft()));
	drawJoint(orient(getShoulderRight()));
	drawJoint(orient(getElbowRight()));
	drawJoint(orient(getWristRight()));
	drawJoint(orient(getHandRight()));
	drawJoint(orient(getHipLeft()));
	drawJoint(orient(getKneeLeft()));
	drawJoint(orient(getAnkleLeft()));
	drawJoint(orient(getFootLeft()));
	drawJoint(orient(getHipRight()));
	drawJoint(orient(getKneeRight()));
	drawJoint(orient(getAnkleRight()));
	drawJoint(orient(getFootRight()));
	drawJoint(orient(getSpineShoulder()));
	drawJoint(orient(getHandTipLeft()));
	drawJoint(orient(getThumbLeft()));
	drawJoint(orient(getHandTipRight()));
}

ofVec3f Skeleton::orient(ofVec3f point){
	point.x = ofMap(point.x, -1, 1, 0, ofGetWidth());
	point.y = ofMap(point.y, -1, 1, ofGetHeight(), 0);
	point.z = ofMap(point.z, 0, 2, 30, 10);
	return point;
}

void Skeleton::drawJoint(ofVec3f point){
	ofCircle(point.x, point.y, point.z);
}

void Skeleton::setThumbRight(ofVec3f point) {
	this->thumbRight = point;
}

void Skeleton::setSpineBase(ofVec3f point) {
	this->spineBase = point;
}

void Skeleton::setSpineMid(ofVec3f point) {
	this->spineMid = point;
}

void Skeleton::setNeck(ofVec3f point) {
	this->neck = point;
}

void Skeleton::setHead(ofVec3f point) {
	this->head = point;
}

void Skeleton::setShoulderLeft(ofVec3f point) {
	this->shoulderLeft = point;
}

void Skeleton::setElbowLeft(ofVec3f point) {
	this->elbowLeft = point;
}

void Skeleton::setWristLeft(ofVec3f point) {
	this->wristLeft = point;
}

void Skeleton::setHandLeft(ofVec3f point) {
	this->handLeft = point;
}

void Skeleton::setShoulderRight(ofVec3f point) {
	this->shoulderRight = point;
}

void Skeleton::setElbowRight(ofVec3f point) {
	this->elbowRight = point;
}

void Skeleton::setWristRight(ofVec3f point) {
	this->wristRight = point;
}

void Skeleton::setHandRight(ofVec3f point) {
	this->handRight = point;
}

void Skeleton::setHipLeft(ofVec3f point) {
	this->hipLeft = point;
}

void Skeleton::setKneeLeft(ofVec3f point) {
	this->kneeLeft = point;
}

void Skeleton::setAnkleLeft(ofVec3f point) {
	this->ankleLeft = point;
}

void Skeleton::setFootLeft(ofVec3f point) {
	this->footLeft = point;
}

void Skeleton::setHipRight(ofVec3f point) {
	this->hipRight = point;
}

void Skeleton::setKneeRight(ofVec3f point) {
	this->kneeRight = point;
}

void Skeleton::setAnkleRight(ofVec3f point) {
	this->ankleRight = point;
}

void Skeleton::setFootRight(ofVec3f point) {
	this->footRight = point;
}

void Skeleton::setSpineShoulder(ofVec3f point) {
	this->spineShoulder = point;
}

void Skeleton::setHandTipLeft(ofVec3f point) {
	this->handTipLeft = point;
}

void Skeleton::setThumbLeft(ofVec3f point) {
	this->thumbLeft = point;
}

void Skeleton::setHandTipRight(ofVec3f point) {
	this->handTipRight = point;
}

string Skeleton::getBodyId() {
	return this->bodyId;
}

ofVec3f Skeleton::getThumbRight() {
	return this->thumbRight;
}

ofVec3f Skeleton::getSpineBase() {
	return this->spineBase;
}

ofVec3f Skeleton::getSpineMid() {
	return this->spineMid;
}

ofVec3f Skeleton::getNeck() {
	return this->neck;
}

ofVec3f Skeleton::getHead() {
	return this->head;
}

ofVec3f Skeleton::getShoulderLeft() {
	return this->shoulderLeft;
}

ofVec3f Skeleton::getElbowLeft() {
	return this->elbowLeft;
}

ofVec3f Skeleton::getWristLeft() {
	return this->wristLeft;
}

ofVec3f Skeleton::getHandLeft() {
	return this->handLeft;
}

ofVec3f Skeleton::getShoulderRight() {
	return this->shoulderRight;
}

ofVec3f Skeleton::getElbowRight() {
	return this->elbowRight;
}

ofVec3f Skeleton::getWristRight() {
	return this->wristRight;
}

ofVec3f Skeleton::getHandRight() {
	return this->handRight;
}

ofVec3f Skeleton::getHipLeft() {
	return this->hipLeft;
}

ofVec3f Skeleton::getKneeLeft() {
	return this->kneeLeft;
}

ofVec3f Skeleton::getAnkleLeft() {
	return this->ankleLeft;
}

ofVec3f Skeleton::getFootLeft() {
	return this->footLeft;
}

ofVec3f Skeleton::getHipRight() {
	return this->hipRight;
}

ofVec3f Skeleton::getKneeRight() {
	return this->kneeRight;
}

ofVec3f Skeleton::getAnkleRight() {
	return this->ankleRight;
}

ofVec3f Skeleton::getFootRight() {
	return this->footRight;
}

ofVec3f Skeleton::getSpineShoulder() {
	return this->spineShoulder;
}

ofVec3f Skeleton::getHandTipLeft() {
	return this->handTipLeft;
}

ofVec3f Skeleton::getThumbLeft() {
	return this->thumbLeft;
}

ofVec3f Skeleton::getHandTipRight() {
	return this->handTipRight;
}