#include<bits/stdc++.h>
using namespace std;

int a[1123];
int b[1123];

int LCS(int m, int n){ // Maior Ancestral Comum
    int L[m + 1][n + 1];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                L[i][j] = 0;
            }
            else if(a[i - 1] == b[j - 1]){
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else{
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    return L[m][n];
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    int resp = LCS(n, m);
    cout << n - resp << " " << m - resp << "\n";
}