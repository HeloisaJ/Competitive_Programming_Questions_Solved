#include<bits/stdc++.h>
using namespace std;

int s, n;
vector<pair<long, long>> itens; // tamanho, valor

int main(){ // The Knapsack Problem
    cin >> s >> n;
    long x1, x2;
    for(int i = 0; i < n; i++){
        cin >> x1 >> x2;
        itens.push_back(make_pair(x1, x2));
    }
    long valores[n + 1][s + 1]; // quant, tamanhoRest
    memset(valores, 0, sizeof(valores));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= s; j++){
            if(itens[i - 1].first > j){
                valores[i][j] = valores[i - 1][j];
            }
            else{
                valores[i][j] = max(valores[i - 1][j], valores[i - 1][j - itens[i - 1].first] + itens[i - 1].second);
            }
        }
    }
    cout << valores[n][s] << "\n";
}