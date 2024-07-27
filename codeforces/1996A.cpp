#include<bits/stdc++.h>
using namespace std;

int main(){ // Legs
    int t, n, resp;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        resp = 0;

        if(n >= 4){
            int d = n/4;
            resp += d;
            n -= 4 * d;
        }
        if(n != 0){
            resp++;
            n -= 2;
        }
        cout << resp << "\n";
    }
}