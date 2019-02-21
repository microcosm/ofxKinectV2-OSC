/*
 ofxKinectFeatures
 Copyright © 2014  Music Technology Group - Universitat Pompeu Fabra / Escola Superior de Música de Catalunya
 
 This file is part of ofxKinectFeatures, created and maintained by Álvaro Sarasúa <http://alvarosarasua.wordpress.com>
 
 ofxKinectFeatures is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License (LGPL v3) as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 ofxKinectFeatures is distributed in the hope that it will be useful, but WITHOUT  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License (LGPL v3).
 
 You should have received a copy of the GNU Lesser General Public License long within the ofxKinectFeatures SW package.  If not, see <http://www.gnu.org/licenses/>.
 
 If you are willing to get a (non FOSS) commercial license, please contact us at mtg@upf.edu
 */

#include "ofxKinectSkeleton.h"

//Real-time filters for MoCap by Skogstad et al ( http://www.uio.no/english/research/groups/fourms/projects/sma/subprojects/mocapfilters/ )

float lpf_soft_a[] = {1,-1.2982434912,1.4634092217,-0.7106501488,0.2028836637};
float lpf_soft_b[] = {0.1851439645,0.1383283833,0.1746892243,0.1046627716,0.0464383730};
float lpf_med_a[] = {1,-1.7462227354,1.7354077932,-0.8232679111,0.1793463694};
float lpf_med_b[] = {0.1526249789,0.0333481282,0.0777551903,0.0667145281,0.0138945068};
float lpf_hard_a[] = {1,-1.9185418203,1.5929378702,-0.5939699187,0.0814687111};
float lpf_hard_b[] = {0.1400982208,-0.0343775491,0.0454003083,0.0099732061,0.0008485135};

float lpd1_soft_a[] = {1,-0.2919477037,0.5104653639,-0.01557831719,0.000283848732};
float lpd1_soft_b[] = {0.2712475020,0.1323672597,-0.0487267360,-0.1783422292,-0.1765457966};
float lpd1_med_a[] = {1,-0.9870779094,0.7774863652,-0.2206843188,0.02813441289};
float lpd1_med_b[] = {0.1973679432,-0.0056567353,-0.0321850947,-0.1099445540,-0.0495815592};
float lpd1_hard_a[] = {1,-2.057494776,1.858705877,-0.801785135,0.131076358};
float lpd1_hard_b[] = {-0.1543174259,0.1742393427,-0.0178886989,-0.0022975713,0.0002643535};

float lpd2_soft_a[] = {1,-0.8274946715,0.8110775672,-0.3530877871,0.06598917583};
float lpd2_soft_b[] = {0.1099156485,-0.1289124440,-0.0372667405,0.0216082189,0.0346553170};
float lpd2_med_a[] = {1,-1.571029458,1.459212744,-0.7173743414,0.1488005975};
float lpd2_med_b[] = {-0.0795571277,0.1390709784,-0.0479192600,-0.0031459045,-0.0084486862};
float lpd2_hard_a[] = {1,-1.628286742,1.418759018,-0.6223424612,0.1085280231};
float lpd2_hard_b[] = {-0.0738989849,0.1351624829,-0.0512998379,-0.0072918334,-0.0026718267};

//____________________________________________________ofxKinectSkeleton

ofxKinectSkeleton::ofxKinectSkeleton(){
    newValues_ = false;
    setDepth(30);
    aFilter = lpf_soft_a;
    bFilter = lpf_soft_b;
    aLpd1 = lpd1_soft_a;
    bLpd1 = lpd1_soft_b;
    aLpd2 = lpd2_soft_a;
    bLpd2 = lpd2_soft_b;
    //TODO
}

ofxKinectSkeleton::ofxKinectSkeleton(int skeletonId){
    newValues_ = false;
    setDepth(30);
    aFilter = lpf_soft_a;
    bFilter = lpf_soft_b;
    aLpd1 = lpd1_soft_a;
    bLpd1 = lpd1_soft_b;
    aLpd2 = lpd2_soft_a;
    bLpd2 = lpd2_soft_b;
    skeletonId_ = skeletonId;
}

