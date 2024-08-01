#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int m, int n){
    int dp[m + 1][n + 1];
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(a[i - 1] == b [j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main(){ // Longest Common Subsequence
    string s1, s2;
    while(getline(cin, s1)){
        getline(cin, s2);

        cout << LCS(s1, s2, s1.size(), s2.size()) << "\n";
    }
}