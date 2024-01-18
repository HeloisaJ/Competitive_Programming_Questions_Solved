#include<bits/stdc++.h>
using namespace std;

int n, m;

int main(){ // Minesweeper
	int cont = 1;
	while(cin >> n >> m && n != 0 && m != 0){
		if(cont != 1){
			cout << endl;
		}
		char field[n][m];
		int hint[n][m];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> field[i][j];
				hint[i][j] = 0;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(field[i][j] == '*'){
					if(i > 0 && i < n - 1){ 
						hint[i + 1][j]++;
						hint[i - 1][j]++;
						if(j > 0 && j < m - 1){ 
							hint[i + 1][j + 1]++;
							hint[i + 1][j - 1]++;
							hint[i][j + 1]++;
							hint[i][j - 1]++;
							hint[i - 1][j + 1]++;
							hint[i - 1][j - 1]++;
						}
						else if(j == m - 1 && j > 0){
							hint[i + 1][j - 1]++;
							hint[i][j - 1]++;
							hint[i - 1][j - 1]++;
						}
						else if(j == 0 && j < m - 1){ 
							hint[i + 1][j + 1]++;
							hint[i][j + 1]++;
							hint[i - 1][j + 1]++;
						}
					}
					else if(i == n - 1 && i > 0){
						hint[i - 1][j]++;
						if(j > 0 && j < m - 1){ 
							hint[i][j + 1]++;
							hint[i][j - 1]++;
							hint[i - 1][j + 1]++;
							hint[i - 1][j - 1]++;
						}
						else if(j == m - 1 && j > 0){
							hint[i][j - 1]++;
							hint[i - 1][j - 1]++;
						}
						else if(j == 0 && j < m - 1){ 
							hint[i][j + 1]++;
							hint[i - 1][j + 1]++;
						}
					}
					else if(i == 0 && i < n - 1){
						hint[i + 1][j]++;
						if(j > 0 && j < m - 1){ 
							hint[i + 1][j + 1]++;
							hint[i + 1][j - 1]++;
							hint[i][j + 1]++;
							hint[i][j - 1]++;
						}
						else if(j == m - 1 && j > 0){
							hint[i + 1][j - 1]++;
							hint[i][j - 1]++;
						}
						else if(j == 0 && j < m - 1){ 
							hint[i + 1][j + 1]++;
							hint[i][j + 1]++;
						}
					}
					else{
						if(j > 0 && j < m - 1){ 
							hint[i][j + 1]++;
							hint[i][j - 1]++;
						}
						else if(j == m - 1 && j > 0){
							hint[i][j - 1]++;
						}
						else if(j == 0 && j < m - 1){
							hint[i][j + 1]++;
						}
					}
				}
			}
		}
		cout << "Field #" << cont << ":" << endl; 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(field[i][j] == '*'){
					cout << '*';
				}
				else{
					cout << hint[i][j];
				}
			}
			cout << endl;
		}
		cont++;
	}
}
