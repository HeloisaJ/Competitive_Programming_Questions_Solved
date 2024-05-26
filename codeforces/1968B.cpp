#include<bits/stdc++.h>
using namespace std;

int main(){ // Prefiquence
    string a, b;
    int t, n, m;
    cin >> t;
    for(int k = 0; k < t; k++){
        cin >> n >> m >> a >> b;
        int i = 0, j = 0, cont = 0; // i -> a, j -> b
        while(i < n && j < m){
            if(a[i] == b[j]){
                i++;
                cont++;
            }
            j++;
        }
        cout << cont << "\n";
    }
}