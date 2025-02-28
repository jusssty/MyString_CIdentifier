
#include <iostream>
#include "../include/MyString.h"

int MyString::cpy_num = 0;

MyString::MyString() : size(0), str(nullptr) {}

MyString::MyString(const char *_str) {
	for (size = 0; _str[size] != '\0'; size++);
	str = new char[size + 1];
	for (int i = 0; i < size; i++) str[i] = _str[i];
	str[size] = '\0';
}

MyString::MyString(char symb) : size(1) {
	str = new char[2];
	str[0] = symb; 
	str[1] = '\0';
}

MyString::MyString(const MyString &s) : size(s.size) {
	MyString::cpy_num++;
	str = new char[s.size + 1];
	for (int i = 0; i < size; i++) str[i] = s.str[i];
	str[size] = '\0';
}

MyString::~MyString() {
	if (str != nullptr) delete[] str;
}

int MyString::getlen() const {
	return size;
}

int MyString::getCpyNum() const {
	return cpy_num;
}

void MyString::strClear() {
	if (str != nullptr) {
		delete[] str;
		str = nullptr;
		size = 0;
	}
	return;
}

void MyString::checkIdnt() {
	for (int i = 0; i < size; i++) {
		if (!((str[i] >= 'A' && str[i] <= 'Z') 
			|| (str[i] >= 'a' && str[i] <= 'z') 
			|| (str[i] >= '0' && str[i] <= '9') 
			|| str[i] == '_') 
			|| (!i && str[i] >= '0' && str[i] <= '9')) {
			strClear();
			std::cout << "Неверный символ!\n";
			break;
		}
	}
}

char MyString::returnSymb(int s) const {
	return str[s];
}

MyString& MyString::operator=(const MyString &s) {
	strClear();
	size = s.size;
	str = new char[s.size + 1];
	for (int i = 0; i < size; i++) str[i] = s.str[i];
	str[size] = '\0';
	return *this;
}

MyString MyString::operator-(const MyString &s) {
	MyString temp(str);
	for (int i = 0; i < s.size; i++) {
		for (int j = 0; j < temp.size; j++) {
			if (temp.str[j] == s.str[i]) {
				for (int k = j + 1; k < temp.size; k++) temp.str[k - 1] = temp.str[k];
				temp.size--; j--;
			}
		}
	}
	return temp;
}

MyString MyString::operator+(const MyString &s) {
	MyString temp;
	temp.size = size + s.size;
	temp.str = new char[size + s.size + 1];
	for (int i = 0; i < size; i++) temp.str[i] = str[i];
	for (int i = size; i < size + s.size; i++) temp.str[i] = s.str[i - size];
	temp.str[size + s.size] = '\0';
	return temp;
}

bool MyString::operator>(const MyString &s) {
	int mn = std::min(s.size, size);
	for (int i = 0; i < mn; i++) {
		if (str[i] < s.str[i]) return false;
		if (str[i] > s.str[i]) return true;
	}
	if (size <= s.size) return false;
	return true;
}

bool MyString::operator<(const MyString &s) {
	int mn = std::min(s.size, size);
	for (int i = 0; i < mn; i++) {
		if (str[i] > s.str[i]) return false;
		if (str[i] < s.str[i]) return true;
	}
	if (size >= s.size) return false;
	return true;
}

std::istream &operator>>(std::istream &in, MyString &s) {
	s.strClear();
	s.str = new char[255];
	in.getline(s.str, 255);
	while (s.str[s.size] != '\0') s.size++;
	return in;
}

std::ostream &operator<<(std::ostream &out, MyString &s) {
	for (int i = 0; i < s.size; i++) out << s.str[i];
	return out;
}

