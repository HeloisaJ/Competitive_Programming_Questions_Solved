#include<iostream>
using namespace std;

int main(){ // Jumping Mario
	int i = 1, n;
	int nWalls, bef, af;
	int j;
	int h = 0, l = 0;
	cin >> n;
	while(i <= n){
		cin >> nWalls;
		cin >> bef;

		nWalls--;
		j = 0;

		while(j < nWalls){
			cin >> af;
			if(bef > af){
				l++;	
			}
			else if(bef < af){
				h++;
			}

			bef = af;
			j++;
		}

		cout << "Case " << i << ": " << h << " " << l << endl;

		h = 0;
		l = 0;
		i++;
	}
	
	return 0;
}
