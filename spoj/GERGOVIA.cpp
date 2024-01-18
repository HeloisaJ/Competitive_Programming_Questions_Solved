#include<bits/stdc++.h>
using namespace std;

int main(){ // Wine trading in Gergovia
	long n, wo, sum, x;
	while(cin >> n && n != 0){
		wo = 0;
		sum = 0;
		for(int i = 0; i < n; i++){
			cin >> x;
			sum += x;
			wo += abs(sum);
		}
		cout << wo << endl;
	}
}
