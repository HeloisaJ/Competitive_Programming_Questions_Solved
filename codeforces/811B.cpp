#include<bits/stdc++.h>
using namespace std;

int main(){ // Vladik and Complicated Book
	int n, m;
	int li, xi, ri;
	cin >> n >> m;
	int P[n];
	for(int i = 0; i < n; i++){
		cin >> P[i];	
	}
	for(int i = 0; i < m; i++){
		cin >> li >> ri >> xi;
		int menor = 0;
		for(int j = li - 1; j < ri; j++){
			if(P[j] < P[xi - 1]){
				menor++;
			}
		}
		if(li + menor != xi){
			cout << "No" << endl;
		}
		else{
			cout << "Yes" << endl;
		}
	}
}
