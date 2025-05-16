#pragma once
#include <iostream>
#include "String.h"
using namespace std;

class Webcam {
	String name;
	String resolution;
	float frameRate;
public:
	Webcam(const char* name, const char* resolution, float frameRate)
		: name(name), resolution(resolution), frameRate(frameRate) {
	}
	Webcam(const Webcam& other)
		: name(other.name), resolution(other.resolution), frameRate(other.frameRate) {
	}
	void Print() const {
		cout << "Webcam: " << name << ", Resolution: " << resolution
			<< ", Frame Rate: " << frameRate << " FPS" << endl;
	}
	// Getters and setters if needed
	const String& getName() const { return name; }
	const String& getResolution() const { return resolution; }
	float getFrameRate() const { return frameRate; }
	void setName(const String& name) { this->name = name; }
	void setResolution(const String& resolution) { this->resolution = resolution; }
	void setFrameRate(float frameRate) { this->frameRate = frameRate; }
};
