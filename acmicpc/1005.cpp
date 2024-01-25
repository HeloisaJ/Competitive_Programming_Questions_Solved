#include<bits/stdc++.h>
using namespace std;

#define MAX 1123456

vector<int> pedras;
int menorDif, n, val, soma;
int valores[MAX];

void calculo(int i, int mask){
    int valMask = (mask | (1 << i));
    valores[valMask] = pedras[i] + valores[mask];
    val = abs(soma - valores[valMask]);
    menorDif = min(menorDif, abs(val - valores[valMask]));
    if(i + 1 < n){
        calculo(i + 1, valMask);
        calculo(i + 1, mask);
    }
    else{
        return;
    }
}

int main(){ // Stone Pile
    int p;
    soma = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p;
        pedras.push_back(p);
        soma += p;
    }
    menorDif = soma;
    memset(valores, 0, sizeof(valores));
    valores[0] = 0;
    calculo(0, 0);
    cout << menorDif << "\n";
}