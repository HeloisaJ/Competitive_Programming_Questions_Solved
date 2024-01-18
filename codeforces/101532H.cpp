#include<iostream>
using namespace std;

int main(){ // Corrupted Images
	int T;
	cin >> T;

	for(int z = 0; z < T; z++){
		int n, m;
		cin >> n >> m;
		char matriz[n][m];
	    int mod1 = 0;
		int mov = 0;
		int n1 = 0;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				char elem;
				cin >> elem;
				matriz[i][j] = elem;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(matriz[i][j] == '1'){
					if(i != 0 && i != n - 1 && j != 0 && j != m - 1){
						mov++;
					}
					else{
						mod1++;
					}
				}
			}
		}

		n1 = m * 2 + (n - 2) * 2;

		if(mod1 + mov < n1){ // Não tem a quantidade certa de 1 para completar a imagem
			cout << -1 << endl;
		}
		else if(mod1 + mov == n1){ // Tem a quantidade certa de 1 para completar a imagem
			cout << mov << endl;
		}
		else if(mod1 == n1){ // A imagem já está da forma certa
			cout << 0 << endl;
		}
		else{ // mod1 + mov > n1, quantidade de 1 maior que a quantidade de mov para completar a moldura
			cout << n1 - mod1 << endl;
		}
	}

	return 0;
}
