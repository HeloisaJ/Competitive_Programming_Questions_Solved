#include<bits/stdc++.h>
using namespace std;

string res;

void calculo(long x, long y){
    long metade = x/2;
    if(metade == y){
        return;
    }
    else{
        res = "Yes";
    }
}

int main(){ // Rectangle Cutting
    int t;
    cin >> t;
    long a, b;
    for(int k = 0; k < t; k++){
        res = "No";
        cin >> a >> b;
        if(a % 2 == 0){
            calculo(a, b);
        }
        if(b % 2 == 0){
            calculo(b, a);
        }
        cout << res << "\n";
    }
}