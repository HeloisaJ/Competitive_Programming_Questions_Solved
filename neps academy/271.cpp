#include<bits/stdc++.h>
using namespace std;

int main(){ // Expressões
	string s, res;
	int t;
	cin >> t;
	for(int k = 0; k < t; k++){
		cin >> s;
		res = "S";
		stack<char> carac;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '(' || s[i] == '[' || s[i] == '{'){ // aberto
				carac.push(s[i]);
			}
			else{ // fechado
				if(!carac.empty()){ // não vazio, ver o complemento
					if((carac.top() == '(' && s[i] == ')') || (carac.top() == '[' && s[i] == ']') || (carac.top() == '{' && s[i] == '}')){
						carac.pop();
					}
					else{ // não forma um par
						res = "N";
						break;
					}
				}
				else{ // tem um caracter de fechamento sem uma entrada
					res = "N";
					break;
				}
			}
		}
		if(!carac.empty()){
			res = "N";
		}
		cout << res << "\n";
	}
}
