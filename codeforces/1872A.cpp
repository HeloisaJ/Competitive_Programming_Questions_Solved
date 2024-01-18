#include<bits/stdc++.h>
using namespace std;

int main(){ // Two Vessels
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int a, b, c, t;
    double sum, nc = 0;
    cin >> t;
    for(int x = 0; x < t; x++){
        nc = 0;
        cin >> a >> b >> c;
        if(a != b){
            sum = (a + b)/2.0;
            if(a > b){
                sum = a - sum;
            }
            else {
                sum = b - sum;
            }
            nc = sum/c;
            nc = ceil(nc);
        }
        cout << nc << endl;
    }
}