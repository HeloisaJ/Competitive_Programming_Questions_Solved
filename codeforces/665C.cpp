#include<bits/stdc++.h>
using namespace std;

string s;

char encontrarLetra(char letra, char va){
    for(int i = 0; i < 26; i++){
        if('a' + i != letra && 'a' + i != va){
            return 'a' + i;
        }
    }
}

void substituiImpar(int inicio, int pos){
    bool imp = false;
    for(int i = inicio; i <= pos; i++){
        if(imp){
            s[i] = encontrarLetra(s[i], s[i]);
        }
        imp = !imp;
    }
}

void substituiPar(int inicio, int pos){
    bool p = false;
    for(int i = inicio; i <= pos; i++){
        if(!p){
            s[i] = encontrarLetra(s[i], s[i - 1]);
        }
        p = !p;
    }
}

void calculo(int inicio, int i){
    if(inicio == -1){
        return;
    }
    int cont = i - inicio + 1;
    if(cont > 1){
        if(cont % 2 != 0){
            substituiImpar(inicio, i);
        }
        else{
            substituiPar(inicio, i);
        }
    }
}

int main(){ // Simple Strings
    cin >> s;
    int inicio = -1, i;
    bool first = false;
    for(i = 0; i < s.size() - 1; i++){
        if(s[i] != s[i + 1]){
            calculo(inicio, i);
            first = false;
            inicio = -1;
        }
        else{
            if(!first){
                inicio = i;
                first = true;
            }
        }
    }
    calculo(inicio, i);
    cout << s << "\n";
}