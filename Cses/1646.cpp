#include<bits/stdc++.h>
using namespace std;

long long prefixo[212345];
long val[212345];

int main(){ // Static Range Sum Queries
    int n, q, x, y;
    cin >> n >> q;
    long long soma = 0;
    prefixo[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> val[i];
        soma += val[i];
        prefixo[i] = soma;
    }
    for(int i = 0; i < q; i++){
        cin >> x >> y;
        x--;
        cout << (prefixo[y] - prefixo[x]) << "\n";
    }
}