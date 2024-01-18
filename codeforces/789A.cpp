#include<iostream>
using namespace std;

int main(){ // Anastasia and pebbles
	int n, k;
	cin >> n >> k;
	int* allPebbles = new int [n];
	int i, num = 0;
	int dias = 0;
	int cheio = 0;

	for(i = 0; i < n; i++){
		cin >> allPebbles[i];
		num += allPebbles[i];
	}

	i = 0;
	while(num != 0){
		if(k * 2 < allPebbles[i]){
			num -= k * 2;
			allPebbles[i] += - k * 2;
			dias++;
		}
		else if(allPebbles[i] == k * 2){
			num -= allPebbles[i];
			dias++;
			i++;
		}
		else{
			if(allPebbles[i] > k){
				num -= allPebbles[i];
				allPebbles[i] = 0;
				dias++;
			}
			else{
				num -= allPebbles[i];
				allPebbles[i] = 0;
				cheio++;
				if(cheio != 2){
					dias++;
				}
				else{
					cheio = 0;
				}
			}
			i++;
		}
		
	}

	cout << dias << endl;

	return 0;
}
