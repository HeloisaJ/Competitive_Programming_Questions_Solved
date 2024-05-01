#include<bits/stdc++.h>
using namespace std;
#define MAX 51

long long matriz[MAX][MAX];
string s, a, b;
int k, pos;

void calculoTrianguloPascal(int limite){
    for(int i = pos; i <= limite; i++){
        matriz[i][0] = 1;
        matriz[i][i] = 1;
        for(int j = 1; j < i; j++){
            matriz[i][j] = matriz[i - 1][j] + matriz[i - 1][j - 1];
        }
    }
}

void formarResp(){
    int valorA = k, valorB = 0;
    bool multiplicacao;
    for(int i = 0; i <= k; i++){
        multiplicacao = false;
        if(i != 0 && i != k){
            cout << matriz[k][i] << "*";
        }
        if(valorA > 0){
            cout << a;
            if(valorA != 1){
                cout << "^" << valorA;
            }
            if(valorA < k){
                multiplicacao = true;
            }
        }
        if(multiplicacao){
            cout << "*";
        }
        if(valorB > 0){
            cout << b;
            if(valorB != 1){
                cout << "^" << valorB;
            }
        }
        if(i < k){
            cout << "+";
        }
        valorA--;
        valorB++;
    }
    cout << "\n";
}

void destrinchar(){
    a = "";
    b = "";
    string pot = "";
    bool aOuB = false, valorK = false;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == ')'){
            continue;
        }
        else if(s[i] == '+'){
            aOuB = true;
        }
        else if(s[i] == '^'){
            valorK = true;
        }
        else if(valorK){
            pot += s[i];
        }
        else{
            if(!aOuB){
                a += s[i];
            }
            else{
                b += s[i];
            }
        }
    }
    k = stoi(pot);
}

int main(){ // Binomial Theorem
    int t;
    cin >> t;
    matriz[0][0] = 1;
    pos = 0;
    for(int i = 0; i < t; i++){
        cin >> s;
        destrinchar();
        if(k > pos){
            calculoTrianguloPascal(k);
            pos = k;
        }
        cout << "Case " << (i + 1) << ": ";
        formarResp();
    }
}