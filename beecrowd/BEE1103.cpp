#include<bits/stdc++.h>
using namespace std;

const int dia = 24;
const int hora = 60;

int main(){ // Alarme Despertador
    int h1, h2, m1, m2, tempo;
    while(cin >> h1 >> m1 >> h2 >> m2 && h1 + m1 + h2 + m2 != 0){
        h1 = h1 * hora + m1;
        h2 = h2 * hora + m2;
        if(h1 > h2){
            h2 += hora * dia;
        }
        tempo = h2 - h1;
        cout << tempo << "\n";
    }
}