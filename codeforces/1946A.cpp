#include<bits/stdc++.h>
using namespace std;

vector<long> v;

int main(){ // Median of an Array
    int t, n, x;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        n--;
        int meio = n/2, posMaior;
        posMaior = upper_bound(v.begin(), v.end(), v[meio]) - v.begin();
        cout << posMaior - meio << "\n";
        v.clear();
    }
}