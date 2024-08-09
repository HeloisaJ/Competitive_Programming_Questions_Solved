#include<bits/stdc++.h>
using namespace std;

#define MAX 10000

int n, cont;
vector<pair<int, int>> pontos;
vector<vector<int>> grafo;
vector<bool> visited;
long long mat [1123][1123];

void calculoDfs(int v){
    cont++;
    visited[v] = true;

    for(int u: grafo[v]){
        if(!visited[u]){
            calculoDfs(u);
        }
    }
}

long long distEntreDoisP(int i, int j){
    long long p1 = pontos[i].first - pontos[j].first, p2 = pontos[i].second - pontos[j].second;
    return p1 * p1 + p2 * p2;
}

bool verificar(int i, int j){
    if(i == -1){
        return false;
    }
    if(pontos[j].first < pontos[i].first){
        return true;
    }
    else if(pontos[j].second < pontos[i].second){
        return true;
    }
    return false;
}

void definirArestas(){
    long long dist;

    for(int i = 0; i < n; i++){
        mat[i][i] = MAX;
        for(int j = i + 1; j < n; j++){
            dist = distEntreDoisP(i, j);
            mat[i][j] = dist;
            mat[j][i] = dist;
        }
    }

    long long m1, m2; 
    int p1, p2;
    for(int i = 0; i < n; i++){
        m1 = MAX;
        m2 = MAX;
        p1 = -1;
        p2 = -1;
        for(int j = 0; j < n; j++){
            if((mat[i][j] < m1 || (m1 == mat[i][j] && verificar(p1, j))) && i != j){
                if(m1 != MAX && m1 < m2){
                    m2 = m1;
                    p2 = p1;
                }
                m1 = mat[i][j];
                p1 = j;
            }
            else if((mat[i][j] < m2 || (m2 == mat[i][j] && verificar(p2, j))) && i != j){
                m2 = mat[i][j];
                p2 = j;
            }
        }
        if(m1 != MAX){
            grafo[i].push_back(p1);
        }
        if(m2 != MAX){
            grafo[i].push_back(p2);
        }
    }
}

int main(){ // Monitorando a Amazônia
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int xi, yi;
    while(cin >> n && n != 0){
        for(int i = 0; i < n; i++){
            cin >> xi >> yi;
            pontos.push_back(make_pair(xi, yi));
        }

        grafo.assign(n, vector<int>());
        visited.assign(n, false);

        definirArestas();
        cont = 0;
        calculoDfs(0);

        if(cont == n){
            cout << "All stations are reachable.";
        }
        else{
            cout << "There are stations that are unreachable.";
        }
        cout << "\n";

        pontos.clear();
    }
}