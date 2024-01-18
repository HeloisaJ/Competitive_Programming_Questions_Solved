#include<iostream>
using namespace std;

int main(){ // Fibonacci
	int i, num;
	int first = 1, second = 1;
	int fib = 1;
	cin >> num;

	for(i = 1; i < num; i++){
		fib = first + second;
		second = first;
		first = fib;
	}

	cout << fib << endl;

	return 0;
}
