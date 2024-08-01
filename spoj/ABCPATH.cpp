#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> quantA;
char mat[51][51];
bool visited[51][51];
int h, w, maior;
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};

bool valido(int i, int j){
    if(i >= 0 && i < h && j >= 0 && j < w){
        return true;
    }
    return false;
}

void calculoDfs(int i, int j, int cont){
    visited[i][j] = true;
    int x, y;
    if(cont > maior){
        maior = cont;
    }
    for(int k = 0; k < 8; k++){
        x = i + dx[k];
        y = j + dy[k];
        if(valido(x, y) && mat[i][j] + 1 == mat[x][y] && !visited[x][y]){
            calculoDfs(x, y, cont + 1);
        }
    }
}

int main(){ // ABC Path
    int t = 1;
    while(cin >> h >> w && h != 0 && w != 0){
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> mat[i][j];
                if(mat[i][j] == 'A'){
                    quantA.push_back(make_pair(i, j));
                }
                visited[i][j] = false;
            }
        }

        maior = 0;
        for(int i = 0; i < quantA.size(); i++){
            calculoDfs(quantA[i].first, quantA[i].second, 1);
        }
        cout << "Case " << t << ": ";
        cout << maior << "\n";
        quantA.clear();
        t++;
    }
}