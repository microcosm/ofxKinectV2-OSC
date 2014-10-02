#pragma once
#include "ofMain.h"

class Skeleton {
public:
	void init(string bodyId);
	void draw();
	void drawJoints();
	void drawJoint(ofVec3f point);
	ofVec3f orient(ofVec3f point);

	void setThumbRight(ofVec3f point);
	void setSpineBase(ofVec3f point);
	void setSpineMid(ofVec3f point);
	void setNeck(ofVec3f point);
	void setHead(ofVec3f point);
	void setShoulderLeft(ofVec3f point);
	void setElbowLeft(ofVec3f point);
	void setWristLeft(ofVec3f point);
	void setHandLeft(ofVec3f point);
	void setShoulderRight(ofVec3f point);
	void setElbowRight(ofVec3f point);
	void setWristRight(ofVec3f point);
	void setHandRight(ofVec3f point);
	void setHipLeft(ofVec3f point);
	void setKneeLeft(ofVec3f point);
	void setAnkleLeft(ofVec3f point);
	void setFootLeft(ofVec3f point);
	void setHipRight(ofVec3f point);
	void setKneeRight(ofVec3f point);
	void setAnkleRight(ofVec3f point);
	void setFootRight(ofVec3f point);
	void setSpineShoulder(ofVec3f point);
	void setHandTipLeft(ofVec3f point);
	void setThumbLeft(ofVec3f point);
	void setHandTipRight(ofVec3f point);
	
	string getBodyId();
	ofVec3f getThumbRight();
	ofVec3f getSpineBase();
	ofVec3f getSpineMid();
	ofVec3f getNeck();
	ofVec3f getHead();
	ofVec3f getShoulderLeft();
	ofVec3f getElbowLeft();
	ofVec3f getWristLeft();
	ofVec3f getHandLeft();
	ofVec3f getShoulderRight();
	ofVec3f getElbowRight();
	ofVec3f getWristRight();
	ofVec3f getHandRight();
	ofVec3f getHipLeft();
	ofVec3f getKneeLeft();
	ofVec3f getAnkleLeft();
	ofVec3f getFootLeft();
	ofVec3f getHipRight();
	ofVec3f getKneeRight();
	ofVec3f getAnkleRight();
	ofVec3f getFootRight();
	ofVec3f getSpineShoulder();
	ofVec3f getHandTipLeft();
	ofVec3f getThumbLeft();
	ofVec3f getHandTipRight();

protected:
	string bodyId;
	ofVec3f thumbRight;
	ofVec3f spineBase;
	ofVec3f spineMid;
	ofVec3f neck;
	ofVec3f head;
	ofVec3f shoulderLeft;
	ofVec3f elbowLeft;
	ofVec3f wristLeft;
	ofVec3f handLeft;
	ofVec3f shoulderRight;
	ofVec3f elbowRight;
	ofVec3f wristRight;
	ofVec3f handRight;
	ofVec3f hipLeft;
	ofVec3f kneeLeft;
	ofVec3f ankleLeft;
	ofVec3f footLeft;
	ofVec3f hipRight;
	ofVec3f kneeRight;
	ofVec3f ankleRight;
	ofVec3f footRight;
	ofVec3f spineShoulder;
	ofVec3f handTipLeft;
	ofVec3f thumbLeft;
	ofVec3f handTipRight;
};