#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo;
vector<int> visited, gatos;
long contR;
int m;

void calculoDfs(int v, int con){
    visited[v] = 1;
    if(gatos[v] == 1){
        con++;
    }
    else{
        con = 0;
    }
    if(con > m){
        return;
    }

    for(int u: grafo[v]){
        if(visited[u] == 0){
            calculoDfs(u, con);
        }
    }

    if(grafo[v].size() == 1 && v != 0){
        contR++;
    }
}

int main(){ // Kefa and Park
    int n, x, y;
    cin >> n >> m;

    grafo.assign(n, vector<int>());
    for(int i = 0; i < n; i++){
        cin >> x;
        gatos.push_back(x);
    }
    for(int i = 0; i < n - 1; i++){
        cin >> x >> y;
        x--;
        y--;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
    visited.assign(n, 0);
    contR = 0;
    calculoDfs(0, 0);
    cout << contR << "\n";
}