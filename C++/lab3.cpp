#include <iostream>

using namespace std;

void f_illegal() {
	int simpleArray[10];
	
	simpleArray[10] = 999;
	
	cout << simpleArray[10] << "\n";

}

void f() {
	int simpleArray[10];
	
	int* el = &simpleArray[1];
	
	for (int i = 0; i<10; i++) {
		el[i-1] = i;
	}
}

void print_array_length(double* myArray) {
	cout << sizeof(myArray) << "\n";
}

void program1() {
	f();
	f_illegal();
}

void program2() {
	constexpr int arrayLength = 5;
	double myArray[arrayLength];
	cout << sizeof(myArray) << "\n";
	print_array_length(myArray);
}

void print_reference(const double& n) {
	cout << n << "\n";
}

void print_pointer(double* n) {
	cout << *n << "\n";
}

void print_pointer(int* n) {
	cout << *n << "\n";
}

void program3() {
	int a = 10;
	double b = 3.14;
	
	print_reference(a);
	print_reference(b);
	
	print_pointer(&a);
	print_pointer(&b);
}

int main() {
	program1();
	program2();
	program3();
}