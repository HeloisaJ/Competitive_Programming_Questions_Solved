#include<bits/stdc++.h>
using namespace std;

long ata[112345];

int main(){ // Frequência na Aula
	int n;
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> ata[i];
	}
	sort(ata, ata + n);
	int cont = 1;
	for(int i = 0; i < n - 1; i++){
		if(ata[i] != ata[i + 1]){
			cont++;
		}
	}
	cout << cont << endl;
}
