#include<bits/stdc++.h>
using namespace std;
#define MAX 112345

long stalls[MAX];
long minimo;
int n, c;

bool verificar(long meio){
    int contC = 1, i = 0, j = 1;
    while(i <= n - 2 && j <= n - 1 && contC < c){
        if(stalls[j] - stalls[i] >= meio){
            contC++;
            i = j;
        }
        j++;
    }
    if(contC < c){
        return false;
    }
    minimo = max(minimo, meio);
    return true;
}

void busca(long ini, long fim){
    while(ini <= fim){
        long meio = (ini + fim)/2;
        if(!verificar(meio)){
            fim = meio - 1;
        }
        else{
            ini = meio + 1;
        }
    }
}

int main(){ // Aggressive cows
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        cin >> n >> c;
        for(int i = 0; i < n; i++){
            cin >> stalls[i];
        }
        sort(stalls, stalls + n);
        minimo = 1;
        busca(1, stalls[n - 1] - stalls[0]);
        cout << minimo << "\n";
    }
}