#include<bits/stdc++.h>
using namespace std;

int main(){ // Bafana Bafana
    int t, n, k, p;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n >> k >> p;
        cout << "Case " << i << ": ";
        if(k + p > n){
            if((k + p) % n == 0){
                cout << n << "\n";
            }
            else{
                cout << (k + p) % n << "\n";
            }
        }
        else{
            cout << k + p << "\n";
        }
    }
}