int ofxKinectSkeleton::getSkeletonId(){
    return skeletonId_;
}

void ofxKinectSkeleton::setFilterLevel(int filterLevel){
    switch (filterLevel) {
        case filter::HARD:
            aFilter = lpf_hard_a;
            bFilter = lpf_hard_b;
            aLpd1 = lpd1_hard_a;
            bLpd1 = lpd1_hard_b;
            aLpd2 = lpd2_hard_a;
            bLpd2 = lpd2_hard_b;
            break;
        case filter::MED:
            aFilter = lpf_med_a;
            bFilter = lpf_med_b;
            aLpd1 = lpd1_med_a;
            bLpd1 = lpd1_med_b;
            aLpd2 = lpd2_med_a;
            bLpd2 = lpd2_med_b;
            break;
        case filter::SOFT:
            aFilter = lpf_soft_a;
            bFilter = lpf_soft_b;
            aLpd1 = lpd1_soft_a;
            bLpd1 = lpd1_soft_b;
            aLpd2 = lpd2_soft_a;
            bLpd2 = lpd2_soft_b;
        default:
            break;
    }
}

void ofxKinectSkeleton::setDepth(int depth){
    depth_ = depth;
}

int ofxKinectSkeleton::getDepth(){
    return depth_;
}

void ofxKinectSkeleton::update(map<int, ofPoint> joints){
    //Initialize elements
    if (elements_.empty()) {
        for (map<int, ofPoint>::iterator it = joints.begin(); it != joints.end(); it++) {
            ofxMocapElement newElement(it->first, depth_);
            elements_.push_back(newElement);
        }
    }
    
    //Compute descriptors
    //Hard-coded way to check if skeleton (bSkeleton doesn't work) and new data (isNewDataAvailable doesn't work)
//    if (user.getJoint((Joint)0).getWorldPosition() != ofPoint(0,0,0) &&
//        user.getJoint((Joint)0).getWorldPosition() != getElement((Joint)0)->getPosition()[0] ) {
    newValues_ = true;
    
    //TODO solve this!!
    //ofPoint headPos = user.getJoint(JOINT_HEAD).getWorldPosition();
    ofPoint headPos = joints[2];
    //ofPoint torsoPos = user.getJoint(JOINT_TORSO).getWorldPosition();
    ofPoint torsoPos = joints[0];
    
    float h = headPos.distance(torsoPos);
    float meanVel = 0.0; //for qom
    //for CI
    float xMax = numeric_limits<float>::min();
	float yMax = numeric_limits<float>::min();
	float zMax = numeric_limits<float>::min();
    float xMin = numeric_limits<float>::max();
	float yMin = numeric_limits<float>::max();
	float zMin = numeric_limits<float>::max();
    
    for (map<int, ofPoint>::iterator it = joints.begin(); it != joints.end(); it++) {
        int j = it->first;
        computeJointDescriptors(it->first, it->second, h);
        
        //qom
        meanVel += getVelocityMagnitude(j);
        
        //ci
        if (getPositionFiltered(j).x > xMax) {
            xMax = getPositionFiltered(j).x;
        }
        if (getPositionFiltered(j).y > yMax) {
            yMax = getPositionFiltered(j).y;
        }
        if (getPositionFiltered(j).z > zMax) {
            zMax = getPositionFiltered(j).z;
        }
        if (getPositionFiltered(j).x < xMin) {
            xMin = getPositionFiltered(j).x;
        }
        if (getPositionFiltered(j).y < yMin) {
            yMin = getPositionFiltered(j).y;
        }
        if (getPositionFiltered(j).z < zMin) {
            zMin = getPositionFiltered(j).z;
        }
    }
    
    // Add position to history
    if (meanVels_.size() <= depth_) {
        meanVels_.insert(meanVels_.begin(), meanVel/joints.size());
    }
    
    // remove positions from history
    if (meanVels_.size() > depth_) {
        meanVels_.pop_back();
    }
    
    qom_ = accumulate(meanVels_.begin(), meanVels_.end(), 0.0) / (meanVels_.size());
    

    ci_ = h == 0 ? 0 : ( -4.0 + (( abs(xMax-xMin) + abs(yMax-yMin) + abs(zMax-zMin) ) / h) ) / 6.0;
    
    //TODO solve this!!
    symmetry_ = 1.0 - (0.5 * (abs(sqrt(getDistanceToTorso(8))-sqrt(getDistanceToTorso(5))) + abs(sqrt(getDistanceToTorso(7))-sqrt(getDistanceToTorso(7)))) / h);
    //symmetry_ = 0.0;
 
    //TODO solve this!!
    yMaxHands_ = max(getRelativePositionToTorso(8).y, getRelativePositionToTorso(5).y);
    //yMaxHands_ = 0.0;
        
        
//    } else {
//        newValues_
//        = false;
//    }
}

