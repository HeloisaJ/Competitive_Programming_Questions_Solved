#include<bits/stdc++.h>
using namespace std;
#define MAX 1123456

int n, m;
long arvores[MAX];
long maiorAlt;

bool verificar(long meio){
    long soma = 0;
    for(int i = 0; i < n; i++){
        if(arvores[i] > meio){
            soma += arvores[i] - meio;
        }
    }
    if(soma < m){
        return false;
    }
    maiorAlt = max(maiorAlt, meio);
    return true;
}

void busca(long ini, long fim){
    long meio;
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

int main(){ // Eko
    cin >> n >> m;
    long maior = 0;
    for(int i = 0; i < n; i++){
        cin >> arvores[i];
        if(arvores[i] > maior){
            maior = arvores[i];
        }
    }
    maiorAlt = 0;
    busca(0, maior);
    cout << maiorAlt << "\n";
}