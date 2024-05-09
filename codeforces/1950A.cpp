#include<bits/stdc++.h>
using namespace std;

int main(){ // Stair, Peak, or Neither?
    int t, a, b, c;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> a >> b >> c;
        if(a < b && b < c){
            cout << "STAIR";
        }
        else if(a < b && b > c){
            cout << "PEAK";
        }
        else{
            cout << "NONE";
        }
        cout << "\n";
    }
}