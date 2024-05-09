#include<bits/stdc++.h>
using namespace std;

int main(){ // To My Critics
    int t, a, b, c;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a >> b >> c;
        if(a + b >= 10 || b + c >= 10 || a + c >= 10){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << "\n";
    }
}