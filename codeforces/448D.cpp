#include<bits/stdc++.h>
using namespace std;

long long n, m, k;

long long verificar(long long meio){
    long long res = 0;
    meio--;
    for(int i = 1; i <= n; i++){
        res += min(meio/i, m);
    }
    return res;
}

int main(){ // Multiplication Table
    cin >> n >> m >> k;

    long long ini = 1, fim = n * m, meio, valor;
    while(ini <= fim){
        meio = (ini + fim)/2;
        valor = verificar(meio);

        if(valor >= k){
            fim = meio - 1;
        }
        else{
            ini = meio + 1;
        }
    }
    cout << ini - 1 << "\n";
}