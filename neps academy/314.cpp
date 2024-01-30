#include<bits/stdc++.h>
using namespace std;

int dp[1123];
int notas[1123];
int n, m;

void calculo(){
    int valor = 1123;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < n; j++){
            if(notas[j] <= i){
                dp[i] = min(dp[i], 1 + dp[i - notas[j]]);
            }
        }
    }
}

int main(){ // Mano, tu me dá esse troco com menos de dez moedas!
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> notas[i];
    }
    memset(dp, 1123, sizeof(dp));
    dp[0] = 0;
    calculo();
    if(dp[m] < 10){
        cout << 'S' << "\n";
    }
    else{
        cout << 'N' << "\n";
    }
}