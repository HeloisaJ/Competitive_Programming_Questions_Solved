#include<bits/stdc++.h>
using namespace std;

#define MAX 112345678912
vector<map<int, long long>> grafo;
vector<long long> p, d;

void dijkstra(int ini, int fim){
    d.assign(fim + 1, MAX);
    p.assign(fim + 1, -1);
    d[ini] = 0;

    set<pair<long long, int>> q;
    q.insert({0, ini});

    while(!q.empty()){
        int v = q.begin()->second;
        q.erase(q.begin());

        map<int, long long> m = grafo[v];
        for(auto ed: m){
            int to = ed.first;
            long long len = ed.second;

            if(d[v] + len < d[to]){
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

int main(){ // Dijkstra?
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m, x, y;
    long w;
    cin >> n >> m;

    grafo.assign(n + 1, map<int, long long>());
    for(int i = 0; i < m; i++){
        cin >> x >> y >> w;
        if(x != y){
            if(grafo[x].find(y) == grafo[x].end()){
                grafo[x][y] = w;
            }
            else{
                if(grafo[x][y] > w){
                    grafo[x][y] = w;
                }
            }

            if(grafo[y].find(x) == grafo[y].end()){
                grafo[y][x] = w;
            }
            else{
                if(grafo[y][x] > w){
                    grafo[y][x] = w;
                }
            }
        }
    }

    dijkstra(1, n);
    if(p[n] == -1){
        cout << -1 << "\n";
    }
    else{
        vector<int> pat;

        for(int v = n; v != -1; v = p[v]){
            pat.push_back(v);
        }
        reverse(pat.begin(), pat.end());

        for(int i = 0; i < pat.size(); i++){
            cout << pat[i];
            if(i != pat.size() - 1){
                cout << " ";
            }
        }
        cout << "\n";
    }
}