#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000
#define TESTES 10000000

vector<bool> repetidos;
vector<long> numeros;
long respostas[14];
int k;

void roda(){
    if(!numeros.empty()){
        numeros.clear();
    }
    for(int i = 1; i <= 2 * k; i++){
        numeros.push_back(i);
    }
}

bool calculoRoda(int m){
    long pos = 0, val, cont = 0, dobro = 2 * k;
    roda();
    while(cont < k){
        val = m % (dobro - cont);
        pos = ((val + pos) % (dobro - cont)) - 1;
        if(pos == -1){
            pos = (dobro - cont) - 1;
        }
        if(numeros[pos] > k){
            numeros.erase(numeros.begin() + pos);
        }
        else{
            return false;
        }
        cont++;
    }
    return true;
}

int main(){ // Joseph
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    memset(respostas, -1, sizeof(respostas));
    while(cin >> k && k != 0){
        if(respostas[k - 1] == -1){
            repetidos.assign(MAX, false);
            long mult = 1, resp;
            bool minimo = false;
            for(int i = k; i <= TESTES; i++){
                if(!repetidos[i]){
                    minimo = calculoRoda(i);
                    repetidos[i] = true;
                }
                if(minimo){
                    resp = i;
                    break;
                }
                mult++;
            }
            respostas[k - 1] = resp;
        }
        cout << respostas[k - 1] << "\n";
    }
}