#include<iostream>
using namespace std;

int main(){ // A and B and Team Training
	int n, m;
	cin >> n >> m;
	int cont = 0;
	while(n > 0 && m > 0){
		if(n <= m && n >= 1 && m >= 2){
			n--;
			m -= 2;
			cont++;
		}
		else if(m < n && m >= 1 && n >= 2){
			n -= 2;
			m--;
			cont++;
		}
		else{
			break;
		}
	}
	cout << cont << endl;
	return 0;
}
