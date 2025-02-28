#ifndef MYIDENTIFIER_H
#define MYIDENTIFIER_H
#include "MyString.h"

class MyIdentifier : public MyString {
private:
	static int cpy_num;
public:
	MyIdentifier();
	MyIdentifier(const char*);
	MyIdentifier(char);
	MyIdentifier(const MyIdentifier&);
	MyIdentifier(const MyString&);
	~MyIdentifier();
	void upper();
	void lower();
	int searchSymb(char);
	MyIdentifier& operator=(const MyIdentifier&);
	MyIdentifier& operator=(const MyString&);
};

#endif