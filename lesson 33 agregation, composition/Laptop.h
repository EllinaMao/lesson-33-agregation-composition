#pragma once
#include <iostream>
#include "String.h"
#include "Processor.h"
#include "RAM.h"
#include "Mouse.h"
#include "Webcam.h"
#include "Printer.h"
#include "GraphicsCard.h"

using namespace std;
class Laptop {
	Processor m_processor;
	RAM m_ram;
	GraphicsCard m_graphicsCard;
	Mouse* m_mouse;
	Webcam* m_webcam;
	Printer* m_printer;

public:
	Laptop(const Processor& processor, const RAM& ram, const GraphicsCard& graphicsCard, Mouse* mouse, Webcam* webcam, Printer* printer);
	void Print() const;

};