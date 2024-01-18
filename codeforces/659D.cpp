#include<iostream>
using namespace std;

int main(){ // Bicycle Race
	int num, i = 0;
	cin >> num;
	int x0, y0, x1, y1;
	int perigo = 0;
	bool east = false;

	cin >> x0 >> y0;

	while(i < num){
		cin >> x1 >> y1;
		if(x0 < x1){
			east = false;
		}
		else if (x0 > x1){
			east = true;
		}

		if((y0 < y1 && east) || (y0 > y1 && !east) || (y0 > y1 && east) || (y0 < y1 && !east)){
			perigo++; 
			east = false;
		}
		x0 = x1;
		y0 = y1;
		i++;
	}

	cout << perigo - 2 << endl;
}
