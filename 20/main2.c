
#include <stdio.h>
#include <stdlib.h>

int main(void){
	long house_nr = 0, nr_presents = 0;

	while(1){
		//find all factors of the house nr
		for(long i = 1; i <= house_nr; i++){
			//each elf only delivers to 50 houses
			if((house_nr%i == 0) && (house_nr / i < 50)){	
					//update amount of presents delivered to the house
					nr_presents += i * 11;
			}
		}

		//found correct house?
		if(nr_presents >= 33100000){
			printf("answer=%ld\n", house_nr);
			break;
		}

		if(house_nr%10000 == 0)
			printf("%ld - %ld\n", house_nr, nr_presents);
		house_nr++;
		nr_presents = 0;
	}

	return EXIT_SUCCESS;
}
