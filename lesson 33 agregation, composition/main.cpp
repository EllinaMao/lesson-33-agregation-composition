/*
Создать класс ноутбук. На основе других объектов таких как:
Процессор  //
ОЗУ        //...
Мышка
Веб-камера окрема//
Принтер    //...
Видеокарта //...

Пишемо окремо класи :Процессор, ОЗУ, Мышка, Веб-камера, Принтер, Видеокарта.
Створити class Nout котрий отримає
 чи агрегацію чи композицію Процессора, ОЗУ, Мышки, Веб-камери, Принтера, Видеокарти
В класі Nout конструктори та метод void Print() const;



Пример класса Мышка:

class Mouse{

MyString name;
 public:
Mouse(const char* name){this->name=name;}

////сеттери геттери якщо потрібно, додати метод void Print() const;
}


MyString замість   string   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


*/

#include <iostream>
#include "String.h" 
#include "Processor.h"
#include "RAM.h"
#include "Mouse.h"
#include "Webcam.h"
#include "Printer.h"
#include "GraphicsCard.h"
#include "Laptop.h" 
using namespace std;

int main()
{
	size_t size = 2;
	Processor processor("Intel Core i7", 8, 16, 3.5);
	RAM ram("Corsair Vengeance", 16, 3200);
	GraphicsCard graphicsCard("NVIDIA GeForce RTX 3080", "GDDR6X", 10);
    Mouse* mouse = new Mouse("Logitech G502", "Wireless", 16000);  
	Webcam* webcam = new Webcam("Logitech C920", "1080p", 30.0f);
	Printer* printer = new Printer("HP LaserJet", "Laser");
    
	Processor processor2("Intel Core i7", 8, 16, 3.5);
	RAM ram2("Corsair Vengeance", 16, 3200);
	GraphicsCard graphicsCard2("NVIDIA GeForce RTX 3080", "GDDR6X", 10);


	Laptop* laptop2 = new Laptop(processor2, ram2, graphicsCard2, mouse, webcam, printer);
	Laptop* laptop = new Laptop(processor, ram, graphicsCard, mouse, webcam, printer);

	Laptop** laptops = new Laptop * [size];
	laptops[0] = laptop;
	laptops[1] = laptop2;
	for (int i = 0; i < size; i++)
	{
		laptops[i]->Print();
	}

	for (int i = 0; i < size; i++)
	{
		delete laptops[i];
	}

	delete[] laptops;
	delete mouse;
	delete webcam;
	delete printer;
	return 0;
}

