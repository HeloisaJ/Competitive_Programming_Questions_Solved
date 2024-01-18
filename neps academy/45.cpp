#include<bits/stdc++.h>
using namespace std;

int main(){ // Torre
	int n;
	cin >> n;
	int tab[n][n];
	pair<int, int> somas [n];
	int soma = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> tab[i][j];
			soma += tab[i][j];
		}
		somas[i].second = soma;
		soma = 0;
	}

	for(int j = 0; j < n; j++){
		for(int i = 0; i < n; i++){
			soma += tab[i][j];
		}
		somas[j].first = soma;
		soma = 0;
	}

	int maior = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			soma = somas[i].second + somas[j].first - 2 * tab[i][j];
			if(soma > maior){
				maior = soma;
			} 
		}
	}

	cout << maior << endl;

	return 0;
}
