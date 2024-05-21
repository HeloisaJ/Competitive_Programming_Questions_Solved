#include<bits/stdc++.h>
using namespace std;

int main(){ // Missing Number
    int n, x, cont = 1;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n - 1; i++){
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        if(v[i] == cont){
            cont++;
        }
        else{
            cout << cont << "\n";
            break;
        }
    }
}