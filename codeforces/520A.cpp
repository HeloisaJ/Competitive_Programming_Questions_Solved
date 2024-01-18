#include<bits/stdc++.h>
using namespace std;

int const alpha = 26;
int const a = 97;

int main(){ // Pangram
	int n;
	cin >> n;
	string x;
	cin >> x;
	if(n < 26){
		cout << "NO" << endl;
	}
	else{
		int letras[alpha]; //a = 97, z = 122, A = 65, Z = 90
		for(int i = 0; i < n; i++){
			if(int(x[i]) < a){
				letras[x[i] + 32 - a] = 1;
			}
			else{
				letras[x[i] - a] = 1;
			}
		}
		bool correto = true;
		for(int i = 0; i < alpha; i++){
			if(letras[i] != 1){
				correto = false;
			}
		}
		if(correto){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}
