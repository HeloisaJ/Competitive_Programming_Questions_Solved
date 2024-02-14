#include<bits/stdc++.h>
using namespace std;

unsigned long long soma;

void calculo(int n){
    int raiz = sqrt(n);
    for(int i = 2; i <= raiz; i++){
        if(n % i == 0){
            soma += i;
            if(i * i != n){
                soma += n/i;
            }
        }
    }
}

int main(){ // Divisor Summation
    cin.tie(0);
	ios_base::sync_with_stdio(0);
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        if(n == 1){
            cout << 0 << "\n";
        }
        else{
            soma = 1;
            calculo(n);
            cout << soma << "\n";
        }
    }
}