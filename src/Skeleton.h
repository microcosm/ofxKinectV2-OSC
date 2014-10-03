#pragma once
#include "ofMain.h"
#include "Joint.h"
#include "Hand.h"

class Skeleton {
public:
	void init(string bodyId);
	void draw();
	void drawHands();
	void drawHand(Hand &hand, Joint &handJoint);
	void drawBones();
	void drawBone(Joint &joint1, Joint &joint2);
	void drawJoints();
	void drawJoint(Joint &joint);
	void drawTorso();
	void drawRightArm();
	void drawLeftArm();
	void drawRightLeg();
	void drawLeftLeg();
	TrackingState combinedTrackingState(Joint &joint1, Joint &joint2);

	//Setters and getters
	void setHand(Hand &_hand);
	void setJoint(Joint &_joint);

	void setThumbRight(Joint &joint);
	void setSpineBase(Joint &joint);
	void setSpineMid(Joint &joint);
	void setNeck(Joint &joint);
	void setHead(Joint &joint);
	void setShoulderLeft(Joint &joint);
	void setElbowLeft(Joint &joint);
	void setWristLeft(Joint &joint);
	void setHandLeft(Joint &joint);
	void setShoulderRight(Joint &joint);
	void setElbowRight(Joint &joint);
	void setWristRight(Joint &joint);
	void setHandRight(Joint &joint);
	void setHipLeft(Joint &joint);
	void setKneeLeft(Joint &joint);
	void setAnkleLeft(Joint &joint);
	void setFootLeft(Joint &joint);
	void setHipRight(Joint &joint);
	void setKneeRight(Joint &joint);
	void setAnkleRight(Joint &joint);
	void setFootRight(Joint &joint);
	void setSpineShoulder(Joint &joint);
	void setHandTipLeft(Joint &joint);
	void setThumbLeft(Joint &joint);
	void setHandTipRight(Joint &joint);
	
	string getBodyId();
	Joint getThumbRight();
	Joint getSpineBase();
	Joint getSpineMid();
	Joint getNeck();
	Joint getHead();
	Joint getShoulderLeft();
	Joint getElbowLeft();
	Joint getWristLeft();
	Joint getHandLeft();
	Joint getShoulderRight();
	Joint getElbowRight();
	Joint getWristRight();
	Joint getHandRight();
	Joint getHipLeft();
	Joint getKneeLeft();
	Joint getAnkleLeft();
	Joint getFootLeft();
	Joint getHipRight();
	Joint getKneeRight();
	Joint getAnkleRight();
	Joint getFootRight();
	Joint getSpineShoulder();
	Joint getHandTipLeft();
	Joint getThumbLeft();
	Joint getHandTipRight();

protected:
	string bodyId;
	Hand leftHand;
	Hand rightHand;
	Joint thumbRight;
	Joint spineBase;
	Joint spineMid;
	Joint neck;
	Joint head;
	Joint shoulderLeft;
	Joint elbowLeft;
	Joint wristLeft;
	Joint handLeft;
	Joint shoulderRight;
	Joint elbowRight;
	Joint wristRight;
	Joint handRight;
	Joint hipLeft;
	Joint kneeLeft;
	Joint ankleLeft;
	Joint footLeft;
	Joint hipRight;
	Joint kneeRight;
	Joint ankleRight;
	Joint footRight;
	Joint spineShoulder;
	Joint handTipLeft;
	Joint thumbLeft;
	Joint handTipRight;
};