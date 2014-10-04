#include "Hand.h"

void Hand::setState(HandState _state) {
	state = _state;
}

void Hand::setConfidence(HandConfidence _confidence) {
	confidence = _confidence;
}

void Hand::setPosition(HandPosition _position) {
	position = _position;
}

bool Hand::isOpen() {
	return state == OPEN;
}

bool Hand::isClosed() {
	return state == CLOSED;
}

bool Hand::isHighConfidence() {
	return confidence == HIGH;
}

bool Hand::isConfidentlyDetected() {
	return isHighConfidence() && (isOpen() || isClosed());
}

bool Hand::isLeft() {
	return position == LEFT;
}

bool Hand::isRight() {
	return position == RIGHT;
}