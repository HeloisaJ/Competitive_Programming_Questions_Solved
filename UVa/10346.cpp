#include<bits/stdc++.h>
using namespace std;

int func(long long n, long long k){
    long long val = n/k;
    long long resto = n % k;
    if(val >= k && resto == 0){
        return val + func(val, k);
    }
    if(val + resto >= k){
        return val + func(val + resto, k);
    }
    return val;
}

int main(){ // Peter’s Smokes
    long long n, k;
    while(cin >> n >> k){
        cout << func(n, k) + n << "\n";
    }
}