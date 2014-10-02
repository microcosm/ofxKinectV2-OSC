#include "Skeleton.h"

void Skeleton::init(string bodyId) {
	this->bodyId = bodyId;
}

void Skeleton::draw() {
	this->drawBones();
	this->drawJoints();
}

void Skeleton::drawBones() {
	this->drawTorso();
    this->drawRightArm();
    this->drawLeftArm();
    this->drawRightLeg();
    this->drawLeftLeg();
}

void Skeleton::drawTorso(){
	drawBone(getHead(), getNeck());
	drawBone(getNeck(), getSpineShoulder());
	drawBone(getSpineShoulder(), getSpineMid());
	drawBone(getSpineMid(), getSpineBase());
	drawBone(getSpineShoulder(), getShoulderRight());
	drawBone(getSpineShoulder(), getShoulderLeft());
	drawBone(getSpineBase(), getHipRight());
	drawBone(getSpineBase(), getHipLeft());
}

void Skeleton::drawRightArm(){
    drawBone(getShoulderRight(), getElbowRight());
    drawBone(getElbowRight(), getWristRight());
    drawBone(getWristRight(), getHandRight());
    drawBone(getHandRight(), getHandTipRight());
    drawBone(getWristRight(), getThumbRight());
}

void Skeleton::drawLeftArm(){
    drawBone(getShoulderLeft(), getElbowLeft());
    drawBone(getElbowLeft(), getWristLeft());
    drawBone(getWristLeft(), getHandLeft());
    drawBone(getHandLeft(), getHandTipLeft());
    drawBone(getWristLeft(), getThumbLeft());
}

void Skeleton::drawRightLeg(){
    drawBone(getHipRight(), getKneeRight());
    drawBone(getKneeRight(), getAnkleRight());
    drawBone(getAnkleRight(), getFootRight());
}

void Skeleton::drawLeftLeg(){
    drawBone(getHipLeft(), getKneeLeft());
    drawBone(getKneeLeft(), getAnkleLeft());
    drawBone(getAnkleLeft(), getFootLeft());
}

void Skeleton::drawBone(ofVec3f point1, ofVec3f point2){
	ofLine(point1, point2);
}

void Skeleton::drawJoints() {
	drawJoint(getThumbRight());
	drawJoint(getSpineBase());
	drawJoint(getSpineMid());
	drawJoint(getNeck());
	drawJoint(getHead());
	drawJoint(getShoulderLeft());
	drawJoint(getElbowLeft());
	drawJoint(getWristLeft());
	drawJoint(getHandLeft());
	drawJoint(getShoulderRight());
	drawJoint(getElbowRight());
	drawJoint(getWristRight());
	drawJoint(getHandRight());
	drawJoint(getHipLeft());
	drawJoint(getKneeLeft());
	drawJoint(getAnkleLeft());
	drawJoint(getFootLeft());
	drawJoint(getHipRight());
	drawJoint(getKneeRight());
	drawJoint(getAnkleRight());
	drawJoint(getFootRight());
	drawJoint(getSpineShoulder());
	drawJoint(getHandTipLeft());
	drawJoint(getThumbLeft());
	drawJoint(getHandTipRight());
}

void Skeleton::drawJoint(ofVec3f point){
	ofCircle(point, 10);
}

ofVec3f Skeleton::orient(ofVec3f point){
	point.x = ofMap(point.x, -1, 1, 0, ofGetWidth());
	point.y = ofMap(point.y, -1, 1, ofGetHeight(), 0);
	point.z = ofMap(point.z, 0, 2, 30, 10);
	return point;
}

//Setters and getters
void Skeleton::setThumbRight(ofVec3f point) {
	this->thumbRight = orient(point);
}

void Skeleton::setSpineBase(ofVec3f point) {
	this->spineBase = orient(point);
}

void Skeleton::setSpineMid(ofVec3f point) {
	this->spineMid = orient(point);
}

void Skeleton::setNeck(ofVec3f point) {
	this->neck = orient(point);
}

void Skeleton::setHead(ofVec3f point) {
	this->head = orient(point);
}

void Skeleton::setShoulderLeft(ofVec3f point) {
	this->shoulderLeft = orient(point);
}

void Skeleton::setElbowLeft(ofVec3f point) {
	this->elbowLeft = orient(point);
}

void Skeleton::setWristLeft(ofVec3f point) {
	this->wristLeft = orient(point);
}

void Skeleton::setHandLeft(ofVec3f point) {
	this->handLeft = orient(point);
}

void Skeleton::setShoulderRight(ofVec3f point) {
	this->shoulderRight = orient(point);
}

void Skeleton::setElbowRight(ofVec3f point) {
	this->elbowRight = orient(point);
}

void Skeleton::setWristRight(ofVec3f point) {
	this->wristRight = orient(point);
}

void Skeleton::setHandRight(ofVec3f point) {
	this->handRight = orient(point);
}

void Skeleton::setHipLeft(ofVec3f point) {
	this->hipLeft = orient(point);
}

void Skeleton::setKneeLeft(ofVec3f point) {
	this->kneeLeft = orient(point);
}

void Skeleton::setAnkleLeft(ofVec3f point) {
	this->ankleLeft = orient(point);
}

void Skeleton::setFootLeft(ofVec3f point) {
	this->footLeft = orient(point);
}

void Skeleton::setHipRight(ofVec3f point) {
	this->hipRight = orient(point);
}

void Skeleton::setKneeRight(ofVec3f point) {
	this->kneeRight = orient(point);
}

void Skeleton::setAnkleRight(ofVec3f point) {
	this->ankleRight = orient(point);
}

void Skeleton::setFootRight(ofVec3f point) {
	this->footRight = orient(point);
}

void Skeleton::setSpineShoulder(ofVec3f point) {
	this->spineShoulder = orient(point);
}

void Skeleton::setHandTipLeft(ofVec3f point) {
	this->handTipLeft = orient(point);
}

void Skeleton::setThumbLeft(ofVec3f point) {
	this->thumbLeft = orient(point);
}

void Skeleton::setHandTipRight(ofVec3f point) {
	this->handTipRight = orient(point);
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