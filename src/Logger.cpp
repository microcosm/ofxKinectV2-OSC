#include "Logger.h"
#define BUFFER_SIZE 40

void Logger::log(ofxOscMessage message) {
	buffer.insert(buffer.begin(), parse(message));
	if(buffer.size() > BUFFER_SIZE) {
		buffer.pop_back();
	}
}

int Logger::size() {
	return buffer.size();
}

string Logger::getLine(int i) {
	return buffer[i];
}

string Logger::parse(ofxOscMessage message) {
	string result;
	result = message.getAddress();
	result += ": [";

	for(int i = 0; i < message.getNumArgs(); i++) {
		result += " " + message.getArgTypeName(i) + ":";

		switch(message.getArgType(i)) {
			case OFXOSC_TYPE_INT32:
				result += ofToString(message.getArgAsInt32(i));
				break;
			case OFXOSC_TYPE_FLOAT:
				result += ofToString(message.getArgAsFloat(i));
				break;
			case OFXOSC_TYPE_STRING:
				result += message.getArgAsString(i);
				break;
			default:
				result += "unknown";
		}
		result += " ";
	};
	return result + "]";
}