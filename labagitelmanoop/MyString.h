#pragma once

class MyString
{
private:
	char* s;
	int len;
public:
	MyString();
	MyString(char*);
	MyString(const MyString&);
	~MyString();
	char& item(int);
	MyString* copy();
	void assign(const MyString&);
	int cmp(const MyString&);
	int equal(const MyString&) const;
	int equal(const MyString&);
	int input();
	int output();
	
	
	
	

	
};

