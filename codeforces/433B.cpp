#include<bits/stdc++.h>
using namespace std;

#define MAX 112345

long long pedras[MAX];
long long pedrasOrd[MAX];
long long prefU[MAX];
long long prefO[MAX];

int main(){ // Kuriyama Mirai's Stones
    int n, m;
    cin >> n;
    prefU[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> pedras[i - 1];
        prefU[i] = prefU[i - 1] + pedras[i - 1];
        pedrasOrd[i - 1] = pedras[i - 1];
    }
    sort(pedrasOrd, pedrasOrd + n);
    prefO[0] = 0;
    for(int i = 1; i <= n; i++){
        prefO[i] = prefO[i - 1] + pedrasOrd[i - 1];
    }
    cin >> m;
    int t, l, r;
    for(int i = 0; i < m; i++){
        cin >> t >> l >> r;
        l--;
        if(t == 1){
            cout << (prefU[r] - prefU[l]);
        }
        else{
            cout << (prefO[r] - prefO[l]);
        }
        cout << "\n";
    }
}