#include<bits/stdc++.h>
using namespace std;

int main(){ // TV da Vovó
    int n, m, cont = 1;
    while(cin >> m >> n && m != 0){
        int mat[m][n];
        int certo[m][n];
        if(cont > 1){
            cout << "\n";
            cout << "\n";
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        int sx = 0, sy = 0, x, y;
        while(cin >> x >> y){
            if(x == 0 && y == 0){
                break;
            }
            sx += x;
            sy += y;
        }
        int vx, vy;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                vx = j + sx;
                vy = i - sy;
                while(vx >= n){
                    vx -= n;
                }
                while(vx < 0){
                    vx += n;
                }
                while(vy >= m){
                    vy -= m;
                }
                while(vy < 0){
                    vy += m;
                }
                certo[vy][vx] = mat[i][j];
            }
        }
        cout << "Teste " << cont << "\n";
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cout << certo[i][j];
                if(j != n - 1){
                    cout << " ";
                }
            }
            if(i != m - 1){
                cout << "\n";
            }
        }
        cont++;
    }
}