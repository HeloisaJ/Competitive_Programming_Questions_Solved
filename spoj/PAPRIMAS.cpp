#include<bits/stdc++.h>
using namespace std;

int soma;
bool prime;

void isPrime(){
	int num = 2;
	while(num <= sqrt(soma)){
		if(soma % num == 0){
			prime = false;
			return;
		}
		num++;
	}
}

int main(){ // Palavras primas
	string s;
	bool start = true;
	while(cin >> s){
		if(!start){
			cout << endl;
		}
		soma = 0;
		for(int i = 0; i < s.size(); i++){
			if(int(s[i]) - 96 > 0){ // Minusculas
				soma += int(s[i]) - 96;
			}
			else{ // Maiusculas
				soma += int(s[i]) - 38;
			}
		}
		prime = true;
		isPrime();
		if(prime){
			cout << "It is a prime word.";
		}
		else{
			cout << "It is not a prime word.";
		}
		start = false;
	}
}
