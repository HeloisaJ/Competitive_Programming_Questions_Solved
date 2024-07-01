#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> grafo;
bool visited[1123][1123];
int contSalas, n, m;
int dx[]{1, 0, -1, 0}, dy[]{0, 1, 0, -1};

bool verificar(int ip, int jp){
    if(ip < 0 || jp < 0 || ip >= n || jp >= m){
        return false;
    }
    if(grafo[ip][jp] == '#'){
        return false;
    }
    return true;
}

void calculoDfs(int i, int j){
    visited[i][j] = true;
    for(int p = 0; p < 4; p++){
        int ip = i + dx[p], jp = j + dy[p];
        if(verificar(ip, jp) && !visited[ip][jp]){
            calculoDfs(ip, jp);
        }
    }
}

int main(){ // Counting Rooms
    cin >> n >> m;
    grafo.assign(n, vector<char>(m, '0'));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grafo[i][j];
            if(grafo[i][j] == '#'){
                visited[i][j] = true;
            }
            else{
                visited[i][j] = false;
            }
        }
    }
    contSalas = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j]){
                calculoDfs(i, j);
                contSalas++;
            }
        }
    }
    cout << contSalas << "\n";
}