#include<bits/stdc++.h>
using namespace std;

int maior;

void calculo(int n[], int cont){
    if(cont > 5){
        return;
    }
    int mult;
    for(int i = 0; i < 3; i++){
        n[i]++;
        cont++;

        if(cont <= 5){
            mult = n[0] * n[1] * n[2];
            if(mult > maior){
                maior = mult;
            }
            calculo(n, cont);
        }

        n[i]--;
        cont--;
    }
}

int main(){ // Only Pluses
    int n[3];
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n[0] >> n[1] >> n[2];
        maior = 0;
        calculo(n, 0);
        cout << maior << "\n";
    }
}