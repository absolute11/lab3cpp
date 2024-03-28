#include "MyString.h"
#include <iostream>;
using namespace std;
MyString::MyString() {
	s = new char[1];
	*s = '\0';
	len = 0;
}
MyString::MyString(char* t) {
	s = new char[strlen(t) + 1];
	*s = '\0';
	strcpy_s(s,strlen(t)+1, t);
	len = strlen(t);

}
MyString::MyString(const MyString& u) {
	s = new char[u.len + 1];
	*s = '\0';
	strcpy_s(s,len+1,u.s);
	len = u.len;
}
MyString::~MyString() {
	delete[] s;
}
char& MyString::item(int t) {
	char err = 'e';
	if (t <= len && t >= 0) {
		return s[t];
	}
	else {
		cout << "ERROR";
		return err;
	}

}
MyString* MyString::copy() {
	return new MyString(*this);
}

void MyString::assign(const MyString& u) {
	s = new char[u.len + 1];
	*s = '\0';
	len = u.len;
	strcpy_s(s,len+1, u.s);
	
}

int MyString::cmp(const MyString& t) {
	return strcmp(s, t.s);
}
int MyString::equal(const MyString& t)const {
	return strcmp(s, t.s) == 0;
}
int MyString::equal(const MyString& t) {
	return strcmp(s, t.s) == 0;
}
int MyString::input() {
	if (cin.eof()) {
		return 0;
	}
	char buf1[256];
	cin.getline(buf1, 254, '\n');
	if (strlen(buf1) == 0) cin.getline(buf1, 254, '\n');
	s = new char[strlen(buf1) + 1];
	len = strlen(buf1);
	*s = '\0';
	strcpy_s(s,len+1, buf1);
	return 0;


}

int MyString::output() {
	cout << s << endl;
	return 0;
}

