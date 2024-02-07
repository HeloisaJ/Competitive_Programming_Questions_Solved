#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> h;

int main(){ // Before an Exam
    int d, minimo = 0, maximo = 0, s, x1, x2;
    cin >> d >> s;
    for(int i = 0; i < d; i++){
        cin >> x1 >> x2;
        h.push_back(make_pair(x1, x2));
        minimo += x1;
        maximo += x2;
    }
    if(s < minimo || s > maximo){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES" << "\n";
        if(s == minimo){
            for(int i = 0; i < d; i++){
                cout << h[i].first;
                if(i != d - 1){
                    cout << " ";
                }
            }
        }
        else if(s == maximo){
            for(int i = 0; i < d; i++){
                cout << h[i].second;
                if(i != d - 1){
                    cout << " ";
                }
            }
        }
        else{
            int total = minimo, dif;
            for(int i = 0; i < d; i++){
                dif = h[i].second - h[i].first;
                while(total + dif > s && dif > 0){
                    dif--;
                }
                total += dif;
                cout << h[i].first + dif;
                if(i != d - 1){
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }
}