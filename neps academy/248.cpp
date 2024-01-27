#include<bits/stdc++.h>
using namespace std;
#define MAX 11234

int n, maior;
vector<pair<long, long>> consultas;
int dp [MAX];

int calculo(int i){
    if(dp[i] != -1){
        return dp[i];
    }
    dp[i] = 1;
    for(int j = i; j < n; j++){
        if(consultas[i].second <= consultas[j].first){
            dp[i] = max(dp[i], calculo(j) + 1);
        }
    }
    maior = max(maior, dp[i]);
    return dp[i];
}

int main(){ // Dentista
    cin >> n;
    long ini, fim;
    for(int i = 0; i < n; i++){
        cin >> ini >> fim;
        consultas.push_back(make_pair(ini, fim));
    }
    memset(dp, -1, sizeof(dp));
    maior = 1;
    for(int i = 0; i < n; i++){
        calculo(i);
    }
    cout << maior << "\n";
}