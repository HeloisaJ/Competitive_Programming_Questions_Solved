#include<bits/stdc++.h>
using namespace std;

int main(){ // log2(N)
    long long x, r = 1, c = 0;
    cin >> x;
    while(r < x){
        if(r * 2 > x){
            break;
        }
        r *= 2;
        c++;
    }
    cout << c << "\n";
}