#include<bits/stdc++.h>
using namespace std;

map<long long, bool> lista;

int main(){ // k-Multiple Free Set
    int n;
    long k, valor;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> valor;
        lista.insert(make_pair(valor, false));
    }
    long long busca;
    for(auto& x: lista){
        busca = k * x.first;
        if(busca != x.first && !x.second && lista.find(busca) != lista.end()){
            lista[busca] = true;
        }
    }
    int cont = 0;
    for(auto& x: lista){
        if(!x.second){
            cont++;
        }
    }
    cout << cont << "\n";
}