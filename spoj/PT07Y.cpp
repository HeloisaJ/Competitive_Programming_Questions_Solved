#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> arv;
vector<int> visited;

bool ciclo;
int contN, n, m;

void dfs(int v, int p){
    if(ciclo){
        return;
    }
    visited[v] = 0;
    contN++;

    for(int to : arv[v]){
        
        if(to == p){
            continue;
        }
        else if(visited[to] == 0){
            ciclo = true;
            return;
        }
        else{
            dfs(to, v);
            if(ciclo){
                return;
            }
        }
    }

    visited[v] = 1;
}

int main(){ // Is it a tree
    int x, y;
    cin >> n >> m;

    arv.assign(n + 1, vector<int>());
    for(int i = 0; i < m; i++){
        cin >> x >> y;

        arv[x].push_back(y);
        arv[y].push_back(x);
    }

    contN = 0;
    ciclo = false;
    visited.assign(n + 1, -1);
    dfs(1, -1);

    if(!ciclo && contN == n){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    cout << "\n";
}