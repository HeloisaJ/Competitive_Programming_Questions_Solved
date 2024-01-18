#include<iostream>
using namespace std;

int a[112][112];
int res[112345];
int n;

int calcularAjuste(int cont, int i, int j){
    int ia;
    res[cont] = a[i][j];
    cont++;
    ia = i;
    while(ia - 1 >= 0 && j + 1 < n){
        ia--;
        j++;
        res[cont] = a[ia][j];
        cont++;
    }
    return cont;
}

int main(){ // Some Words about Sport
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    int i, j, cont = 0;
    for(i = 0; i < n; i++){
        j = 0;
        cont = calcularAjuste(cont, i, j);
    }
    i = n - 1;
    for(int j = 1; j < n; j++){
        cont = calcularAjuste(cont, i, j);
    }
    for(i = 0; i < cont; i++){
        cout << res[i];
        if(i != cont - 1){
            cout << " ";
        }
    }
    cout << "\n";
}