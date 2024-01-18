#include<bits/stdc++.h>
using namespace std;

int main(){ // Bingo
	int n, b;
	while(cin >> n >> b && n != 0 && b != 0){
		int arr[n];
		for(int i = 0; i < b; i++){
			cin >> arr[i];
		}
		if(n == b - 1){
			cout << 'Y' << endl;
		}
		else{
			int pres[n + 1];
			for(int i = 0; i < b; i++){
				for(int j = 0; j < b; j++){
					pres[abs(arr[i] - arr[j])] = 1;
				}
			}
			int conf = 1;
			for(int i = 0; i < n + 1; i++){
				if(pres[i] != 1){
					conf = 0;	
				}
			}
			if(conf == 1){
				cout << 'Y' << endl;
			}
			else{
				cout << 'N' << endl;
			}
		}
	}
	return 0;
}
