/*
 ofxKinectFeatures
 Copyright © 2014  Music Technology Group - Universitat Pompeu Fabra / Escola Superior de Música de Catalunya
 
 This file is part of ofxKinectFeatures, created and maintained by Álvaro Sarasúa <http://alvarosarasua.wordpress.com>
 
 ofxKinectFeatures is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License (LGPL v3) as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 ofxKinectFeatures is distributed in the hope that it will be useful, but WITHOUT  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License (LGPL v3).
 
 You should have received a copy of the GNU Lesser General Public License long within the ofxKinectFeatures SW package.  If not, see <http://www.gnu.org/licenses/>.
 
 If you are willing to get a (non FOSS) commercial license, please contact us at mtg@upf.edu
 */
#include "ofxMocapElement.h"

ofxMocapElement::ofxMocapElement(){
    ofPoint zeros = ofPoint(0.0,0.0,0.0);
    for (int i = 0; i < historyDepth_; i++) {
        setPosition(zeros);
        setPositionFiltered(zeros);
        setVelocity(zeros);
        setAcceleration(zeros);
        setAccelerationTrajectory(0.0);
        setRelativePositionToTorso(zeros);
    }
}

ofxMocapElement::ofxMocapElement(int elementId, int depth){
    elementId_ = elementId;
    historyDepth_ = depth;
    ofPoint zeros = ofPoint(0.0,0.0,0.0);
    for (int i = 0; i < historyDepth_; i++) {
        setPosition(zeros);
        setPositionFiltered(zeros);
        setVelocity(zeros);
        setAcceleration(zeros);
        setAccelerationTrajectory(0.0);
        setRelativePositionToTorso(zeros);
    }
}

unsigned int ofxMocapElement::getElementId(){
    return elementId_;
}

void ofxMocapElement::setElementId(int newId){
    elementId_ = newId;
}


void ofxMocapElement::setHistoryDepth(int depth){
    historyDepth_ = depth;
}

//Getters & setters

vector<ofPoint> ofxMocapElement::getPosition(){
    return position_;
}

void ofxMocapElement::setPosition(ofPoint position){
    // Add position to history
	if (position_.size() <= historyDepth_) {
        position_.insert(position_.begin(), position);
	}
    
	// remove positions from history
	if (position_.size() > historyDepth_) {
		position_.pop_back();
	}
}

vector<ofPoint> ofxMocapElement::getPositionFiltered(){
    return positionFiltered_;
}

void ofxMocapElement::setPositionFiltered(ofPoint positionFiltered){
    // Add position to history
	if (positionFiltered_.size() <= historyDepth_) {
        positionFiltered_.insert(positionFiltered_.begin(), positionFiltered);
	}
    
	// remove positions from history
	if (positionFiltered_.size() > historyDepth_) {
		positionFiltered_.pop_back();
	}
}

vector<ofPoint> ofxMocapElement::getVelocity(){
    return velocity_;
}

void ofxMocapElement::setVelocity(ofPoint velocity){
    // Add position to history
	if (velocity_.size() <= historyDepth_) {
        velocity_.insert(velocity_.begin(), velocity);
	}
    
	// remove positions from history
	if (velocity_.size() > historyDepth_) {
		velocity_.pop_back();
	}
}

vector<ofPoint> ofxMocapElement::getAcceleration(){
    return acceleration_;
}

void ofxMocapElement::setAcceleration(ofPoint acceleration){
    // Add position to history
	if (acceleration_.size() <= historyDepth_) {
        acceleration_.insert(acceleration_.begin(), acceleration);
	}
    
	// remove positions from history
	if (acceleration_.size() > historyDepth_) {
		acceleration_.pop_back();
	}
}

vector<float> ofxMocapElement::getAccelerationTrajectory(){
    return accelerationTrajectory_;
}

void ofxMocapElement::setAccelerationTrajectory(float accelerationTrajectory){
    if (accelerationTrajectory_.size() <= historyDepth_) {
        accelerationTrajectory_.insert(accelerationTrajectory_.begin(), accelerationTrajectory);
	}
    
	// remove positions from history
	if (accelerationTrajectory_.size() > historyDepth_) {
		accelerationTrajectory_.pop_back();
	}
}

vector<float> ofxMocapElement::getDistanceToTorso(){
    return distanceToTorso_;
}

void ofxMocapElement::setDistanceToTorso(float distanceToTorso){
    if (distanceToTorso_.size() <= historyDepth_) {
        distanceToTorso_.insert(distanceToTorso_.begin(), distanceToTorso);
	}
    
	// remove positions from history
	if (distanceToTorso_.size() > historyDepth_) {
		distanceToTorso_.pop_back();
	}
}

vector<ofPoint> ofxMocapElement::getRelativePositionToTorso(){
    return relativePositionToTorso_;
}

void ofxMocapElement::setRelativePositionToTorso(ofPoint relativePositionToTorso){
    if (relativePositionToTorso_.size() <= historyDepth_) {
        relativePositionToTorso_.insert(relativePositionToTorso_.begin(), relativePositionToTorso);
	}
    
	// remove positions from history
	if (relativePositionToTorso_.size() > historyDepth_) {
		relativePositionToTorso_.pop_back();
	}
}

