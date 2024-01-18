#include <stdio.h>
#include <math.h>

int main(){ // Booklet Printing
	int page;
	while(scanf("%d", &page) > 0 && page != 0){
		int howMany;
		int numBlanks = 0;
		int total;
		if(page < 4){
			howMany = round(page/4) + 1;
			numBlanks = 4 - page;
			total = page;
		}
		else if(page % 4 == 0){
			howMany = page/4;
			total = page;
		}
		else{
			numBlanks = 1;
			while((page + numBlanks) % 4 != 0){
				numBlanks++;
			}
			total = page + numBlanks;
			howMany = (total)/4;
		}

		printf("Printing order for %d pages:\n", page);
		int i, cont = 1;
		for(i = 1; i <= howMany; i++){
			if(page < 4){
				printf("Sheet %d, front: Blank, %d\n", i, cont);
				cont++;
				if(numBlanks == 2){
					printf("Sheet %d, back : %d, Blank\n", i, cont);
				}
				else if(numBlanks == 1){
					printf("Sheet %d, back : %d, %d\n", i, cont, total);
				}
				numBlanks = 0;	
			}
			else if(total > page){
				printf("Sheet %d, front: Blank, %d\n", i, cont);
				cont++;
				total--;
				if(numBlanks >= 2){
					printf("Sheet %d, back : %d, Blank\n", i, cont);
					numBlanks -= 2;
					total--;
					cont++;
				}
				else{
					printf("Sheet %d, back : %d, %d\n", i, cont, total);
					numBlanks--;
					cont++;
					total--;
				}
				
			}
			else{
				printf("Sheet %d, front: %d, %d\n", i, total, cont);
				cont++;
				total--;
				printf("Sheet %d, back : %d, %d\n", i, cont, total);
				cont++;
				total--;
			}
			
		}
	}
	return 0;
}
