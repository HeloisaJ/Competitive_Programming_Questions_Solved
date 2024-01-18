#include<bits/stdc++.h>
using namespace std;

int main(){ // Constructive Problems
    int t, n, m;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        if(n > m){
            cout << n << "\n";
        }
        else{
            cout << m << "\n";
        }
    }
}