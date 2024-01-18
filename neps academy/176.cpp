#include<bits/stdc++.h>
using namespace std;

int main(){ // Ordenação Simples
	int n;
	cin >> n;
	long seq[n];
	for(int i = 0; i < n; i++){
		cin >> seq[i];
	}
	long menor, aux; 
	for(int i = 0; i < n; i++){
		menor = i;
		for(int j = i; j < n; j++){
			if(seq[j] < seq[menor]){
				menor = j;
			}
		}
		if(i != menor){
			aux = seq[i];
			seq[i] = seq[menor];
			seq[menor] = aux;
		}
		cout << seq[i];
		if(i != n - 1){
			cout << " ";
		}
	}
	cout << endl;
}
