#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo;
vector<int> visited;
bool ciclo, bloq;
long cont, c, c2;
int n, m;

void calculoDfs(int v, int b){
    visited[v] = 0;
    c2++;

    for(int u: grafo[v]){
        if(visited[u] == 0 && u != b){
            ciclo = true;
            c++;
        }
        else if(visited[u] == -1){
            calculoDfs(u, v);
            c++;
        }
    }

    if(grafo[v].size() != 2){
        bloq = true;
    }
    visited[v] = 1;
}

int main(){ // Cyclic Components
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int x, y;
    cin >> n >> m;
    grafo.assign(n + 1, vector<int>());

    for(int i = 0; i < m; i++){
        cin >> x >> y;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }

    cont = 0;
    visited.assign(n + 1, -1);
    for(int i = 1; i <= n; i++){
        ciclo = false;
        if(visited[i] == -1){
            c = 0;
            c2 = 0;
            bloq = false;
            calculoDfs(i, 0);
            if(ciclo && c == c2 && !bloq){
                cont++;
            }
        }
    }
    cout << cont << "\n";
}