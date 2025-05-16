#pragma once
#include <iostream>
#include "String.h"
using namespace std;

class Processor
{
private:

    String m_name;
	int m_cores;
	int m_threads;
	float m_frequency;

public:
	Processor()
		: m_name("Unknown"), m_cores(0), m_threads(0), m_frequency(0.0f) {
	}
	Processor(const char* name, int cores, int threads, float frequency)
		: m_name(name), m_cores(cores), m_threads(threads), m_frequency(frequency) {
	}
	void Print() const
	{
		cout << "Processor: " << m_cores << " cores, " << m_threads << " threads, "
			<< m_frequency << " GHz" << endl;
	}

// Getters and setters if needed

	const String& getName() const { return m_name; }
	int getCores() const { return m_cores; }
	int getThreads() const { return m_threads; }
	float getFrequency() const { return m_frequency; }
	void setName(const String& name) { m_name = name; }
	void setCores(int cores) { m_cores = cores; }
	void setThreads(int threads) { m_threads = threads; }
	void setFrequency(float frequency) { m_frequency = frequency; }

};
