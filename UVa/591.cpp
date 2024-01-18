#include<bits/stdc++.h>
using namespace std;

int main(){ // Box of Bricks
    int n, cont = 1;
    while(cin >> n && n != 0){
        int h[n];
        int total = 0;
        for(int i = 0; i < n; i++){
            cin >> h[i];
            total += h[i];
        }
        int hight = total/n;
        int mov = 0, i = 0;
        sort(h, h + n);
        while(hight - h[i] > 0){
            mov += hight - h[i];
            i++;
        }
        cout << "Set #" << cont << endl;
        cout << "The minimum number of moves is " << mov << "." << endl;
        cout << endl;
        cont++;
    }
}