#include<bits/stdc++.h>
using namespace std;

int seq[26];

int main(){ // Minimize Ordering
    string s;
    cin >> s;
    memset(seq, 0, sizeof(seq));
    for(int i = 0; i < s.size(); i++){
        seq[s[i] - 97]++;
    }
    for(int i = 0; i < 26; i++){
        while(seq[i] > 0){
            cout << char('a' + i);
            seq[i]--;
        }
    }
    cout << "\n";
}