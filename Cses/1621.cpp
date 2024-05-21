#include<bits/stdc++.h>
using namespace std;

int main(){ // Distinct Numbers
    set<long> valores;
    long n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        valores.insert(x);
    }
    cout << valores.size() << "\n";
}