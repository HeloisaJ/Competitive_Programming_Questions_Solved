#include<bits/stdc++.h>
using namespace std;

long long n;

long long calculo(long long x, long long y){
    x %= n;
    long long res = 1;
    while(y > 0){
        if(y & 1){
            res = res * x % n;
        }
        x = x * x % n;
        y >>= 1;
    }
    return res;
}

int main(){ // MODEX
    long long c, x, y;
    while(cin >> c && c != 0){
        for(long long i = 0; i < c; i++){
            cin >> x >> y >> n;
            cout << calculo(x, y) << "\n";
        }
    }
}