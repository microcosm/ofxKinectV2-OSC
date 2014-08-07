#pragma once
#include "ofMain.h"
#include "ofxOscReceiver.h"

class Logger {
public:
	void log(ofxOscMessage message);
	int size();
	string getLine(int i);
protected:
	string parse(ofxOscMessage message);
	vector<string> buffer;
};