void ofxKinectSkeleton::computeJointDescriptors(int jointId, ofPoint jointPos, const float &h){
    ofxMocapElement* mocapElement = getElement(jointId);
    
    //Position
    mocapElement->setPosition(jointPos);
    
    //Filtered position
    mocapElement->setPositionFiltered(applyFilter(mocapElement->getPosition(), mocapElement->getPositionFiltered(), aFilter, bFilter));
    
    //Velocity
    mocapElement->setVelocity(applyFilter(mocapElement->getPosition(), mocapElement->getVelocity(), aLpd1, bLpd1));
    
    //Acceleration
    mocapElement->setAcceleration(applyFilter(mocapElement->getPosition(), mocapElement->getAcceleration(), aLpd2, bLpd2));
    
    //Acceleration along trajectory
    ofPoint acc = mocapElement->getAcceleration()[0];
    ofPoint vel = mocapElement->getVelocity()[0];
    mocapElement->setAccelerationTrajectory(acc.dot(vel) / vel.length());
    
    //Distance to torso
    //TODO solve this!!
    //mocapElement->setDistanceToTorso(getPositionFiltered(j).distanceSquared(getPositionFiltered(JOINT_TORSO)));
    mocapElement->setDistanceToTorso(getPositionFiltered(jointId).distanceSquared(getPositionFiltered(0)));
    
    //Relative position to torso
    //TODO solve this!!
    ofPoint relPosToTorso;
//    relPosToTorso.x = (jointPos.x - getPositionFiltered(JOINT_TORSO).x) / (h * 1.8);
//    relPosToTorso.y = (jointPos.y - getPositionFiltered(JOINT_TORSO).y) / (h * 1.8);
//    relPosToTorso.z = -((jointPos.z - getPositionFiltered(JOINT_TORSO).z) / h) / 1.4;
    relPosToTorso.x = (jointPos.x - getPositionFiltered(0).x) / (h * 1.8);
    relPosToTorso.y = (jointPos.y - getPositionFiltered(0).y) / (h * 1.8);
    relPosToTorso.z = -((jointPos.z - getPositionFiltered(0).z) / h) / 1.4;
    mocapElement->setRelativePositionToTorso(relPosToTorso);
    
    //TODO: auto hand
    //beatTracker.update(getAccTrVector(JOINT_RIGHT_HAND), get3DFiltPosVector(JOINT_RIGHT_HAND)[coord::Y]);
}

ofxMocapElement* ofxKinectSkeleton::getElement(int _id){
    vector<ofxMocapElement>::iterator it = find_if(elements_.begin(), elements_.end(), MatchId(_id));
    if (it != elements_.end()){
        return &(*it);
    } else {
        return false;
    }
}

ofPoint ofxKinectSkeleton::applyFilter(vector<ofPoint> x, vector<ofPoint> y, float *a, float *b){
    return b[0]*x[0] + b[1]*x[1] + b[2]*x[2] + b[3]*x[3] + b[4]*x[4] - (a[1]*y[0] + a[2]*y[1] + a[3]*y[2] + a[4]*y[3]);
}


template <typename T>
vector<T> ofxKinectSkeleton::createVector(T element){
    vector<T> v (depth_);
    fill(v.begin(), v.begin()+depth_, element);
    return v;
}

//Descriptors getters

ofPoint ofxKinectSkeleton::getPosition(int j){
    if (getElement(j)) {
        return getElement(j)->getPosition()[0];
    } else {
        return ofPoint(0,0,0);
    }
}

