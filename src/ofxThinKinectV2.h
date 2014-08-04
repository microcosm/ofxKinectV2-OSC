#include "ofMain.h"
#include "ofxOscReceiver.h"
#include "Logger.h"

class ofxThinKinectV2 {
public:
	void setup(int port);
	void update();
	void drawDebug();
protected:
	string parse(ofxOscMessage message);
	
	ofxOscReceiver receiver;
	ofxOscMessage lastMessage;
	string lastParsedMessage;
	Logger logger;
};