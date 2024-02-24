#include<bits/stdc++.h>
using namespace std;
#define MAXN 100011

string s, pat;
long minimo, tam;
vector<long> divi;

bool seqCorreta(long m, long val){
    string aux = "";
    for(int i = 0; i < s.size(); i++){
        aux += s[i];
        if(aux.size() == m){
            if(pat == aux){
                aux = "";
            }
            else{
                return false;
            }
        }
    }
    return true;
}

void quantDiv(long v){
    for(int i = 2; i <= v/2; i++){
        if(v % i == 0){
            divi.push_back(i);
        }
    }
}

void busca(){
    long val;
    for(long i = 0; i < divi.size(); i++){
        pat = s.substr(0, divi[i]);
        val = tam/divi[i];
        if(seqCorreta(pat.size(), val)){
            if(pat.size() < minimo){
                minimo = pat.size(); 
            }
        }
    }
}

int main(){ // Periodic Strings
    long t;
    cin >> t;
    for(long k = 0; k < t; k++){
        cin >> s;
        if(k > 0){
            cout << "\n";
        }
        minimo = s.size();
        divi.push_back(1);
        tam = s.size();
        quantDiv(tam);
        busca();
        cout << minimo << "\n";
        divi.clear();
    }
}