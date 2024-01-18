#include<iostream>
using namespace std;

int Estado(int lamp){ // Lâmpadas
	if(lamp == 0){
		lamp = 1;
	}
	else{
		lamp = 0;
	}
	return lamp;
}

int main(){ 
	int A = 0, B = 0;
	int num, interruptor;
	cin >> num;

	while(num > 0){
		cin >> interruptor;
		if(interruptor == 1){
			A = Estado(A);
		}
		else{
			B = Estado(B);
			A = Estado(A);
		}
		num--;
	}

	cout << A << endl;
	cout << B << endl;
	
	return 0;
}
