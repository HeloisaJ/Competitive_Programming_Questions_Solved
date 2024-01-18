#include<bits/stdc++.h>
using namespace std;

int main(){ // Fraction
	int n;
	cin >> n;
	int p1, p2 = n - 1;
	int s1, s2;
	bool coprime = true;
	for(p1 = 1; p1 <= n/2; p1++){
		int div = 2;
		while(div < p2){
			if(p1 % div == 0 && p2 % div == 0){
				coprime = false;
			}
			div++;
		}
		if(coprime && p1 < p2){
			s1 = p1;
			s2 = p2;
		}
		p2--;
		coprime = true;
	}

	cout << s1 << " " << s2 << endl;

	return 0;
}
