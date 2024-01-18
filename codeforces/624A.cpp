#include<iostream>
#include<iomanip>
using namespace std;

int main(){ // Save Luke
	int D, L2, V1, V2;
	int L1 = 0;
	double res = 0;
	int cont = 0;

	cin >> D >> L2;
	cin >> V1 >> V2;

	while((L2 - V2) - (L1 + V1) >= D){
		L1 += V1;
		L2 -= V2;
		cont++;
	}

	if(L2 - L1 > D){
		res = (double)(L2 - L1 - D)/(V1 + V2);
	}

	res += (double) cont;

	cout << setprecision(20) << res << endl;

	return 0;
}
