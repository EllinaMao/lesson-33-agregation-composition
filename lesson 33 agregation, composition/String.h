#pragma once
#ifndef STRING
#define STRING
#include <iostream>
using namespace std;
/*
конструктор без параметров;+
конструктор, принимающий в качестве параметра C-строку (заканчивается нулевым байтом);+
конструктор копирования;+
оператор присваивания;+
получение длины строки;+
деструктор;+
очистка строки (сделать строку пустой);+
конкатенация строк (перегрузить операторы + и +=);+
проверка на равенство (= =) и на неравенство (!=).+
*/
class String
{
protected:
	char* str = nullptr;
	size_t capacity;
	static size_t count;
	void InputStr(char*& temp) const;
	size_t InputSize() const;
public:
	String();
	explicit String(size_t size);
	explicit String(const char* str_user);
	String(const String& a);
	String(String&& a) noexcept;

	String& operator =(const String& a);
	String& operator =(String&& a) noexcept;
	String& operator+=(const String& other);

	~String();

	void Clear();
	void SetStr(const char* str_user);
	void SetUserStr();
	void Reserve(size_t newCapacity);
	const char* GetStr()const;
	size_t GetSize() const { return str ? strlen(str) : 0; }
	size_t GetCapacity() const { return capacity; }

	void Output()const;
	static size_t Count() { return count; }

	static void OutputCount();

	friend String operator+(const String& left, const String& right) {
		size_t size1 = left.GetSize();
		size_t size2 = right.GetSize();
		size_t newSize = size1 + size2 + 1;

		String newStr(newSize);

		// Copy the first string
		if (left.str && size1 > 0) {
			strcpy_s(newStr.str, newSize, left.str);
		}
		else {
			newStr.str[0] = '\0';
		}

		if (right.str && size2 > 0) {
			strcat_s(newStr.str, newSize, right.str);
		}

		return newStr;
	}

	friend ostream& operator<<(ostream& os, const String& s) {
		os << s.str;
		return os;
	}

	friend istream& operator>>(istream& is, String& s) {
		if (s.str) {
			delete[] s.str;
		}

		size_t cap = s.capacity > 0 ? s.capacity : 16;
		size_t len = 0;
		char* buffer = new char[cap];

		char ch;

		while (is.get(ch) && ch != '\n') {
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

		s.capacity = len + 1;
		s.capacity = ((s.capacity + 15) / 16) * 16;
		s.str = new char[s.capacity];
		strcpy_s(s.str, s.capacity, buffer);

		delete[] buffer;
		return is;
	}



	friend bool operator==(const String& left, const String& right) {
		if (!left.str && !right.str) return true;
		if (!left.str || !right.str) return false;
		return strcmp(left.str, right.str) == 0;
	}

	friend bool operator!=(const String& left, const String& right) {
		return !(left == right);
	}


};


#endif //STRING
