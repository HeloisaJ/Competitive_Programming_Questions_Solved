#include<bits/stdc++.h>
using namespace std;

bool isPrime(long n){
    long raiz = sqrt(n);
    for(long i = 2; i <= raiz; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){ // Prime Generator
    int t;
    long n, m;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        for(long j = n; j <= m; j++){
            if(j > 1 && isPrime(j)){
                cout << j << "\n"; 
            }
        }
        if(i < t - 1){
            cout << "\n";
        }
    }
}