#pragma once
#include <iostream>
#include "String.h"
using namespace std;
class GraphicsCard {
	String m_name;
	String m_memoryType;
	size_t m_memorySize;
public:
	GraphicsCard()
		: m_name("Unknown"), m_memoryType("Unknown"), m_memorySize(0) {
	}
	GraphicsCard(const char* name, const char* memoryType, size_t memorySize)
		: m_name(name), m_memoryType(memoryType), m_memorySize(memorySize) {
	}
	void Print() const {
		cout << "Graphics Card: " << m_name << ", Memory Type: " << m_memoryType<<", Memory Size: " << m_memorySize << " GB" << endl;
	}
	// Getters and setters if needed
	const String& getName() const { return m_name; }
	const String& getMemoryType() const { return m_memoryType; }
	size_t getMemorySize() const { return m_memorySize; }
	void setName(const String& name) { m_name = name; }
	void setMemoryType(const String& memoryType) { m_memoryType = memoryType; }
	void setMemorySize(size_t memorySize) { m_memorySize = memorySize; }
};