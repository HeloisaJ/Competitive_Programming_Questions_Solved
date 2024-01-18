#include<iostream>
using namespace std;

int main(){ // Soft Drinking
	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	int t1, t2, t3;
	t1 = (k * l)/nl;
	t2 = c * d;
	t3 = p/np;
	if(t1 < t2 && t1 < t3){
		cout << t1/n << endl;
	}
	else if(t2 < t1 && t2 < t3){
		cout << t2/n << endl;
	}
	else{
		cout << t3/n << endl;
	}
	
	return 0;
}
