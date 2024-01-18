#include<bits/stdc++.h>
using namespace std;

int main(){ // Manolo, O Fazendeiro
	int n, ci, li, cf, lf;
	long cenouras = 0;
	cin >> n;
	int mat[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> mat[i][j];
		}
	}
	int q;
	cin >> q;
	for(int k = 0; k < q; k++){
		cin >> li >> ci >> lf >> cf;
		for(int i = li - 1; i < lf; i++){
			for(int j = ci - 1; j < cf; j++){
				cenouras += mat[i][j];
				mat[i][j] = 0;
			}
		}
	}
	cout << cenouras << endl;
	return 0;
}
