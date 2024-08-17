#include<bits/stdc++.h>
using namespace std;

int t, n, contAsc;
vector<int> menor, maior;

int main(){ // New Year and Ascent Sequence
    int me, m, x;
    bool asc;
    contAsc = 0;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        asc = false;
        me = 1123456;
        m = 0;
        for(int j = 0; j < n; j++){
            cin >> x;
            if(x < me){
                me = x;
            }
            if(x > me){
                asc = true;
            }

            if(x > m){
                m = x;
            }
        }

        if(asc){
            contAsc++;
        }
        else{
            menor.push_back(me);
            maior.push_back(m);
        }
    }

    long long res = 0;
    for(int j = 0; j < contAsc; j++){
        res += (t - j) + (t - j) - 1; 
    }

    sort(menor.begin(), menor.end());
    sort(maior.begin(), maior.end());

    int pos;
    for(int j = 0; j < menor.size(); j++){
        pos = upper_bound(maior.begin(), maior.end(), menor[j]) - maior.begin();
        res += menor.size() - pos;
    }

    cout << res << "\n";
}