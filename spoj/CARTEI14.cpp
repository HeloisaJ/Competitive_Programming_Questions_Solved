#include<bits/stdc++.h>
using namespace std;

map<long, int> casas; // Casa e a posição dela

int main(){ // Carteiro
    int n, m;
    cin >> n >> m;
    long num, mov = 0;
    for(int i = 1; i <= n; i++){
        cin >> num;
        casas.insert(make_pair(num, i));
    }
    int posInicial = 1;
    for(int i = 0; i < m; i++){
        cin >> num;
        mov += abs(casas[num] - posInicial);
        posInicial = casas[num];
    }
    cout << mov << endl;
}