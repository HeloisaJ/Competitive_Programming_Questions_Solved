#include<bits/stdc++.h>
using namespace std;

int calculo(int n){
    double val = n;
    int raiz = sqrt(n);
    for(int i = 2; i <= raiz; i++){
        if(n % i == 0){
            while(n % i == 0){
                n = (double)n/(double)i;
            }
            val *= (1.0 - (1.0 / (double)i));
        }
    }
    if(n > 1){
        val *= (1.0 - (1.0 / (double)n));
    }
    return val;
}

int main(){ // ETF - Euler Totient Function
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        cout << calculo(n) << "\n";
    }
}