#include<bits/stdc++.h>
using namespace std;

int letras[26];
unsigned long res;

void arrLetras(){
    for(int i = 0; i < 26; i++){
        letras[i] = 0;
    }
}

void rep(string w){
    for(int i = w.size() - 1; i >= 0; i--){
        int letra = int(w[i]) - 65;
        if(letras[letra] > 1){
            for(int j = 1; j <= letras[letra]; j++){
                res = res/j;
            }
            letras[letra] = 1;
        }
    }
}

int main(){ // Mischievous Children (Other version)
    int t;
    cin >> t;
    string w;
    for(int k = 1; k <= t; k++){
        cin >> w;
        arrLetras();
        int letra;
        for(int i = 0; i < w.size(); i++){
            letra = int(w[i]) - 65;
            letras[letra]++;
        }
        res = 1;
        for(int i = w.size() - 1; i >= 0; i--){
            if(res == 479001600){
                rep(w);
            }
            res *= (i + 1);
        }
        rep(w);
        cout << "Data set " << k << ": " << res << endl;
    }   
}