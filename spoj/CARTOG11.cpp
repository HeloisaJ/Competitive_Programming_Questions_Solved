#include<bits/stdc++.h>
using namespace std;

long maior;
int pos;
vector<vector<int>> grafo;
vector<bool> visited;

void calculoDfs(int v, long cont){
    visited[v] = true;

    for(int u: grafo[v]){
        if(!visited[u]){
            calculoDfs(u, cont + 1);
        }
    }

    if(cont > maior){
        maior = cont;
        pos = v;
    }
}

int main(){ // Desafio cartográfico
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, x, y;
    cin >> n;
    grafo.assign(n + 1, vector<int>());

    for(int i = 0; i < n - 1; i++){
        cin >> x >> y;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }

    maior = 0;
    visited.assign(n + 1, false);
    calculoDfs(1, 0);
    visited.assign(n + 1, false);
    calculoDfs(pos, 0);

    cout << maior << "\n";
}