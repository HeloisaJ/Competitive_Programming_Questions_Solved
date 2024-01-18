#include<bits/stdc++.h>
using namespace std;

vector<int> num;
int pL, pR;

int comparar(int score){
	if(num[pL] > num[pR]){
		score += num[pL];
		pL++;
	}
	else{
		score += num[pR];
		pR--;
	}
	return score;
}

int main(){ // Sereja and Dima
	int n, x;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		num.push_back(x);
	}
	pL = 0; 
	pR = n - 1;
	int s = 0, d = 0, cont = 1;
	while(pL <= pR){
		if(cont % 2 == 0){
			d = comparar(d);
		}
		else{
			s = comparar(s);
		}
		cont++;
	}
	cout << s << " " << d << endl;
}
