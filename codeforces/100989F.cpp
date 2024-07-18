#include<bits/stdc++.h>
using namespace std;

map<int, int> students; // student, place
map<int, int> places; // place, quantStudent

int main(){ // Mission in Amman (A)
    int n, m, q, covered = 0;
    cin >> n >> m >> q;

    for(int i = 0; i < m; i++){
        places.insert(make_pair(i + 1, 0));
    }

    int initialPos;
    for(int i = 0; i < n; i++){
        cin >> initialPos;
        students.insert(make_pair(i + 1, initialPos));
        places[initialPos]++;

        if(places[initialPos] == 1){
            covered++;
        }
    }

    int a, b;
    for(int i = 0; i < q; i++){
        cin >> a >> b;

        initialPos = students[a];
        if(places[initialPos] == 1){
            covered--;
        }
        places[initialPos]--;

        students[a] = b;
        if(places[b] == 0){
            covered++;
        }
        places[b]++;

        cout << (m - covered) << "\n";
    }
}