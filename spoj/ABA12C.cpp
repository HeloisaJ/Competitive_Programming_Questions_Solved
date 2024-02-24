#include<bits/stdc++.h>
using namespace std;
#define MAXIMO 112345

int n, k;
int a[112];
long long dp[112];
bool valor[112];

void calculo(int kg){
    for(int i = 1; i <= kg; i++){
        if(a[i] != -1 && valor[kg - i]){
            if(kg - i == 0){
                dp[kg] = min(dp[kg], dp[kg - i] + a[i]);
                valor[kg] = true;
            }
            else if(kg - i > 0){
                dp[kg] = min(dp[kg], dp[kg - i] + a[i]);
            }
        }
    }
}

int main(){ // Buying Apples!
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> k;
        for(int j = 1; j <= k; j++){
            cin >> a[j];
            dp[j] = MAXIMO;
            valor[j] = false;
        }
        dp[0] = 0;
        valor[0] = true;
        for(int j = 1; j <= k; j++){
            calculo(j);
        }
        if(dp[k] != MAXIMO){
            cout << dp[k] << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
}