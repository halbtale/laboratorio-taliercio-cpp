#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>

using namespace std;

class MyVector {
	double* ptr = nullptr;
	int s = 0;
	int c = 0;
	
	void resize(int newCapacity);
	
public:
	MyVector() : s{0}, c{8}, ptr{new double[8]} {};
	
	MyVector(int size) : s{size}, c{size}, ptr{new double[size]} {};
	
	MyVector(initializer_list<double> list);
	MyVector(const MyVector& oldVector);
	MyVector(MyVector&& oldVector);
	
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
	
	double& at(const int index);
	double& at(const int index) const;
	
	void push_back(const double& element);
	void pop_back();
	
	void reserve(const int capacity);
	
	MyVector& operator=(const MyVector& oldVector);
	MyVector& operator=(MyVector&& oldVector);
	
	
	class IndexOutOfBoundException {};
};

ostream& operator<<(ostream& stream, MyVector& vector);

#endif