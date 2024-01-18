#include<bits/stdc++.h>
using namespace std;

int organizar[112345];

int main(){ // Ilya and Queries
	string s;
	cin >> s;
	int cont = 0;
	organizar[0] = 0;
	for(int i = 1; i < s.size(); i++){
		if(s[i] == s[i -  1]){
			cont++;
		}
		organizar[i] = cont;
	}
	int m, li, ri;
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> li >> ri;
		cout << organizar[ri - 1] - organizar[li - 1] << endl; 
	}
}