vector<ofPoint> ofxKinectSkeleton::getPositionHistory(int j){
    if (getElement(j)) {
        return getElement(j)->getPosition();
    } else {
        return createVector(ofPoint(0.0,0.0,0.0));
    }
}

vector<ofPoint> ofxKinectSkeleton::getPositionHistory(int j, int frames){
    if (getElement(j)) {
        vector<ofPoint> fullHistory = getElement(j)->getPosition();
        vector<ofPoint> history(fullHistory.begin(), fullHistory.begin() + frames);
        return history;
    } else {
        return createVector(ofPoint(0.0,0.0,0.0));
    }
}

ofPoint ofxKinectSkeleton::getPositionFiltered(int j){
    if (getElement(j)) {
        return getElement(j)->getPositionFiltered()[0];
    } else {
        return ofPoint(0,0,0);
    }
}

vector<ofPoint> ofxKinectSkeleton::getPositionFilteredHistory(int j){
    if (getElement(j)) {
        return getElement(j)->getPositionFiltered();
    } else {
        return createVector(ofPoint(0.0,0.0,0.0));
    }
}

vector<ofPoint> ofxKinectSkeleton::getPositionFilteredHistory(int j, int frames){
    if (getElement(j)) {
        vector<ofPoint> fullHistory = getElement(j)->getPositionFiltered();
        vector<ofPoint> history(fullHistory.begin(), fullHistory.begin() + frames);
        return history;
    } else {
        return createVector(ofPoint(0.0,0.0,0.0));
    }
}

ofPoint ofxKinectSkeleton::getVelocity(int j){
    if (getElement(j)) {
        return getElement(j)->getVelocity()[0];
    } else {
        return ofPoint(0.0,0.0,0.0);
    }
}

vector<ofPoint> ofxKinectSkeleton::getVelocityHistory(int j){
    if (getElement(j)) {
        return getElement(j)->getVelocity();
    } else {
        return createVector(ofPoint(0.0,0.0,0.0));
    }
}

vector<ofPoint> ofxKinectSkeleton::getVelocityHistory(int j, int frames){
    if (getElement(j)) {
        vector<ofPoint> fullHistory = getElement(j)->getVelocity();
        vector<ofPoint> history(fullHistory.begin(), fullHistory.begin() + frames);
        return history;
    } else {
        return createVector(ofPoint(0.0,0.0,0.0));
    }
}

float ofxKinectSkeleton::getVelocityMagnitude(int j){
    if (getElement(j)) {
        return getElement(j)->getVelocity()[0].length();
    } else {
        return 0.0;
    }
}

float ofxKinectSkeleton::getVelocityMean(int j, int frames){
    if (getElement(j)) {
        float sum = 0.0;
        for (int i = 0; i < frames && i < getElement(j)->getVelocity().size(); i++) {
            sum += getElement(j)->getVelocity()[i].length();
        }
        if (frames <= getElement(j)->getVelocity().size()) {
            return sum / frames;
        } else {
            return sum / getElement(j)->getVelocity().size();
        }
    } else {
        return 0.0;
    }
}

ofPoint ofxKinectSkeleton::getAcceleration(int j){
    if (getElement(j)) {
        return getElement(j)->getAcceleration()[0];
    } else {
        return ofPoint(0.0,0.0,0.0);
    }
}

vector<ofPoint> ofxKinectSkeleton::getAccelerationHistory(int j){
    if (getElement(j)) {
        return getElement(j)->getAcceleration();
    } else {
        return createVector(ofPoint(0.0,0.0,0.0));
    }
}

vector<ofPoint> ofxKinectSkeleton::getAccelerationHistory(int j, int frames){
    if (getElement(j)) {
        vector<ofPoint> fullHistory = getElement(j)->getAcceleration();
        vector<ofPoint> history(fullHistory.begin(), fullHistory.begin() + frames);
        return history;
    } else {
        return createVector(ofPoint(0.0,0.0,0.0));
    }
}

