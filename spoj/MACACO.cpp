#include<bits/stdc++.h>
using namespace std;

int main(){ // Macaco-prego
    int n, cont = 1;
    while(cin >> n && n != 0){
        if(cont != 1){
            cout << "\n\n";
        }
        int x, y, u, v, x1, y1, u1, v1;
        cin >> x >> y >> u >> v;
        for(int i = 1; i < n; i++){
            cin >> x1 >> y1 >> u1 >> v1;
            x = max(x1, x);
            y = min(y1, y);
            u = min(u1, u);
            v = max(v1, v);
        }
        cout << "Teste " << cont << "\n";
        if(x <= u && y >= v){
            cout << x << " " << y << " " << u << " " << v;
        }
        else{
            cout << "nenhum";
        }
        cont++;
    }
}