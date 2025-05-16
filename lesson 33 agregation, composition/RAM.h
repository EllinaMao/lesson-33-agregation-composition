#pragma once
#include <iostream>
#include "String.h"
using namespace std;

class RAM {
    String m_name;
	size_t m_size; 
	size_t m_frequency;

public:
	RAM()
		: m_name("Unknown"), m_size(0), m_frequency(0) {
	}
	RAM(const char* name, size_t size, size_t frequency)
		: m_name(name), m_size(size), m_frequency(frequency) {
	}
	void Print() const {
		cout << "RAM: " << m_name << ", Size: " << m_size << " GB, Frequency: " << m_frequency << " MHz" << endl;
	}
	// Getters and setters if needed
	const String& getName() const { return m_name; }
	size_t getSize() const { return m_size; }
	size_t getFrequency() const { return m_frequency; }
	void setName(const String& name) { m_name = name; }
	void setSize(size_t size) { m_size = size; }
	void setFrequency(size_t frequency) { m_frequency = frequency; }

};