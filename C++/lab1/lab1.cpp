#include <iostream>
#include <vector>

using namespace std;

int d = 0;
int e;

void print(const string& s, const vector<int>& v) {
	cout << s << "\n";
	for (int i = 0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void fib(const int x, const int y, vector<int>& v, const int n) {
	v.clear();
	v.push_back(x);
	v.push_back(y);
	
	for (int i=2; i<n; i++) {
		v.push_back(v[i-1]+v[i-2]);
	}
}

void call_counter() {
	static int count = 0;
	cout << "il contatore e' " << ++count << " \n";
}

int main() {
	cout << "Hello world\n";
	int a = 0;
	static int b = 4;
	static int gatto = 100;
	static int c;
	vector<int> v {1,2,3,4,5,6};
	fib(1,1,v,100);
	//print("il mio vector: ", v);
	call_counter();
	call_counter();
	call_counter();
	call_counter();
	call_counter();
	return 0;
}