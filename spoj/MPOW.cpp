#include<bits/stdc++.h>
using namespace std;
#define vll vector<unsigned long long>
#define modulo 1000000007

vector<vll> ident(int al){
    vector<vll> c;
    c.assign(al, vll(al, 0));
    for(int i = 0; i < al; i++){
        c[i][i] = 1;
    }
    return c;
}

vector<vll> mult(vector<vll> a, vector<vll> b){
    vector<vll> c;
    c.assign(a.size(), vll(a.size(), 0));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a.size(); j++){
            for(int k = 0; k < a.size(); k++){
                c[i][j] = (c[i][j] + ((a[i][k] % modulo) * (b[k][j] % modulo)) % modulo) % modulo;
            }
        }
    }
    return c;
}

vector<vll> matrixExp(vector<vll> a, int n){ 
    if(n == 0){
        return ident(a.size());
    }
    vector<vll> c = matrixExp(a, n/2);
    c = mult(c, c);
    if(n % 2 != 0) c = mult(c, a);
    return c;
}

int main(){ // Power of matrix
    vector<vll> matrix;
    int t, m, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> m >> n;
        matrix.assign(m, vll(m, 0));
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++){
                cin >> matrix[j][k];
            }
        }
        matrix = matrixExp(matrix, n);
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++){
                cout << matrix[j][k] % 1000000007;
                if(k != m - 1){
                    cout << " ";
                }
            }
            cout << "\n";
        }
        matrix.clear();
    }
}