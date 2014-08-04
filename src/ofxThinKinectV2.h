#include "ofMain.h"
#include "ofxOscReceiver.h"

class ofxThinKinectV2 {
public:
	void setup(int port);
	void update();
	void drawDebug();
protected:
	string parse(ofxOscMessage message);
	void log(string parsedMessage);
	
	ofxOscReceiver receiver;
	vector<string> buffer;
};