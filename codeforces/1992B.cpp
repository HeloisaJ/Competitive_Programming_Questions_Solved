#include<bits/stdc++.h>
using namespace std;

int a[112345];

int main(){ // Angry Monk
    int t, k;
    cin >> t;
    long n;
    for(int i = 0; i < t; i++){
        cin >> n >> k;

        for(int j = 0; j < k; j++){
            cin >> a[j];
        }

        sort(a, a + k);
        long contM = 0;
        for(int j = 0; j < k - 1; j++){

            if(a[j] == 1){
                contM++;
            }
            else{
                contM += (a[j] - 1) + a[j];
            }
        }
        cout << contM << "\n";
    }
}