#include<bits/stdc++.h>
using namespace std;

int color[112345];
vector<vector<int>> grafo;

bool ehBipartido(int s){
    queue<int> q;
    q.push(s);
    color[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: grafo[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if(color[v] == color[u]){
                return false;
            }
        }
    }
    return true;
}

int main(){ // Building Teams
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    grafo.assign(n + 1, vector<int>());
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        grafo[x].push_back(y);
        grafo[y].push_back(x);
    }
    memset(color, -1, sizeof(color));
    bool bipartido = true;
    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            if(!ehBipartido(i)){
                bipartido = false;
                break;
            }
        }
    }
    if(!bipartido){
        cout << "IMPOSSIBLE" << "\n";
    }
    else{
        for(int i = 1; i <= n; i++){
            cout << (color[i] + 1);
            if(i < n){
                cout << " ";
            }
        }
        cout << "\n";
    }
}