#include<bits/stdc++.h>
using namespace std;

int main(){ // Obtain The String
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        string s, t;
        cin >> s >> t;

        map<char, vector<int>> letras;
        for(int i = 0; i < s.size(); i++){
            letras[s[i]].push_back(i);
        }

        int i = 0, j = 0;
        long long cont = 1;
        while(i < t.size()){
            if(letras.find(t[i]) != letras.end()){
                int pos = lower_bound(letras[t[i]].begin(), letras[t[i]].end(), j) - letras[t[i]].begin();
                if(pos != letras[t[i]].size()){
                    j = letras[t[i]][pos] + 1;
                    i++;
                }
                else {
                    j = 0;
                    cont++;
                }
                if(j == s.size() && i != t.size()){
                    j = 0;
                    cont++;
                }
            }
            else{
                cont = -1;
                break;
            }
        }

        cout << cont << '\n';
    }
}