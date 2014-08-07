#pragma once

#include "ofMain.h"
#include "ofxThinKinectV2.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void drawSkeleton(Skeleton* skeleton);
		void drawJoint(ofVec3f point);
		ofVec3f orient(ofVec3f point);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		ofxThinKinectV2 thinKinect;
};
