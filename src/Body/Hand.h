#pragma once
#include "ofMain.h"

enum HandState {
	UNKNOWN, OPEN, CLOSED
};

enum HandConfidence {
	LOW, HIGH
};

enum HandPosition {
	LEFT, RIGHT
};

class Hand {
public:
	void setState(HandState _state);
	void setConfidence(HandConfidence _confidence);
	void setPosition(HandPosition _position);
	HandState getState();
	HandConfidence getConfidence();
	HandPosition getPosition();
	void clone(Hand* hand);

	bool isClosed();
	bool isOpen();
	bool isHighConfidence();
	bool isConfidentlyDetected();
	bool isLeft();
	bool isRight();

protected:
	HandState state;
	HandConfidence confidence;
	HandPosition position;
};