#include<iostream>
using namespace std;

int main(){ // Fatorial

	int N;
	cin >> N;
	int res = 1;
	while(N > 0){
		res = N * res;
		N--;
	}
	cout << res << endl;
	return 0;
}
