#include<bits/stdc++.h>
using namespace std;

int main(){ // Matriz Escada
	char resp = 'S';
	int n, m;
	cin >> n >> m;
	int mat[n][m];
	bool linhaZ = false, num, w = false;
	int cont;
	for(int i = 0; i < n; i++){
		cont = 0;
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
			if(mat[i][j] == 0){
				cont++;
			}
		}
		if(linhaZ){
			if(cont < m){
				resp = 'N';
				w = true;
			}
		}
		else{
			if(cont == m){
				linhaZ = true;
			}
		}
	}
	if(!w){
		int i = 0, iantes = 0;
		for(int j = 0; j < m; j++){
			num = false;
			for(int l = i; l < n; l++){
				if(mat[l][j] != 0){
					if(!num){
						num = true;
						i++;
					}
					else{
						resp = 'N';
						w = true;
						break;
					}
				}
			}
			if(w){
				break;
			}
		}
	}
	cout << resp << "\n";
}
