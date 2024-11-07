#include "my_vector.h"
#include <iostream>

using namespace std;

int main() {
	MyVector myVector = MyVector(10);
	MyVector myVectorVoid;
	
	myVector.safe_set(3, 10.4);
	
	cout << myVector;
	cout << myVectorVoid;
	
	cout << myVector.at(3) << "\n";
	
}