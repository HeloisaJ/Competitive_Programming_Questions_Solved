#include<bits/stdc++.h>
using namespace std;

bool prime;

void isPrime(int num){
	int m = 2;
	while(m <= sqrt(num)){
		if(num % m == 0){
			prime = false;
			break;
		}
		m++;
	}
}

int main(){ // Goldbach’s Conjecture (II)
	int n;
	while(cin >> n && n != 0){
		int p1 = 2, p2 = n - 2, cont = 0;
		while(p1 <= n/2){
			prime = true;
			isPrime(p1);
			isPrime(p2);
			if(prime){
				cont++;
			}
			p1++;
			p2--;
		}
		cout << cont << endl;
	}
}
