#include<bits/stdc++.h>
using namespace std;

long long k, n, a, b, maior;

bool verificar(long long meio){
    if(k - (a * meio + b * (n - meio)) > 0){
        maior = max(maior, meio);
        return true;
    }
    return false;
}

void busca(long long ini, long long fim){
    long long meio;
    while(ini <= fim){
        meio = (ini + fim)/2;
        if(verificar(meio)){
            ini = meio + 1;
        }
        else{
            fim = meio - 1;
        }
    }
}

int main(){ // Computer Game
    long long q;
    cin >> q;
    for(long long i = 0; i < q; i++){
        cin >> k >> n >> a >> b;
        if(k - b * n <= 0){
            cout << -1 << "\n";
        }
        else if(k - a * n > 0){
            cout << n << "\n";
        }
        else{
            maior = 0;
            busca(0, n);
            cout << maior << "\n";
        }
    }
}