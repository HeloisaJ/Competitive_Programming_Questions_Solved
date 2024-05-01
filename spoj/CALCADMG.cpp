#include<bits/stdc++.h>
using namespace std;

int main(){ // Caminhando pela calçada
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    long a, b, c, d;
    for(int i = 0; i < t; i++){
        cin >> a >> b >> c >> d;
        cout << __gcd(abs(a - c), abs(b - d)) + 1 << "\n";
    }
}