#include<bits/stdc++.h>
using namespace std;

int n, k, maior;
string w;

void seMaior(int tam){
	if(tam > maior){
		maior = tam;
	}
}

void func(char comp){
	int tam = 0, i = 0, j = 0, contK = 0;
	while(j < n){
		if(w[j] != comp){
			contK++;
			if(contK > k){
				seMaior(tam);
				while(contK > k){
					if(w[i] != comp){
						contK--;
					}
					i++;
					tam--;
				}
			}
		}
		j++;
		tam++;
	}
	seMaior(tam);
}

int main(){ // Vasya and String
	cin >> n >> k >> w;
	maior = 0;
	func('a');
	func('b');
	cout << maior << endl;
}
