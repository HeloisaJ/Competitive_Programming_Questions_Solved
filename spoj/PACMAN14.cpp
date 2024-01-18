#include<bits/stdc++.h>
using namespace std;

char tab[100][100];
int maior, cont;

void func(int i, int j){
	if(tab[i][j] == 'A'){
		if(cont > maior){
			maior = cont;
		}
		cont = 0;
	}
	else if(tab[i][j] == 'o'){
		cont++;
	}
}

int main(){ // PacMan
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> tab[i][j];
		}
	}
	maior = 0;
	cont = 0;
	for(int i = 0; i < n; i++){
		int j;
		if(i == 0 || i % 2 == 0){
			j = 0;
			while(j < n){
				func(i, j);
				j++;
			}
		}
		else{
			j = n - 1;
			while(j >= 0){
				func(i, j);
				j--;
			}
		}	
	}
	if(cont > maior){
		maior = cont;
	}
	cout << maior << endl;
}
