#include "ofMain.h"

class Logger {
public:
	void log(string message);
	int size();
	string getLine(int i);
protected:
	vector<string> buffer;
};