#include<iostream>
using namespace std;

int main(){ // Kefa and First Steps
	int N;
	long int num1, num2;
	cin >> N;
	cin >> num1;
	int cont = 1;
	int save = 0;
	for(int i = 0; i < N - 1; i++){
		cin >> num2;
		if(num1 > num2){
			if(cont > save){
				save = cont;
			}
			cont = 0;
		}
		cont++;
		num1 = num2;
	}
	if(cont > save){
		cout << cont << endl;
	}
	else{
		cout << save << endl;
	}
	return 0;
}
