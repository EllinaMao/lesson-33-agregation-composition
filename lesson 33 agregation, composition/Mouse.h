#pragma once
#include <iostream>
#include "String.h"
using namespace std;

class Mouse {
    String m_name;
	String m_type;
	size_t m_dpi;

public:

Mouse(const char* name, const char* type, size_t dpi)
	: m_name(name), m_type(type), m_dpi(dpi) {
}

Mouse(const Mouse& other)
	: m_name(other.m_name), m_type(other.m_type), m_dpi(other.m_dpi) {
}
void Print() const {
	cout << "Mouse: " << m_name << ", Type: " << m_type << ", DPI: " << m_dpi << endl;
}
// Getters and setters if needed
const String& getName() const { return m_name; }
const String& getType() const { return m_type; }
size_t getDPI() const { return m_dpi; }
void setName(const String& name) { m_name = name; }
void setType(const String& type) { m_type = type; }
void setDPI(size_t dpi) { m_dpi = dpi; }

};
