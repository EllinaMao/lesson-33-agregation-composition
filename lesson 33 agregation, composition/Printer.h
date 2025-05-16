#pragma once
#include <iostream>
#include "String.h"
using namespace std;
class Printer {
	String m_name;
	String m_type;
public:
	Printer(const char* name, const char* type)
		: m_name(name), m_type(type) {
	}
	Printer(const Printer& other)
		: m_name(other.m_name), m_type(other.m_type) {
	}
	void Print() const {
		cout << "Printer: " << m_name << ", Type: " << m_type << endl;
	}
	// Getters and setters if needed
	const String& getName() const { return m_name; }
	const String& getType() const { return m_type; }
	void setName(const String& name) { m_name = name; }
	void setType(const String& type) { m_type = type; }
};