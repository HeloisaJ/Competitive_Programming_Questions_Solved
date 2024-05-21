#include<bits/stdc++.h>
using namespace std;

int main(){ // Water Station
    int n, m, d;
    cin >> n;
    m = n % 5;
    if(m == 0){
        cout << n;
    }
    else{
        d = n/5;
        if(m >= 3){
            d++;
        }
        cout << d * 5;
    }
    cout << "\n";
}