#include<bits/stdc++.h>
using namespace std;

int main(){ // Aeroporto
	int a, v, cont = 1;
	while(cin >> a >> v && a != 0){
		if(cont > 1){
			cout << endl;
		}
		int ini, fim;
		int aero[a];
		for(int i = 0; i < a; i++){
			aero[i] = 0;
		}
		for(int j = 0; j < v; j++){
			cin >> ini >> fim;
			aero[ini - 1]++;
			aero[fim - 1]++;
		}
		int maior[a], pos = 0, m = 0;
		for(int i = 0; i < a; i++){
			if(aero[i] > m){
				m = aero[i];
				pos = 0;
				maior[pos] = i + 1;
				pos++;
			}
			else if(aero[i] == m){
				maior[pos] = i + 1;
				pos++;
			}
		}
		cout << "Teste " << cont << endl;
		for(int i = 0; i < pos; i++){
			cout << maior[i];
			if(i + 1 < pos){
				cout << " ";
			}
		}
		cout << endl;
		cont++;
	}
}
