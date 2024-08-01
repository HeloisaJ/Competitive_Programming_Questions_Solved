#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> grafo;
int color[105];

bool bipartido(){
    for(int i = 1; i < n + 1; i++){
        color[i] = -1;
    }
    int s = 1;
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

int main(){ // Mesa da Sra Montagny!
    int t = 1;
    while(cin >> n >> m){
        if(t > 1){
            cout << "\n";
        }

        grafo.assign(n + 1, vector<int>());
        int u, v;
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }

        cout << "Instancia " << t << "\n";
        if(bipartido()){
            cout << "sim";
        }
        else{
            cout << "nao";
        }
        cout << "\n";
        t++;
        grafo.clear();
    }
}