#include<bits/stdc++.h>
using namespace std;

long long m;

long long calculo(long long x, long long y){
    x %= m;
    long long res = 1;
    while(y > 0){
        if(y & 1){
            res = res * x % m;
        }
        x = x * x % m;
        y >>= 1;
    }
    return res;
}

int main(){ // Big Mod
    long long b, p;
    while(cin >> b >> p >> m){
        cout << calculo(b, p) << "\n";
    }
}