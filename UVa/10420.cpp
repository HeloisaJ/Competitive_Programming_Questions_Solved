#include<bits/stdc++.h>
using namespace std;

int main(){ // List of Conquests
    map<string, int> listagem;
    int n;
    cin >> n;
    string pais, nome;
    for(int i = 0; i < n; i++){
        cin >> pais;
        getline(cin, nome);
        if(listagem.find(pais) == listagem.end()){
            listagem.insert(make_pair(pais, 1));
        }
        else{
            listagem[pais]++;
        }
    }
    for(auto& x: listagem){
        cout << x.first << " " << x.second << "\n";
    }
}