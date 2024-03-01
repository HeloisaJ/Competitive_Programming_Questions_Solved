#include<bits/stdc++.h>
using namespace std;
#define MAX 6 * 1000 * 1000

int calculoArea(int a, int b, int c){
    return 2 * a * b + 2 * a * c + 2 * b * c;
}

vector<int> calculo(int n){
    vector<int> lista;
    for(int i = 1; i < n; i++){
        if(n % i == 0){
            lista.push_back(i);
        }
    }
    return lista;
}

int menorValor(vector<int> lista, int x, int y, int minimo){
    for(int i = 0; i < lista.size(); i++){
        minimo = min(calculoArea(x/lista[i], y, lista[i]), minimo);
    }
    return minimo;
}

int calculoMult(int n){
    int raiz = sqrt(n);
    int minimo = MAX;
    vector<int> lista;
    for(int i = 1; i <= raiz; i++){
        if(n % i == 0){
            lista = calculo(i);
            minimo = menorValor(lista, i, n/i, minimo);
            lista = calculo(n/i);
            minimo = menorValor(lista, n/i, i, minimo);
        }
    }
    return minimo;
}

int main(){ // Blocks
    int t, n, val;
    cin >> t;
    for(int k = 0; k < t; k++){
        cin >> n;
        val = cbrt(n);
        if(val * val * val == n){
            cout << calculoArea(val, val, val) << "\n";
        }
        else{
            cout << calculoMult(n) << "\n";
        }
    }
}