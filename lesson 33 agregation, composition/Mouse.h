#pragma once
#include <iostream>
#include "String.h"
using namespace std;

class Mouse {
    String name;
	String type;
	size_t dpi;

public:

Mouse(const char* name, const char* type, size_t dpi)
	: name(name), type(type), dpi(dpi) {
}
void Print() const {
	cout << "Mouse: " << name << ", Type: " << type << ", DPI: " << dpi << endl;
}
// Getters and setters if needed
const String& getName() const { return name; }
const String& getType() const { return type; }
size_t getDPI() const { return dpi; }
void setName(const String& name) { this->name = name; }
void setType(const String& type) { this->type = type; }
void setDPI(size_t dpi) { this->dpi = dpi; }

};
