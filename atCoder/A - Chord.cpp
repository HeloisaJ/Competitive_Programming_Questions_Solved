#include<bits/stdc++.h>
using namespace std;

int main(){ // Chord
    string s;
    cin >> s;
    if(s == "ACE" || s == "BDF" || s == "CEG" || s == "DFA" || s == "EGB" || s == "FAC" || s == "GBD"){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }
}