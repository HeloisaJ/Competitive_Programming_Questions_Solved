#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> shop;
unsigned long long custo;

int main(){ // Duff and Meat
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    pair<int, int> day;
    int n;
    cin >> n;
    custo = 0;
    for(int i = 0; i < n; i++){
        cin >> day.first >> day.second;
        shop.push_back(day);
    }
    for(int i = 0; i < n; i++){
        if(i != n - 1 && shop[i].second < shop[i + 1].second){
            custo += shop[i].second * shop[i].first;
            int save = i;
            for(i = i; i < n - 1 && shop[save].second < shop[i + 1].second; i++){
                custo += shop[save].second * shop[i + 1].first;
            }
        }
        else{
            custo += shop[i].second * shop[i].first;
        }
    }
    cout << custo << "\n";
}