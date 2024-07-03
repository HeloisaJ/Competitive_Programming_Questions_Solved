#include <bits/stdc++.h>
using namespace std;
 
int mx;
bool possible;
int m;
 
void distribution(map<string, int> x, vector<pair<string, string>> s, int pos) {
    if(possible == true){
        return;
    }
    if (pos == m) {
        possible = true;
        return;
    }
    if (x[s[pos].first] < mx) {
        x[s[pos].first]++;
        distribution(x, s, pos + 1);
        x[s[pos].first]--;
    }
    if(x[s[pos].second] < mx){
        x[s[pos].second]++;
        distribution(x, s, pos + 1);
        x[s[pos].second]--;
    }
}
 
int main() { // My T-shirt suits me
    int t, n;
 
    cin >> t;
 
    while (t--) {
        cin >> n >> m;
        mx = n/6;
        possible = false;
        map<string, int> x;
        vector<pair<string, string>> s;
 
        string sz1, sz2;
 
        for (int i = 0; i < m; i++) {
            cin >> sz1 >> sz2;
            if (x.find(sz1) == x.end()) {
                x.insert(make_pair(sz1, 0));
            }
            if (x.find(sz2) == x.end()) {
                x.insert(make_pair(sz2, 0));
            }
            s.push_back(make_pair(sz1, sz2));
        }
        int pos = 0;
        distribution(x, s, pos);
        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
 
    return 0;
}