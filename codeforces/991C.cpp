#include<bits/stdc++.h>
using namespace std;

long long n, metade, minimo;

bool verificar(long long meio){
    long long v = 0, quant = n;
    while(quant > 0){
        if(meio > quant){
            v += quant;
            quant = 0;
        }
        else{
            quant -= meio;
            v += meio;
        }

        if(quant >= 10){
            long long porc = quant/10;
            quant -= porc;
        }
    }
    if(v >= metade){
        minimo = min(minimo, meio);
        return true;
    }
    return false;
}

void busca(long long ini, long long fim){
    long long meio;
    while(ini <= fim){
        meio = (ini + fim)/2;
        if(verificar(meio)){
            fim = meio - 1;
        }
        else{
            ini = meio + 1;
        }
    }
}

int main(){ // Candies
    cin >> n;
    metade = n/2;
    minimo = metade;
    if(n % 2 != 0){
        minimo++;
        metade++;
    }
    busca(1, minimo);
    cout << minimo << "\n";
}