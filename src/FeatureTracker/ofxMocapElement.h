/*
 ofxKinectFeatures
 Copyright © 2014 Music Technology Group - Universitat Pompeu Fabra / Escola Superior de Música de Catalunya
 
 This file is part of ofxKinectFeatures, created and maintained by Álvaro Sarasúa <http://alvarosarasua.wordpress.com>
 
 ofxKinectFeatures is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License (LGPL v3) as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 ofxKinectFeatures is distributed in the hope that it will be useful, but WITHOUT  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License (LGPL v3).
 
 You should have received a copy of the GNU Lesser General Public License long within the ofxKinectFeatures SW package.  If not, see <http://www.gnu.org/licenses/>.
 
 If you are willing to get a (non FOSS) commercial license, please contact us at mtg@upf.edu
 */

#ifndef openNiFeatures_ofxMocapElement_h
#define openNiFeatures_ofxMocapElement_h

#include "ofMain.h"

class ofxMocapElement{
public:
    ofxMocapElement();
    ofxMocapElement(int elementId, int depth);
    
    unsigned int getElementId();
    void setElementId(int newId);
    
    void setHistoryDepth(int depth);    
    
    vector<ofPoint> getPosition();
    void setPosition(ofPoint position);
    
    vector<ofPoint> getPositionFiltered();
    void setPositionFiltered(ofPoint positionFiltered);
    
    vector<ofPoint> getVelocity();
    void setVelocity(ofPoint velocity);
    
    vector<ofPoint> getAcceleration();
    void setAcceleration(ofPoint acceleration);
    
    vector<float> getAccelerationTrajectory();
    void setAccelerationTrajectory(float accelerationTrajectory);
    
    vector<float> getDistanceToTorso();
    void setDistanceToTorso(float distanceToTorso);
    
    vector<ofPoint> getRelativePositionToTorso();
    void setRelativePositionToTorso(ofPoint relativePositionToTorso);

private:
    int historyDepth_;
    int elementId_;
    
    vector<ofPoint> position_;
    vector<ofPoint> positionFiltered_;
    vector<ofPoint> velocity_;
    vector<ofPoint> acceleration_;
    vector<float> accelerationTrajectory_;
    vector<float> distanceToTorso_;
    vector<ofPoint> relativePositionToTorso_;
};

#endif
