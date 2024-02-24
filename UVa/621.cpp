#include<bits/stdc++.h>
using namespace std;

string s;

int main(){ // Secret Research
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        cin >> s;
        if(s == "78" || s == "4" || s == "1"){
            cout << '+' << "\n";
        }
        else if(s[s.size() - 1] == '5' && s[s.size() - 2] == '3'){
            cout << '-' << "\n";
        }
        else if(s[0] == '9'){
            cout << '*' << "\n";
        }
        else{
            cout << '?' << "\n";
        }
    }
}