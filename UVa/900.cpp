#include<bits/stdc++.h>
using namespace std;

long dp[51];
int pos;

long calculo(int num){
    long cont = 0;
    if(dp[num] != 0){
        return dp[num];
    }
    if(num - 1 >= 0){
        cont += calculo(num - 1);
    }
    if(num - 2 >= 0){
        cont += calculo(num - 2);
    }
    if(dp[num] == 0){
        dp[num] = cont;
    }
    return cont;
}

int main(){ // Brick Wall Patterns
    pos = 1;
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    dp[0] = 1;
    int x;
    while(cin >> x && x != 0){
        if(pos < x){
            calculo(x);
            pos = x;
        }
        cout << dp[x] << "\n";
    }
}