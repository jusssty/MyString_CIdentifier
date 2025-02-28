#ifndef MYSTRING_H 
#define MYSTRING_H
#include <iostream>

class MyString {
private:
	static int cpy_num;
protected:
	char *str;
	int size;
public:
	MyString();
	MyString(const char*);
	MyString(char);
	MyString(const MyString&);
	~MyString();
	int getlen() const;
	int getCpyNum() const;
	void strClear();
	void checkIdnt();
	char returnSymb(int) const;
	MyString& operator=(const MyString&);
	MyString operator-(const MyString&);
	MyString operator+(const MyString&);
	bool operator>(const MyString&);
	bool operator<(const MyString&);
	friend std::istream &operator>>(std::istream&, MyString&);
	friend std::ostream &operator<<(std::ostream&, MyString&);
};

#endif