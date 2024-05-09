#include<bits/stdc++.h>
using namespace std;

int t, n, k;

int main(){ // Preparing for the Contest
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> k;
        int quant = 0;
        for(int j = 1; j <= k; j++){
            cout << j;
            quant++;
            if(quant != n){
                cout << " ";
            }
        }
        for(int j = n; j > k; j--){
            cout << j;
            quant++;
            if(quant != n){
                cout << " ";
            }
        }
        cout << "\n";
    }
}