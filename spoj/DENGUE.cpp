#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo;
vector<bool> visited;
pair<int, int> menor; // node, dist
pair<int, int> resp; // node, dist

void dfs(int v, int dist){
    visited[v] = true;

    if(dist > menor.second){
        menor.second = dist;
    }

    if(menor.second > resp.second){
        return;
    }

    for(int i : grafo[v]){
        if(!visited[i]){
            dfs(i, dist + 1);
        }
    }
}

int main(){ // Dengue 
    int n, x, y, t = 1;

    while(cin >> n && n != 0){

        if(t > 1){
            cout << "\n";
        }

        grafo.assign(n + 1, vector<int>());

        for(int i = 0; i < n - 1; i++){
            cin >> x >> y;

            grafo[y].push_back(x);
            grafo[x].push_back(y);
        }

        resp.first = -1;
        resp.second = 112;

        for(int i = 1; i <= n; i++){
            visited.assign(n + 1, false);
            menor.first = i;
            menor.second = -1;
            dfs(i, 0);

            if(menor.second < resp.second){
                resp.second = menor.second;
                resp.first = menor.first;
            }
        }

        cout << "Teste " << t << "\n";
        cout << resp.first << "\n";
        t++;
        grafo.clear();
    }
}