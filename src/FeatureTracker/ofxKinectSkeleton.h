/*
 ofxKinectFeatures
 Copyright © 2014  Music Technology Group - Universitat Pompeu Fabra / Escola Superior de Música de Catalunya
 
 This file is part of ofxKinectFeatures, created and maintained by Álvaro Sarasúa <http://alvarosarasua.wordpress.com>
 
 ofxKinectFeatures is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License (LGPL v3) as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 ofxKinectFeatures is distributed in the hope that it will be useful, but WITHOUT  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License (LGPL v3).
 
 You should have received a copy of the GNU Lesser General Public License long within the ofxKinectFeatures SW package.  If not, see <http://www.gnu.org/licenses/>.
 
 If you are willing to get a (non FOSS) commercial license, please contact us at mtg@upf.edu
 */

#ifndef openNiWorm_ofxKinectSkeleton_h
#define openNiWorm_ofxKinectSkeleton_h

#include "ofMain.h"
#include "ofxMocapElement.h"
#include <numeric>

namespace filter
{
    enum
    {
        SOFT = 0,
        MED = 1,
        HARD = 2
    };
} // namespace filter

class ofxKinectSkeleton {
public:
    ofxKinectSkeleton();
    ofxKinectSkeleton(int skeletonId);
    
    int getSkeletonId();
    
    void update(map<int, ofPoint> joints);
    ofxMocapElement* getElement(int _id);
    
    void setFilterLevel(int filterLevel);
    
    void setDepth(int depth);
    int getDepth();
    
    //DESCIPTOR GETTERS
    //JOINT DESCRIPTORS
    ofPoint getPosition(int j);
    vector<ofPoint> getPositionHistory(int j);
    vector<ofPoint> getPositionHistory(int j, int frames);
    
    ofPoint getPositionFiltered(int j);
    vector<ofPoint> getPositionFilteredHistory(int j);
    vector<ofPoint> getPositionFilteredHistory(int j, int frames);
    
    ofPoint getVelocity(int j);
    vector<ofPoint> getVelocityHistory(int j);
    vector<ofPoint> getVelocityHistory(int j, int frames);
    float getVelocityMagnitude(int j);
    float getVelocityMean(int j, int frames = 30);
    
    ofPoint getAcceleration(int j);
    vector<ofPoint> getAccelerationHistory(int j);
    vector<ofPoint> getAccelerationHistory(int j, int frames);
    float getAccelerationMagnitude(int j);
    float getAccelerationMean(int j, int frames = 30);
    
    float getAccelerationTrajectory(int j);
    vector<float> getAccelerationTrajectoryHistory(int j);
    vector<float> getAccelerationTrajectoryHistory(int j, int frames);
    float getAccelerationTrajectoryMean(int j, int frames = 30);
    
    float getDistanceToTorso(int j);
    vector<float> getDistanceToTorsoHistory(int j);
    vector<float> getDistanceToTorsoHistory(int j, int frames);
    
    ofPoint getRelativePositionToTorso(int j);
    vector<ofPoint> getRelativePositionToTorsoHistory(int j);
    vector<ofPoint> getRelativePositionToTorsoHistory(int j, int frames);
    
    //OVERALL DESCRIPTORS
    float getQom();
    float getCI();
    float getSymmetry();
    float getYMaxHands();
    
    bool isNewDataAvailable();
    
private:
    int skeletonId_;
    
    template <typename T>
    vector<T> createVector (T element);
    
    float *aFilter;
    float *bFilter;
    float *aLpd1;
    float *bLpd1;
    float *aLpd2;
    float *bLpd2;
    
    //overall descriptors
    float qom_, ci_, symmetry_, yMaxHands_;
    vector<float> meanVels_;
    
    bool newValues_;
    
    vector<ofxMocapElement> elements_;
    
    int depth_;
    
    void computeJointDescriptors(int jointId, ofPoint jointPos, const float &h);
    ofPoint applyFilter (vector<ofPoint> x, vector<ofPoint> y, float *a, float *b);
    
    //Functor to look for mocap elements matching a Joint
    struct MatchId
    {
        MatchId(const int& j) : j_(j) {}
        bool operator()(ofxMocapElement& obj) const
        {
            return obj.getElementId() == j_;
        }
    private:
        const int& j_;
    };
};

#endif
