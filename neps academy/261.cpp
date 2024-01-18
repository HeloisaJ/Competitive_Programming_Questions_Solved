#include<bits/stdc++.h>
using namespace std;

long force[112345];
long prize[112345];

void espaco(int i, int m){
	if(i != m - 1){
		cout << " ";
	}
}

int main(){ // Ogros
	int n, m;
	cin >> n >> m;
	force[0] = 0;
	for(int i = 1; i < n; i++){
		cin >> force[i];
	}
	for(int i = 0; i < n; i++){
		cin >> prize[i];
	}
	long of;
	for(int i = 0; i < m; i++){
		cin >> of;
		for(int j = 0; j < n - 1; j++){
			if(of >= force[j] && of < force[j + 1]){
				cout << prize[j];
				espaco(i, m);
				break;
			}
		}
		if(of >= force[n - 1]){
			cout << prize[n - 1];
			espaco(i, m);
		}
	}
	cout << endl;
}
