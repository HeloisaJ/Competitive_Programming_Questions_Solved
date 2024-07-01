#include<bits/stdc++.h>
using namespace std;

int n;
long long t, tempoMax, save;
long maquinas[212345];

bool verificar(long long meio){
    long long soma = 0;
    for(int i = 0; i < n; i++){
        soma += meio/maquinas[i];
        if(soma >= t){
            return true;
        }
    }
    return false;
}

void busca(){
    long long ini = 0, fim = tempoMax, meio;
    while(ini <= fim){
        meio = (ini + fim)/2;
        if(verificar(meio)){
            if(save == -1 || meio < save){
                save = meio;
            }
            fim = meio - 1;
        }
        else{
            ini = meio + 1;
        }
    }
}

int main(){ // Factory Machines
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> t;
    long long maior = 0;
    for(int i = 0; i < n; i++){
        cin >> maquinas[i];
        if(maquinas[i] > maior){
            maior = maquinas[i];
        }
    }
    tempoMax = t * maior;
    save = -1;
    busca();
    cout << save << "\n";
}