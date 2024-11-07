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

double& MyVector::at(const int index) const {
	return safe_get(index);
}

void MyVector::resize() {
	c = c * 2;
	
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
