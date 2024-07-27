#include<bits/stdc++.h>
using namespace std;

string cubo, s;
set<string> combinacoes;
stack<string> pilha;
bool resp;

int girarCima[] = {2, 1, 5, 6, 2};
int girarDir[] = {2, 4, 5, 3, 2};

string copiar(string x){
    string p = "";
    for(int i = 0; i < 6; i++){
        p += x[i];
    }
    return p;
}

string criarComb1(int a[], string x){
    string p = copiar(x);
    char save, aux;

    save = p[a[1] - 1];
    for(int i = 0; i < 4; i++){
        if(i == 0){
            p[a[i + 1] - 1] = p[a[i] - 1];
        }
        else{
            aux = p[a[i + 1] - 1];
            p[a[i + 1] - 1] = save;
            save = aux;
        }

    }

    return p;
}

bool comparar(string x){
    for(int i = 0; i < 6; i++){
        if(x[i] != s[i]){
            return false;
        }
    }
    return true;
}

void calculo(){
    pilha.push(cubo);
    combinacoes.insert(cubo);
    string comb;

    while(!pilha.empty()){
        comb = pilha.top();
        pilha.pop();

        if(comparar(comb)){
            resp = true;
            break;
        }
        else{
            string x = "";
            x = criarComb1(girarCima, comb);
            if(combinacoes.find(x) == combinacoes.end()){
                pilha.push(x);
                combinacoes.insert(x);
            }

            x = "";
            x = criarComb1(girarDir, comb);
            if(combinacoes.find(x) == combinacoes.end()){
                pilha.push(x);
                combinacoes.insert(x);
            }
        }
    }
}

int main(){ // Cube painting
    string cores;
    while(cin >> cores){
        cubo = "";
        for(int i = 0; i < 6; i++){
            cubo += cores[i];
        }

        s = "";
        for(int i = 6; i < cores.size(); i++){
            s += cores[i];
        }

        resp = false;
        calculo();

        if(resp){
            cout << "TRUE";
        }
        else{
            cout << "FALSE";
        }
        cout << "\n";
        combinacoes.clear();
        while(!pilha.empty()){
            pilha.pop();
        }
    }
}