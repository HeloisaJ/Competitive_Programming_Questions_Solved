#include<bits/stdc++.h>
using namespace std;

int main(){ // Coins And Triangle
	long n;
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		long cont = 1, total = 1;
		while(n > total && n >= total + cont + 1){
			cont++;
			total += cont;
		}
		cout << cont << endl;
	}
}
