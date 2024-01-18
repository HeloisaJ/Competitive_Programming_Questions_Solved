#include<bits/stdc++.h>
using namespace std;

int main(){ // Dragons
	long s;
	int n;
	cin >> s >> n;
	vector<pair<int, int>> d;
	pair<int, int> x;
	for(int i = 0; i < n; i++){
		cin >> x.first >> x.second;
		d.push_back(x);
	}
	sort(d.begin(), d.end());
	string resp = "YES";
	for(int i = 0; i < n; i++){
		if(s > d[i].first){
			s += d[i].second;
		}
		else{
			resp = "NO";
			break;
		}
	}
	cout << resp << endl;
}
