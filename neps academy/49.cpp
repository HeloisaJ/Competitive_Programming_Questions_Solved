#include<bits/stdc++.h>
using namespace std;

const int tam = 11234; // Fita Colorida
int fita[tam];
int posZero[tam];
int quantZero;

void loop(int ini, int ate){ // Loop Decrescente
	int num = ate - ini;
	if(num >= 9){
		num = 9;
	}
	for(int i = ini; i < ate; i++){
		fita[i] = num;
		num--;
		if(ate - i > 9){
			num = 9;
		}
	}
}

void loop2(int ini, int ate){ // Loop Crescente
	int num = 1;
	for(int i = ini; i <= ate; i++){
		fita[i] = num;
		num++;
		if(num > 9){
			num--;
		}
	}
}

void configFita(int n){
	if(posZero[0] != 0){
		loop(0, posZero[0]);	
	}
	for(int i = 0; i < quantZero; i++){
		if(i == quantZero - 1){
			loop2(posZero[i] + 1, n);
		}
		else{
			int dist = posZero[i + 1] - posZero[i] - 1;
			if(dist % 2 == 0){
				if(dist != 0){
					loop2(posZero[i] + 1, dist/2 + posZero[i]);
					loop(dist/2 + posZero[i] + 1, posZero[i + 1]);
				}
			}
			else{
				loop2(posZero[i] + 1, dist/2 + posZero[i]);
				loop(dist/2 + posZero[i] + 1, posZero[i + 1]);
			}
		}
	}
}

int main(){
	int n;
	quantZero = 0;
	cin >> n;
	int j = 0;
	for(int i = 0; i < n; i++){
		cin >> fita[i];
		if(fita[i] == 0){
			posZero[quantZero] = i;
			quantZero++;
		}
	}
	configFita(n);
	for(int i = 0; i < n; i++){
		if(i == n - 1){
			cout << fita[i];
		}
		else{
			cout << fita[i] << " ";
		}
	}
	cout << endl;
	return 0;
}
