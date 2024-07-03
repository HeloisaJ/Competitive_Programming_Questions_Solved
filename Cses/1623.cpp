#include<bits/stdc++.h>
using namespace std;

#define INF 15123456789

long long soma;
int apples[21];
int n;
long long menor;

void calculo(long comb, int pos, long long q){
    if(pos == n){
        return;
    }
    calculo(comb, pos + 1, q);
    comb = comb | 1 << pos;
    q += apples[pos];
    long q2 = soma - q;
    if(abs(q - q2) < menor){
        menor = abs(q - q2);
    }
    calculo(comb, pos + 1, q);
}

int main(){ // Apple Division
    cin >> n;
    soma = 0;
    for(int i = 0; i < n; i++){
        cin >> apples[i];
        soma += apples[i];
    }
    menor = INF;
    calculo(0, 0, 0);
    cout << menor << "\n";
}