/*
 ofxKinectFeatures
 Copyright © 2014  Music Technology Group - Universitat Pompeu Fabra / Escola Superior de Música de Catalunya
 
 This file is part of ofxKinectFeatures, created and maintained by Álvaro Sarasúa <http://alvarosarasua.wordpress.com>
 
 ofxKinectFeatures is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License (LGPL v3) as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 ofxKinectFeatures is distributed in the hope that it will be useful, but WITHOUT  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License (LGPL v3).
 
 You should have received a copy of the GNU Lesser General Public License long within the ofxKinectFeatures SW package.  If not, see <http://www.gnu.org/licenses/>.
 
 If you are willing to get a (non FOSS) commercial license, please contact us at mtg@upf.edu
 */

#ifndef openNiWorm_ofxKinectFeatures_h
#define openNiWorm_ofxKinectFeatures_h

#include "ofMain.h"
#include "ofxKinectSkeleton.h"

class ofxKinectFeatures {
public:
    ofxKinectFeatures();
    void updateSkeleton(int skeletonId, map<int, ofPoint> joints);
    ofxKinectSkeleton* getSkeleton(int skeletonId);
    bool skeletonExists(int skeletonId);
    void removeSkeleton(int skeletonId);
    bool isNewDataAvailable();
    
private:
    bool newValues_;
    vector<ofxKinectSkeleton> skeletons_;
    
    int depth_;
    
    //Functor to look for skeleton matching an id
    struct MatchId
    {
        MatchId(const int& i) : i_(i) {}
        bool operator()(ofxKinectSkeleton& obj) const
        {
            return obj.getSkeletonId() == i_;
        }
    private:
        const int& i_;
    };
};

#endif
