#pragma once
#include "String.h"
size_t String::count = 0;

void String::InputStr(char*& temp) const
{
	if (temp) {
		delete[] temp;
	}

	size_t cap = capacity > 0 ? capacity : 16;
	size_t len = 0;
	char* buffer = new char[cap];

	cout << "Enter a string: ";
	char ch;
	while (cin.get(ch) && ch != '\n') {
		if (len + 1 >= cap) { 
			size_t newCap = cap + 16;
			char* newBuffer = new char[newCap];
			memcpy(newBuffer, buffer, len);
			delete[] buffer;
			buffer = newBuffer;
			cap = newCap;
		}
		buffer[len++] = ch;
	}
	buffer[len] = '\0';

	// Allocate temp with the final capacity (or just enough for the string)
	temp = new char[len + 1];
	strcpy_s(temp, len + 1, buffer);

	delete[] buffer;
}


size_t String::InputSize() const
{
	size_t size = 0;
	cout << "Enter expected size(its can be bigger, but cant be smaller)" << endl;
	cin >> size;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return size;
}

String::String() {
	capacity = 16;
	str = new char[capacity];
	strcpy_s(str, capacity, "Unknown");
	count++;
}

String::String(size_t size) {
	capacity = 16;
	while (capacity < size + 1) { 
		capacity += 16;
	}
	str = new char[capacity];
	str[0] = '\0';
	count++;
}

String::String(const char* str_user) {
	size_t len = strlen(str_user) + 1;
	Reserve(len);
	strcpy_s(str, capacity, str_user);
	count++;
}


String::String(const String& a) {
	if (a.str) {
		capacity = a.capacity;
		str = new char[capacity];
		strcpy_s(str, capacity, a.str);
	}
	else {
		str = nullptr;
		capacity = 0;
	}
	count++;
}



String::String(String&& a) noexcept {
	str = a.str;
	capacity = a.capacity;
	a.str = nullptr;
	a.capacity = 0;
}

String& String::operator=(const String& a) {
	if (this == &a) return *this;
	if (str) delete[] str;
	capacity = a.capacity;
	str = new char[capacity];
	strcpy_s(str, capacity, a.str);
	return *this;
}

String& String::operator=(String&& a) noexcept {
	if (this == &a) return *this;
	if (str) delete[] str;
	str = a.str;
	capacity = a.capacity;
	a.str = nullptr;
	a.capacity = 0;
	return *this;
}



String::~String() {
  	if (str) {
		delete[] str;
		str = nullptr;
		count--;
	}
}

void String::Clear() {
	if (str) {
		delete[] str;
	}
	capacity = 16;
	str = new char[capacity];
	str[0] = '\0';
}


void String::Reserve(size_t newCapacity) {
	if (newCapacity <= capacity)
		return;
	size_t adjusted = ((newCapacity + 15) / 16) * 16;
	char* newStr = new char[adjusted];
	if (str) {
		strcpy_s(newStr, adjusted, str);
		delete[] str;
	}
	else {
		newStr[0] = '\0';
	}
	str = newStr;
	capacity = adjusted;
}


String& String::operator+=(const String& other) {
	size_t newLen = GetSize() + other.GetSize() + 1;
	Reserve(newLen);
	strcat_s(str, capacity, other.str);
	return *this;
}

void String::SetStr(const char* str_user) {
	size_t len = strlen(str_user) + 1;

	Reserve(len);
	strcpy_s(str, capacity, str_user);
}


void String::SetUserStr()
{
	if (str) {
		delete[] str;
	}
	char* temp = nullptr;
	InputStr(temp);
	str = temp;
	capacity = strlen(str) + 1;
	capacity = ((capacity + 15) / 16) * 16;
}



const char* String::GetStr() const
{
	return str;
}

void String::Output() const {
	if (str) {
		cout << str << endl;
	}
	else {
		cout << "Cant show empty str" << endl;
	}
}

void String::OutputCount()
{
	cout << "Count: " << count << endl;
}

