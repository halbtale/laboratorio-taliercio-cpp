#include "my_vector.h"
#include <iostream>

using namespace std;

int main() {
	MyVector myVector {1,2, 3, 4, 5, 6.1};
	
	for (int i = 0; i<10; i++) {
		myVector.push_back(i*i);
	}
	
	MyVector copiedVector = myVector;

	
	for (int i = 0; i<5; i++) {
		myVector.pop_back();	
	}
	
	copiedVector = myVector;
	
	
	cout << myVector;
	cout << copiedVector;
	
}