#include<cstdio>
#include<math.h>
using namespace std;

int main(){ // Selos
	long long int N;
	scanf("%lld", &N);
	long long int div = 2;
	char res = 'N';

	int half = sqrt(N);
	while(div <= half){
		if(N % div == 0){
			res = 'S';
			break;
		}
		div++;
	}
	printf("%c\n", res);
	return 0;
}
