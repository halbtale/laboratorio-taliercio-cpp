#include <iostream>
#include "my_vector.h"

using namespace std;

double& MyVector::operator[](const int index) {
	return ptr[index];
}

double& MyVector::operator[](const int index) const {
	return ptr[index];
}

double& MyVector::safe_get(int index) const {
	if (index < 0 || index >= s) throw IndexOutOfBoundException();
	
	return ptr[index];
}

double& MyVector::safe_set(int index, const double val) {
	if (index < 0 || index >= s) throw IndexOutOfBoundException();
	
	ptr[index] = val;
	
	return ptr[index];
}

double& MyVector::at(const int index) {
	return safe_get(index);
}

double& MyVector::at(const int index) const {
	return safe_get(index);
}

void MyVector::resize(const int newCapacity) {
	c = newCapacity;
	
	double* newPtr = new double[c];
	
	for (int i = 0; i<s; i++) {
		newPtr[i] = ptr[i];
	}
	
	delete[] ptr;
	ptr = newPtr;
}

ostream& operator<<(ostream& stream, MyVector& vector) {
	if (vector.size() == 0) {
		stream << "[]\n";
		return stream;
	}
	
	stream << "[";
	for (int i = 0; i<vector.size(); i++) {
		stream << vector[i] << ", ";
	}
	stream << "\b\b]\n";
	
	return stream;
}

void MyVector::push_back(const double& element) {
	if (s == c) resize(c*2);

	ptr[s] = element;
	s++;
}

void MyVector::pop_back() {
	s--;
}

void MyVector::reserve(const int capacity) {
	if (capacity > c) reserve(capacity);
	
	c = capacity;
}

MyVector::MyVector(initializer_list<double> list) {
	s = static_cast<int>(list.size());
	c = s;
	ptr = new double[c];
	copy(list.begin(), list.begin() + s, ptr);
}

MyVector::MyVector(const MyVector& oldVector): s{oldVector.s}, c{oldVector.c}, ptr{new double[c]} {
	std::copy(oldVector.ptr, oldVector.ptr + s, ptr);
}

MyVector::MyVector(MyVector&& oldVector) : s{oldVector.s}, c{oldVector.c}, ptr{oldVector.ptr} {
	oldVector.s = 0;
	oldVector.ptr = nullptr;
}

MyVector& MyVector::operator=(const MyVector& oldVector) {
	double* newPtr = new double[oldVector.c];
	copy(oldVector.ptr, oldVector.ptr + s, newPtr);
	delete[] ptr;
	ptr = newPtr;
	s = oldVector.s;
	c = oldVector.c;
	return *this;
}

MyVector& MyVector::operator=(MyVector&& oldVector) {
	delete[] ptr;
	ptr = oldVector.ptr;
	s = oldVector.s;
	c = oldVector.c;
	oldVector.ptr = nullptr;
	oldVector.s = 0;
	oldVector.c = 0;
	return *this;
}