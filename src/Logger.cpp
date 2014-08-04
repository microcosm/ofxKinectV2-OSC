#include "Logger.h"
#define BUFFER_SIZE 40

void Logger::log(string message) {
	buffer.insert(buffer.begin(), message);
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