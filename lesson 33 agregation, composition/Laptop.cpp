#include "Laptop.h"

Laptop::Laptop(const Processor& processor, const RAM& ram, const GraphicsCard& graphicsCard, Mouse* mouse, Webcam* webcam, Printer* printer)
{
	m_processor = processor;
	m_ram = ram;
	m_graphicsCard = graphicsCard;

	m_mouse = new Mouse(*mouse);
	m_webcam = new Webcam(*webcam);
	m_printer = new Printer(*printer);
}
void Laptop::Print() const
{
	cout << "Laptop Configuration:" << endl;
	m_processor.Print();
	m_ram.Print();
	m_graphicsCard.Print();
	if (m_mouse) {
		m_mouse->Print();
	}
	if (m_webcam) {
		m_webcam->Print();
	}
	if (m_printer) {
		m_printer->Print();
	}
}