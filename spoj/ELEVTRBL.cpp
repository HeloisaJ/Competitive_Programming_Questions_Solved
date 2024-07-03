#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;
long f, s, g, u, d, quant;
bool possivel;

void calculo(long andarAtual){
    if(visited[andarAtual]){
        possivel = false;
        return;
    }
    visited[andarAtual] = true;
    if(andarAtual == g){
        possivel = true;
    }
    else if(andarAtual < g){
        if(andarAtual + u <= f){
            calculo(andarAtual + u);
        }
        else if(andarAtual - d > 0){
            calculo(andarAtual - d);
        }
        else{
            possivel = false;
        }
        quant++;
    }
    else{
        if(andarAtual - d > 0){
            calculo(andarAtual - d);
        }
        else if(andarAtual + u <= f){
            calculo(andarAtual + u);
        }
        else{
            possivel = false;
        }
        quant++;
    }
}

int main(){ // Elevator Trouble
    cin >> f >> s >> g >> u >> d;
    possivel = true;
    quant = 0;
    visited.assign(f + 1, false);
    calculo(s);
    if(possivel){
        cout << quant;
    }
    else{
        cout << "use the stairs";
    }
    cout << "\n";
}