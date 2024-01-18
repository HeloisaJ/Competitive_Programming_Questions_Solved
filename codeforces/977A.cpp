#include<iostream>
using namespace std;

int main(){ // Wrong Subtraction
	int num, sub, last;
	cin >> num >> sub;
	while(sub > 0){

		last = num % 10;

		if(last == 0){
			num = num/10;
		}
		else{
			num--;
		}
		sub--;
	}

	cout << num << endl;

	return 0;
}
