#include "vec.h" 
#include <iostream> 
using namespace std;
vec::vec() {
	v = new T[size = 10];
}

vec::vec(int sz) {
	v = new T[size = sz];
}
vec::vec(const vec& w)
{
	v = new T[size = w.size];
	for (int i = 0; i < size; i++) {
		v[i] = w.v[i];
	}

}
vec::~vec() {
	delete[]v;
}

T& vec::item(int i) {
	if (i < 0 && i >= size) {
		cout << "Index Error";
		exit(1);
	}
	return v[i];
}

void vec::resize(int n) {
	T* t = new T[size + n];
	for (int i = 0; i < size; i++) {
		t[i] = v[i];
		delete[] v;
		v = t;
		size += n;

	}

}

void vec::assign(const vec& t) {
	if (size == t.size) {
		for (int i = 0; i < size; i++) {
			v[i] = t.v[i];

		}
	}
	else {
		cout << "Size Error";
		exit(1);
	}
}