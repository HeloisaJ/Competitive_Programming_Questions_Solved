#include<bits/stdc++.h>
using namespace std;

map<char, set<char>> grafo;
vector<int> visited;
bool valido;
string g; 

void calculoDfs(char v, char p){
    visited[v - 97] = 0;
    g += v;

    if(grafo[v].size() > 2){
        valido = false;
    }
    if(!valido){
        return;
    }

    for(char u: grafo[v]){
        if(visited[u - 97] == 0 && u != p){
            valido = false; // ciclo
            return;
        }
        else if(visited[u - 97] == -1){
            calculoDfs(u, v);
        }
    }
}

int main(){ // Perfect Keyboard
    int t;
    string s;
    cin >> t;
    char salvar = '.';
    for(int k = 0; k < t; k++){
        cin >> s;
        visited.assign(26, -1);

        for(int i = 0; i < s.size(); i++){
            if(grafo.find(s[i]) == grafo.end()){
                grafo.insert(make_pair(s[i], set<char>()));
            }
            if(i > 0 && s[i] != s[i - 1]){
                grafo[s[i]].insert(s[i - 1]);
            }
            if(i < s.size() - 1 && s[i] != s[i + 1]){
                grafo[s[i]].insert(s[i + 1]);
            }
        }

        for(int i = 0; i < s.size(); i++){
            if(grafo[s[i]].size() == 1){
                salvar = s[i];
            }
        }

        valido = true;
        g = "";
        if(salvar != '.'){
            calculoDfs(salvar, '.');
        }
        else{
            calculoDfs(s[0], '.');
        }

        if(!valido){
            cout << "NO";
        }
        else{
            string res = "";
            bool f = true; 
            for(int i = 0; i < 26; i++){
                if(grafo['a' + i].empty()){
                    res += char('a'+ i);
                }
                else if(salvar != '.' && f){
                    for(int j = 0; j < g.size(); j++){
                        res += g[j];
                    }
                    f = false;
                }
            }
            if(res.size() < 26){
                cout << "NO";
            }
            else{
                cout << "YES" << "\n";
                cout << res;
            }
        }
        cout << "\n";
        grafo.clear();
    }
}