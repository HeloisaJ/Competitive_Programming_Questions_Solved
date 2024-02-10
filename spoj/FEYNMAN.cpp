#include<bits/stdc++.h>
using namespace std;

long dp[112];
int n, pos;

void calculo(){
    for(int i = pos + 1; i <= n; i++){
        dp[i] = dp[i - 1] + i * i;
    }
}

int main(){ // Feynman
    pos = 1;
    dp[1] = 1;
     while(cin >> n && n != 0){
        if(n > pos){
            calculo();
            pos = n;
        }
        cout << dp[n] << "\n";
    }
}