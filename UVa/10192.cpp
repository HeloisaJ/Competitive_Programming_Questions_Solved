#include<bits/stdc++.h>
using namespace std;

map<char, int> letrasM;
map<char, int> letrasP;

int LCS (string a, string b, int m, int n){
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
                if(L[i - 1][j] > L[i][j - 1]){
                    L[i][j] = L[i - 1][j];
                }
                else{
                    L[i][j] = L[i][j - 1];
                }
            }
        }
    }

    return L[m][n];
}

int main(){ // Vacation
    string m, p;
    int t = 1;
    while(getline(cin, m) && m != "#"){
        getline(cin, p);

        int resp = LCS(m, p, m.size(), p.size());

        cout << "Case #" << t << ": you can visit at most ";
        cout << resp << " cities.\n";
        t++;
    }
}