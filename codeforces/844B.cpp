#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[51][51];

unsigned long long power(int x){
    unsigned long long res = 1;
    for(int i = 0; i < x; i++){
        res *= 2;
    }
    return res;
}

int main(){ // Rectangles
    cin >> n >> m;
    unsigned long long cont, total = 0;
    for(int i = 0; i < n; i++){
        cont = 0;
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j]){
                cont++;
            }
        }
        total += power(cont) -1;
        total += power(m - cont) -1;
    }

    for(int i = 0; i < m; i++){
        cont = 0;
        for(int j = 0; j < n; j++){
            if(a[j][i]){
                cont++;
            }
        }
        total += power(cont) -1;
        total += power(n - cont) -1;
    }
    total -= n * m;
    cout << total << "\n";
}