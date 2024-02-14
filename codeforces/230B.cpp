#include<bits/stdc++.h>
using namespace std;

unsigned long long a;

bool isPrime(unsigned long long n){
    unsigned long long raiz = sqrt(n);
    for(int i = 2; i <= raiz; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

bool isTPrime(){
    unsigned long long raiz = sqrt(a);
    if(raiz * raiz == a && isPrime(raiz) && a != 1){
        return true;
    }
    return false;
}

int main(){ // T-primes
    cin.tie(0);
	ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(isTPrime()){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }
}