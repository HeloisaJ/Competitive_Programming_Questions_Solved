#include<bits/stdc++.h>
using namespace std;

int ja[512][112];

int main(){ // Biblioteca Pascal
	int n, d;
	while(cin >> n >> d && n != 0 && d != 0){
		for(int i = 0; i < d; i++){
			for(int j = 0; j < n; j++){
				cin >> ja[i][j];
			}
		}
		bool yes, no = true;
		for(int j = 0; j < n; j++){
			yes = true;
			for(int i = 0; i < d; i++){
				if(ja[i][j] == 0){
					yes = false;
				}
			}
			if(yes){
				cout << "yes" << endl;
				no = false;
				break;
			}
		}
		if(no){
			cout << "no" << endl;
		}
	}
}
