#include<iostream>
using namespace std;

int main(){ // Nearly Lucky Number
	long long int num;
	cin >> num;
	int lucky = 0;
	while(num > 0){
		if(num % 10 == 7 || num % 10 == 4){
			lucky++;
		}
		num = num/10;
	}

	if(lucky == 7 || lucky == 4){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
	return 0;
}
