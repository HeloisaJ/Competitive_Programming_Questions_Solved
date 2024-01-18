#include<bits/stdc++.h>
using namespace std;

map<long, int> votos;

int main(){ // Eleições
    int n;
    long v;
    cin >> n;
    for(int k = 0; k < n; k++){
        cin >> v;
        if(votos.find(v) == votos.end()){
            votos.insert(make_pair(v, 1));
        }
        else{
            votos[v]++;
        }
    }
    int maior = 0;
    for(auto& x: votos){
        if(x.second > maior){
            maior = x.second;
            v = x.first;
        }
    }
    cout << v << "\n";
}