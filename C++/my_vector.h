#ifndef MY_VECTOR
#define MY_VECTOR

#include <iostream>

using namespace std;

class MyVector {
	double* ptr = nullptr;
	int s = 0;
	int c = 0;
	
	void resize();
	
public:
	MyVector() : s{0}, c{8}, ptr{new double[8]} {};
	
	MyVector(int size) : s{size}, c{size}, ptr{new double[size]} {};
	
	~MyVector() {
		delete[] ptr;
	}
	
	int size() const {
		return s;
	}
	
	double& operator[](int index);
	double& operator[](int index) const;
	
	double& safe_get(int index) const;
	double& safe_set(int index, const double val);
	
	double& at(const int index) const;
	
	class IndexOutOfBoundException {};
};

ostream& operator<<(ostream& stream, MyVector& vector);

#endif