#include<bits/stdc++.h>
using namespace std;

int dp[1123456];

void calculo(){
    for(int i = 1000000; i > 0; i--){
        if(i > 100){
            dp[i] = i - 10;
        }
        else{
            dp[i] = dp[dp[i + 11]];
        }
    }
}

int main(){ // f91
    int n;
    calculo();
    while(cin >> n && n != 0){
        cout << "f91(" << n << ") = " << dp[n] << "\n";
    }
}