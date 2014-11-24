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

HandState Hand::getState() {
	return state;
}

HandConfidence Hand::getConfidence() {
	return confidence;
}

HandPosition Hand::getPosition() {
	return position;
}

void Hand::clone(Hand* hand) {
	setState(hand->getState());
	setConfidence(hand->getConfidence());
	setPosition(hand->getPosition());
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