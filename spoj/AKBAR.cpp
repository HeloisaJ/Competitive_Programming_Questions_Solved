#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo;
vector<int> visited;
bool opt;
int quantV, n;

void calculoDfs(int v, int cont, int s, int d){
    if(visited[v] == -1){
        quantV++;
    }
    visited[v] = d;
    if(!opt || cont + 1 > s){
        return;
    }

    for(auto x: grafo[v]){
        if(visited[x] == -1 || visited[x] == d){
            calculoDfs(x, cont + 1, s, d);
        }
        else{
            opt = false;
        }
    }
}

int main(){ // Akbar , The great
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t, r, m, x, y;
    cin >> t;
    for(int k = 0; k < t; k++){
        cin >> n >> r >> m;
        
        grafo.assign(n + 1, vector<int>());
        for(int i = 0; i < r; i++){
            cin >> x >> y;
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }

        quantV = 0;
        opt = true;
        visited.assign(n + 1, -1);
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            if(visited[x] == -1 && opt){
                calculoDfs(x, 0, y, x);
            }
            else{
                opt = false;
            }
        }

        if(!opt || quantV < n){
            cout << "No" << "\n";
        }
        else{
            cout << "Yes" << "\n";
        }
    }
}