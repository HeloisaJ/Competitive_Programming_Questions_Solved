#include<bits/stdc++.h>
using namespace std;

vector<int> lista;

bool isPrime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

void calculaNumeros(int i, int n){
    int q = i;
    while(i <= n){
        lista.push_back(i);
        i *= q;
    }
}

int main(){ // Vasya and Petya's Game
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        if(isPrime(i)){
            calculaNumeros(i, n);
        }
    }
    cout << lista.size() << endl;
    for(int i = 0; i < lista.size(); i++){
        cout << lista[i];
        if(i != lista.size() - 1){
            cout << " ";
        }
    }
    cout << endl;
}