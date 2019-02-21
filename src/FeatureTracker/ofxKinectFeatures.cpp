/*
 ofxKinectFeatures
 Copyright © 2014  Music Technology Group - Universitat Pompeu Fabra / Escola Superior de Música de Catalunya
 
 This file is part of ofxKinectFeatures, created and maintained by Álvaro Sarasúa <http://alvarosarasua.wordpress.com>
 
 ofxKinectFeatures is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License (LGPL v3) as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
 ofxKinectFeatures is distributed in the hope that it will be useful, but WITHOUT  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License (LGPL v3).
 
 You should have received a copy of the GNU Lesser General Public License long within the ofxKinectFeatures SW package.  If not, see <http://www.gnu.org/licenses/>.
 
 If you are willing to get a (non FOSS) commercial license, please contact us at mtg@upf.edu
 */

#include "ofxKinectFeatures.h"

//Real-time filters for MoCap by Skogstad et al ( http://www.uio.no/english/research/groups/fourms/projects/sma/subprojects/mocapfilters/ )

//____________________________________________________ofxKinectFeatures

ofxKinectFeatures::ofxKinectFeatures(){
    newValues_ = false;
}

void ofxKinectFeatures::updateSkeleton(int skeletonId, map<int, ofPoint> joints){
    if (!getSkeleton(skeletonId)) {
        ofxKinectSkeleton newSkeleton(skeletonId);
        skeletons_.push_back(newSkeleton);
    }
    getSkeleton(skeletonId)->update(joints);
}

ofxKinectSkeleton* ofxKinectFeatures::getSkeleton(int skeletonId){
    vector<ofxKinectSkeleton>::iterator it = find_if(skeletons_.begin(), skeletons_.end(), MatchId(skeletonId));
    if (it != skeletons_.end()){
        return &(*it);
    } else {
        return false;
    }
}

bool ofxKinectFeatures::skeletonExists(int skeletonId){
    if (getSkeleton(skeletonId)) {
        return true;
    } else {
        return false;
    }
}

void ofxKinectFeatures::removeSkeleton(int skeletonId){
    vector<ofxKinectSkeleton>::iterator it = find_if(skeletons_.begin(), skeletons_.end(), MatchId(skeletonId));
    skeletons_.erase(it);
}

bool ofxKinectFeatures::isNewDataAvailable(){
    return newValues_;
}