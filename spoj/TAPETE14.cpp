#include<iostream>
using namespace std;

int main(){ // Tapetes
	int L, N;
	cin >> L >> N;
	int maior;
	long long int area;
	maior = L - (N - 1);
	area = (long long int) maior * maior + N - 1;
	cout << area << endl;
	return 0;
}
