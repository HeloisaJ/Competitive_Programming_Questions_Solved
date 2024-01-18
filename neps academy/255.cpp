#include<bits/stdc++.h>
using namespace std;

int main(){ // Soma de Casas
	int n;
	long k;
	cin >> n;
	long casas[n];
	for(int i = 0; i < n; i++){
		cin >> casas[i];
	}
	cin >> k;
	long soma;
	int pointI = 0, pointF = n - 1;
	while(pointI < pointF){
		soma = casas[pointI] + casas[pointF];
		if(soma > k){
			pointF--;
		}
		else if(soma < k){
			pointI++;
		}
		else{ // igual
			break;
		}
	}
	cout << casas[pointI] << " " << casas[pointF] << endl;
}
