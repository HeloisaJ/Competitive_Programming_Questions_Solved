#include<bits/stdc++.h>
using namespace std;

int n;
int dp[112345][3];
int valores[112345][3];

void calculo(){
    for(int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(j != k){
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + valores[i][j]);
                }
            }
        }
    }
}

int main(){ // Vacation
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> valores[i][j];
            if(i == 0){
                dp[i][j] = valores[i][j];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    calculo();
    int maior = 0;
    for(int i = 0; i < 3; i++){
        if(dp[n - 1][i] > maior){
            maior = dp[n - 1][i];
        }
    }
    cout << maior << "\n";
}