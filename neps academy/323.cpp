#include<iostream>
using namespace std;

int main(){ // Desafio do Maior Número
	int num,  maior = 0;
	while(cin >> num && num != 0){
		if(num > maior){
			maior = num;
		}
	}
	cout << maior;
	return 0;
}
