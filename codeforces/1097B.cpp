#include<bits/stdc++.h>
using namespace std;

int giros[21];
bool possivel;
int n;

void calculo(long comb, int pos, int h, int a){
    if(pos == n){
        return;
    }
    calculo(comb, pos + 1, h, a);
    comb = comb | 1 << pos;
    h -= giros[pos];
    a += giros[pos];
    if((h - a) % 360 == 0){
        possivel = true;
        return;
    }
    calculo(comb, pos + 1, h, a);
}

int main(){ // Petr and a Combination Lock
    cin >> n;
    long soma = 0;
    for(int i = 0; i < n; i++){
        cin >> giros[i];
        soma += giros[i];
    }
    possivel = false;
    if(soma % 360 == 0){
        possivel = true;
    }
    else{
        calculo(0, 0, soma, 0);
    }

    if(possivel){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    cout << "\n";
}