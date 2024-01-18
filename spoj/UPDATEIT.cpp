#include<bits/stdc++.h>
using namespace std;

int main(){ // Update the array !
    int t, n, u, l, r, val, q, qi;
    cin >> t;
    for(int k = 0; k < t; k++){
        cin >> n >> u;
        int f[n];
        int ref[n];
        for(int i = 0; i < n; i++){
            f[i] = 0;
            ref[i] = 0;
        }
        for(int i = 0; i < u; i++){
            cin >> l >> r >> val;
            ref[l] += val;
            if(r + 1 < n){
                ref[r + 1] -= val;
            }
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += ref[i];
            f[i] = sum;
        }
        cin >> q;
        for(int i = 0; i < q; i++){
            cin >> qi;
            cout << f[qi] << endl;
        }
    }
}