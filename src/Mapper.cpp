#include "Mapper.h"

void Mapper::mapTo(vector<Skeleton>* skeletons) {
	this->skeletons = skeletons;
}

void Mapper::map(ofxOscMessage message) {
	tokenize(message.getAddress());
	if(isBody()) {
		Skeleton* skeleton = getSkeleton(addressTokens[1]);
		string jointType = addressTokens[3];
		ofVec3f point = getPoint(message);
		assign(skeleton, jointType, point);
	}
}

void Mapper::refresh() {
	skeletons->clear();
}

void Mapper::tokenize(string address) {
	istringstream iss(address);
	string token;
	addressTokens.clear();
	while(getline(iss, token, '/')) {
		if(token != ""){
			addressTokens.push_back(token);
		}
	}
}

bool Mapper::isBody() {
	return addressTokens[0] == "bodies";
}

Skeleton* Mapper::getSkeleton(string id) {
	for(int i = 0; i < skeletons->size(); i++) {
		if(skeletons->at(i).getBodyId() == id) {
			return &skeletons->at(i);
		}
	}
	return newSkeleton(id);
}

Skeleton* Mapper::newSkeleton(string id) {
	Skeleton skeleton;
	skeleton.init(id);
	skeletons->push_back(skeleton);
	return &skeleton;
}

ofVec3f Mapper::getPoint(ofxOscMessage message) {
	ofVec3f point;
	point.x = message.getArgAsFloat(0);
	point.y = message.getArgAsFloat(1);
	point.z = message.getArgAsFloat(2);
	return point;
}

void Mapper::assign(Skeleton* skeleton, string jointType, ofVec3f point) {
	if (jointType == "ThumbRight") {
		skeleton->setThumbRight(point);
	} else if (jointType == "SpineBase") {
		skeleton->setSpineBase(point);
	} else if (jointType == "SpineMid") {
		skeleton->setSpineMid(point);
	} else if (jointType == "Neck") {
		skeleton->setNeck(point);
	} else if (jointType == "Head") {
		skeleton->setHead(point);
	} else if (jointType == "ShoulderLeft") {
		skeleton->setShoulderLeft(point);
	} else if (jointType == "ElbowLeft") {
		skeleton->setElbowLeft(point);
	} else if (jointType == "WristLeft") {
		skeleton->setWristLeft(point);
	} else if (jointType == "HandLeft") {
		skeleton->setHandLeft(point);
	} else if (jointType == "ShoulderRight") {
		skeleton->setShoulderRight(point);
	} else if (jointType == "ElbowRight") {
		skeleton->setElbowRight(point);
	} else if (jointType == "WristRight") {
		skeleton->setWristRight(point);
	} else if (jointType == "HandRight") {
		skeleton->setHandRight(point);
	} else if (jointType == "HipLeft") {
		skeleton->setHipLeft(point);
	} else if (jointType == "KneeLeft") {
		skeleton->setKneeLeft(point);
	} else if (jointType == "AnkleLeft") {
		skeleton->setAnkleLeft(point);
	} else if (jointType == "FootLeft") {
		skeleton->setFootLeft(point);
	} else if (jointType == "HipRight") {
		skeleton->setHipRight(point);
	} else if (jointType == "KneeRight") {
		skeleton->setKneeRight(point);
	} else if (jointType == "AnkleRight") {
		skeleton->setAnkleRight(point);
	} else if (jointType == "FootRight") {
		skeleton->setFootRight(point);
	} else if (jointType == "SpineShoulder") {
		skeleton->setSpineShoulder(point);
	} else if (jointType == "HandTipLeft") {
		skeleton->setHandTipLeft(point);
	} else if (jointType == "ThumbLeft") {
		skeleton->setThumbLeft(point);
	} else if (jointType == "HandTipRight") {
		skeleton->setHandTipRight(point);
	}
}