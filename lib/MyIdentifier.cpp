#include <iostream>
#include "../include/MyIdentifier.h"

int MyIdentifier::cpy_num = 0;

MyIdentifier::MyIdentifier() : MyString() {}

MyIdentifier::MyIdentifier(const char *_str) : MyString(_str) {
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

MyIdentifier::MyIdentifier(char s) : MyString(s) {
	if (!((str[0] >= 'A' && str[0] <= 'Z') 
		|| (str[0] >= 'a' && str[0] <= 'z') 
		|| (str[0] >= '0' && str[0] <= '9') 
		|| str[0] == '_') 
		|| (str[0] >= '0' && str[0] <= '9')) {
		strClear();
		std::cout << "Неверный символ!\n";
	}
}

MyIdentifier::MyIdentifier(const MyIdentifier &id) : MyString(id) {
	MyIdentifier::cpy_num++;
}

MyIdentifier::MyIdentifier(const MyString &id) : MyString(id) {
	MyIdentifier::cpy_num++;
}

MyIdentifier::~MyIdentifier() {}

void MyIdentifier::upper() {
	for (int i = 0; i < size; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
	}
	return;
}

void MyIdentifier::lower() {
	for (int i = 0; i < size; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
	}
	return;
}

int MyIdentifier::searchSymb(char a) {
	for (int i = 0; i < size; i++) {
		if (a == str[i]) return i;
	}
	return -1;
}

MyIdentifier& MyIdentifier::operator=(const MyIdentifier &s) {
	strClear();
	size = s.size;
	str = new char[s.size + 1];
	for (int i = 0; i < size; i++) str[i] = s.str[i];
	str[size] = '\0';
	return *this;
}

MyIdentifier& MyIdentifier::operator=(const MyString &s) {
	strClear();
	size = s.getlen();
	str = new char[size + 1];
	for (int i = 0; i < size; i++) str[i] = s.returnSymb(i);
	str[size] = '\0';
	return *this;
}
