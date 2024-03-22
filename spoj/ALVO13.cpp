#include<bits/stdc++.h>
using namespace std;

vector<long> raios;
long c, t;

int busca(double raio){
    long pos = -1, inicio = 0, fim = raios.size() - 1, meio;
    while(inicio <= fim){
        meio = (inicio + fim)/2;
        if(raio <= raios[meio]){
            fim = meio - 1;
            pos = meio;
        }
        else{
            inicio = meio + 1;
        }
    }
    return pos;
}

int main(){ // Tiro ao Alvo
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    unsigned long long total = 0;
    long a, x, y; 
    cin >> c >> t;
    for(long i = 0; i < c; i++){
        cin >> a;
        raios.push_back(a);
    }
    for(long i = 0; i < t; i++){
        cin >> x >> y;
        if(x == 0 && y == 0){
            total += c;
        }
        else{
            double raio;
            unsigned long long x1, y1;
            x1 = abs(x);
            y1 = abs(y);
            if(x1 != 0 && y1 != 0){
                raio = x1 * x1 + y1 * y1;
                raio = sqrt(raio);
            }
            else{
                if(x == 0){
                    raio = y1;
                }
                else{
                    raio = x1;
                }
            }
            long pos = busca(raio);
            if(pos != -1){
                total += c - pos;
            }
        }
    }
    cout << total << "\n";
}