float ofxKinectSkeleton::getAccelerationMagnitude(int j){
    if (getElement(j)) {
        return getElement(j)->getAcceleration()[0].length();
    } else {
        return 0.0;
    }
}

float ofxKinectSkeleton::getAccelerationMean(int j, int frames){
    if (getElement(j)) {
        float sum = 0.0;
        for (int i = 0; i < frames && i < getElement(j)->getAcceleration().size(); i++) {
            sum += getElement(j)->getAcceleration()[i].length();
        }
        if (frames <= getElement(j)->getAcceleration().size()) {
            return sum / frames;
        } else {
            return sum / getElement(j)->getAcceleration().size();
        }
    } else {
        return 0.0;
    }
}

float ofxKinectSkeleton::getAccelerationTrajectory(int j){
    if (getElement(j)){
        return getElement(j)->getAccelerationTrajectory()[0];
    } else {
        return 0.0;
    }
}

vector<float> ofxKinectSkeleton::getAccelerationTrajectoryHistory(int j){
    if (getElement(j)) {
        return getElement(j)->getAccelerationTrajectory();
    } else {
        return createVector(0.0f);
    }
}

vector<float> ofxKinectSkeleton::getAccelerationTrajectoryHistory(int j, int frames){
    if (getElement(j)) {
        vector<float> fullHistory = getElement(j)->getAccelerationTrajectory();
        vector<float> history(fullHistory.begin(), fullHistory.begin() + frames);
        return history;
    } else {
        return createVector(0.0f);
    }
}

float ofxKinectSkeleton::getAccelerationTrajectoryMean(int j, int frames){
    if (getElement(j)) {
        float sum = 0.0;
        for (int i = 0; i < frames && i < getElement(j)->getAccelerationTrajectory().size(); i++) {
            sum += getElement(j)->getAccelerationTrajectory()[i];
        }
        if (frames <= getElement(j)->getAccelerationTrajectory().size()) {
            return sum / frames;
        } else {
            return sum / getElement(j)->getAccelerationTrajectory().size();
        }
    } else {
        return 0.0;
    }
}

float ofxKinectSkeleton::getDistanceToTorso(int j){
    if (getElement(j)){
        return getElement(j)->getDistanceToTorso()[0];
    } else {
        return 0.0;
    }
}

vector<float> ofxKinectSkeleton::getDistanceToTorsoHistory(int j){
    if (getElement(j)) {
        return getElement(j)->getDistanceToTorso();
    } else {
        return createVector(0.0f);
    }
}

vector<float> ofxKinectSkeleton::getDistanceToTorsoHistory(int j, int frames){
    if (getElement(j)) {
        vector<float> fullHistory = getElement(j)->getDistanceToTorso();
        vector<float> history(fullHistory.begin(), fullHistory.begin() + frames);
        return history;
    } else {
        return createVector(0.0f);
    }
}

ofPoint ofxKinectSkeleton::getRelativePositionToTorso(int j){
    if (getElement(j)) {
        return getElement(j)->getRelativePositionToTorso()[0];
    } else {
        return ofPoint(0.0,0.0,0.0);
    }
}

vector<ofPoint> ofxKinectSkeleton::getRelativePositionToTorsoHistory(int j){
    if (getElement(j)) {
        return getElement(j)->getRelativePositionToTorso();
    } else {
        return createVector(ofPoint(0.0,0.0,0.0));
    }
}

vector<ofPoint> ofxKinectSkeleton::getRelativePositionToTorsoHistory(int j, int frames){
    if (getElement(j)) {
        vector<ofPoint> fullHistory = getElement(j)->getRelativePositionToTorso();
        vector<ofPoint> history(fullHistory.begin(), fullHistory.begin() + frames);
        return history;
    } else {
        return createVector(ofPoint(0.0,0.0,0.0));
    }
}

float ofxKinectSkeleton::getQom(){
    return qom_;
}

float ofxKinectSkeleton::getCI(){
    return ci_;
}

float ofxKinectSkeleton::getSymmetry(){
    return symmetry_;
}

float ofxKinectSkeleton::getYMaxHands(){
    return yMaxHands_;
}

bool ofxKinectSkeleton::isNewDataAvailable(){
    return newValues_;
}