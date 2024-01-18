#include<iostream>
using namespace std;

int main(){ // Cumulative Sum Query
	int k, N, Q;
	cin >> N;
	int list[N];

	for(k = 0; k < N; k++){
		cin >> list[k]; 
	}

	cin >> Q;
	int i, j;
	int l = 0;
	int sum = 0;

	while(l != Q){
		cin >> i >> j;
		while(i <= j){
			sum = sum + list[i];
			i++;
		}
		cout << sum << endl;
		sum = 0;
		l++;
	}

	return 0;
}
