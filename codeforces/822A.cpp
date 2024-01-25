#include<bits/stdc++.h>
using namespace std;

int main(){ // I'm bored with life
    long long a, b, f, r = 1;
    cin >> a >> b;
    f = min(a, b);
    for(int i = 2; i <= f; i++){
        r *= i;
    }
    cout << r << "\n";
}