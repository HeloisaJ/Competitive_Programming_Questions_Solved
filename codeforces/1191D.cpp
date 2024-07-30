#include<bits/stdc++.h>
using namespace std;

#define MAX 1123456789

map<long, int> pedras;
int n;
bool turno;
int contP, quantP; // quantidade de pedras mais de duas vezes ou mais de duas pilhas com duas pedras = CSL
long menorPCom2, maior, menor;

void determinarTurno(int valor){
    if(valor % 2 != 0){
        turno = !turno;
    }
}

void calculo(){

    if(menorPCom2 != MAX){
        if(pedras[menorPCom2 - 1] + 1 == 2){
            return;
        }
        else{
            pedras[menorPCom2 - 1]++;
            pedras[menorPCom2]--;
            turno = !turno;
        }
    }

    long anterior = -1;
    for(auto y: pedras){
        
        if(y.first != 0 && y.second != 0){
            if(anterior == -1){
                // zerar a quantidade de pedras dessa pilha, primeira pilha
                determinarTurno(y.first);
                pedras[y.first]--;
                anterior = 0;
            }
            else{
                if(anterior + 1 != y.first){
                    int diferenca = y.first - anterior + 1;
                    determinarTurno(diferenca);
                    pedras[y.first]--;
                    anterior++;
                }
            }
        }
        if(pedras[y.first] != 0){
            anterior = y.first;
        }
    }
}

int main(){ // Tokitsukaze, CSL and Stone Game
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    long x;
    contP = 0;
    quantP = 0;
    menorPCom2 = MAX;
    maior = 0;
    menor = MAX;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(pedras.find(x) != pedras.end()){
            pedras[x]++;
            quantP++;
            if(x < menorPCom2){
                menorPCom2 = x;
            }
            if(pedras[x] > 2){
                contP++;
            }
        }
        else{
            pedras.insert(make_pair(x, 1));
            if(x > maior){
                maior = x;
            }
            if(x < menor){
                menor = x;
            }
        }
    }

    turno = false;
    if(quantP < 2 && contP == 0 && menorPCom2 != 0){
        calculo();
    }

    if(turno){
        cout << "sjfnb";
    }
    else{
        cout << "cslnb";
    }
    cout << "\n";
}