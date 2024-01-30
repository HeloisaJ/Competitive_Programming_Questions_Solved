#include<bits/stdc++.h>
using namespace std;

int const q = 3;
int n;
int c[q];
int quantosC[4123][q];
int dp[4123];

int calcVa(int i, int j){
    return c[0] * quantosC[i - c[j]][0];
}

int calcVb(int i, int j){
    return c[1] * quantosC[i - c[j]][1];
}

int calcVc(int i, int j){
    return c[2] * quantosC[i - c[j]][2];
}

int total(int i, int j){
    int va, vb, vc;
    if(j == 0){
        va = c[j] * (quantosC[i - c[j]][j] + 1);
        vb = calcVb(i, j);
        vc = calcVc(i, j);
    }
    else if(j == 1){
        vb = c[j] * (quantosC[i - c[j]][j] + 1);
        va = calcVa(i, j);
        vc = calcVc(i, j);
    }
    else{
        vc = c[j] * (quantosC[i - c[j]][j] + 1);
        va = calcVa(i, j);
        vb = calcVb(i, j);
    }
    return va + vb + vc;
}

void calculo(){ 
    for(int i = 1; i <= n; i++){
        int valor = 0;
        for(int j = 0; j < q; j++){
            if(c[j] <= i){
                valor = max(valor, dp[i - c[j]] + 1);
                if(i == total(i, j)){
                    quantosC[i][0] = quantosC[i - c[j]][0];
                    quantosC[i][1] = quantosC[i - c[j]][1];
                    quantosC[i][2] = quantosC[i - c[j]][2];
                    quantosC[i][j]++;
                    dp[i] = max(dp[i], valor);
                    valor = dp[i];
                }
            }
        }
    }
}

int main(){ // Cut Ribbon
    cin >> n;
    for(int i = 0; i < q; i++){
        cin >> c[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    calculo();
    cout << dp[n] << "\n";
}