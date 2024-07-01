#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo;

vector<bool> visited;
vector<int> tin, low;
int timer, p, c;
bool bridge;

void calculoDfs(int v, int p = -1){
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for(int to : grafo[v]){
        if(to == p){
            continue;
        }
        if(visited[to]){
            low[v] = min(low[v], tin[to]);
        }
        else{
            calculoDfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v]){
                bridge = true;
            }
        }
    }
}

void find_bridges(){
    timer = 0;
    visited.assign(p, false);
    tin.assign(p, -1);
    low.assign(p, -1);
    for(int i = 0; i < p; i++){
        if(!visited[i]){
            calculoDfs(i);
        }
    }
}

int main(){ // Birthday Party
    int x, y;
    while(cin >> p >> c && p != 0 && c != 0){
        grafo.assign(p, vector<int>());
        for(int i = 0; i < c; i++){
            cin >> x >> y;
            grafo[x].push_back(y);
            grafo[y].push_back(x);
        }
        bridge = false;
        find_bridges();
        if(bridge){
            cout << "Yes";
        }
        else{
            cout << "No";
        }
        cout << "\n";
        grafo.clear();
    }
}