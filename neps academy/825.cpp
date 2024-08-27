#include<bits/stdc++.h>
using namespace std;

char mat[512][512];
int n, f;
bool vis[512][512];
int dx[]{1,0,-1,0}, dy[]{0,1,0,-1};

bool verificar(int i, int j){
    if(i >= 0 && i < n && j >= 0 && j < n){
        return true;
    }
    return false;
}

void calculoDfs(int i, int j){
    vis[i][j] = true;

    if(f < mat[i][j] - 48){
        return;
    }
    else{
        mat[i][j] = '*';
    }

    int dix, diy;
    for(int k = 0; k < 4; k++){
        dix = dx[k] + i;
        diy = dy[k] + j;

        if(verificar(dix, diy) && !vis[dix][diy]){
            calculoDfs(dix, diy);
        }
    }
}

int main(){ // Fissura Perigosa
    cin >> n >> f;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
            vis[i][j] = false;
        }
    }

    calculoDfs(0, 0);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mat[i][j];
        }
        cout << "\n";
    }
}