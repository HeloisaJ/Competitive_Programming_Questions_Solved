#include<bits/stdc++.h>
using namespace std;

int main(){ // The Decoder
    string s;
    while(getline(cin, s)){
        for(int i = 0; i < s.size(); i++){
            cout << char(s[i] - 7);
        }
        cout << "\n";
    }
}