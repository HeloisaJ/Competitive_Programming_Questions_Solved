#include<bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<vector<int>> grafo;

void dfs(int s){
    visited[s] = 1;
    for(int i = 0; i < grafo[s].size(); i++){
        if(visited[grafo[s][i]] == 0){
            dfs(grafo[s][i]);
        }
    }
}

int main(){ // Transmissão de Energia
    int e, l, x, y, cont = 1;
    while(cin >> e >> l && e != 0){
        if(cont > 1){
            cout << "\n";
        }
        grafo.assign(e, vector<int>());
        visited.assign(e, 0);
        for(int i = 0; i < l; i++){
            cin >> x >> y;
            x--;
            y--;
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }
        dfs(x);
        bool conec = true;
        for(int i = 0; i < visited.size(); i++){
            if(visited[i] == 0){
                conec = false;
            }
        }
        cout << "Teste " << cont << "\n";
        if(conec){
            cout << "normal" << "\n";
        }
        else{
            cout << "falha" << "\n";
        }
        cont++;
        grafo.clear();
        visited.clear();
    }
}