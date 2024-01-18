#include<bits/stdc++.h>
using namespace std;

int main(){ // Lumberjack Sequencing
    int n;
    cin >> n;
    cout << "Lumberjacks:" << "\n";
    for(int i = 0; i < n; i++){
        int a[10];
        for(int j = 0; j < 10; j++){
            cin >> a[j];
        }
        bool c = true, d = true;
        for(int j = 0; j < 9; j++){
            if(a[j] > a[j + 1]){
                c = false;
            }
        }
        if(c){
            cout << "Ordered" << "\n";
        }
        else{
            for(int j = 0; j < 9; j++){
                if(a[j] < a[j + 1]){
                    d = false;
                }
            }
            if(d){
                cout << "Ordered" << "\n";
            }
            else{
                cout << "Unordered" << "\n";
            }
        }
    }
}