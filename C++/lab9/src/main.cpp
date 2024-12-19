#include <unique_ptr.h>
#include <iostream>
#include <vector>
#include <memory>

void ex_1() {
	unique_ptr<int> ptr(new int {10});
	
	std::cout << "output is " << *ptr << std::endl;
	
	int* released_ptr = ptr.release();
	
	std::cout << "output is " << *released_ptr << std::endl;
	
	delete released_ptr;
	released_ptr = nullptr;
}

void ex_2() {
	std::vector<int> vect(10);
	
	auto ptr = std::make_unique<std::vector<int>>(vect);
	
	for (int i = 0; i<10;i++) {
		(*ptr)[i] = i;
	}
	
	for (int i = 1; i<=4; i++) {
		(*ptr).push_back(i*10);
	}
	
	for (auto curr = (*ptr).begin(); curr != (*ptr).end(); curr++) {
		std::cout << *curr << std::endl;
	}
}

int main() {
	ex_1();
	ex_2();
}