#include<bits/stdc++.h>
using namespace std;

int main(){ // Wrath
	long n;
	cin >> n;
	long guilt[n];
	for(long i = 0; i < n; i++){
		cin >> guilt[i];
	}
	long i = n - 1, j = n - 2, dead = 0;
	while(j >= 0){
		if(j >= i){
			j--;
		}
		else{
			if(j >= i - guilt[i]){
				dead++;
				j--;
			}
			else{
				i--;
			}
		}
	}
	cout << n - dead << endl;
}
