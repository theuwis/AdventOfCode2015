#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NR_ELEMENTS 20
#define LITERS_TO_STORE 150

int main(void){
	int input[NR_ELEMENTS] = {50, 44, 11, 49, 42, 46, 18, 32, 26, 40, 21, 7, 18, 43, 10, 47, 36, 24, 22, 40};
	int multiplier[NR_ELEMENTS] = {0};
	int nr_combinations = 0, result = 0;

	//generate a list to check all possible solutions
	//it uses the multiplier, which can have a value of either 0 or 1
	//example when the multiplier is {1, 1, 0, 0}
	//  1*(20l) + 1*(15l) + 0*(5l) + 0*(5l)
	for(int i = 0; i < pow(2, NR_ELEMENTS); i++){
		for(int j = 0; j < NR_ELEMENTS; j++){
			multiplier[NR_ELEMENTS - 1 - j] = (i >> (NR_ELEMENTS - 1 -j)) & 1;
		}

		//calculate the result of the used jars
		for(int k = 0; k < NR_ELEMENTS; k++){
			result += input[k] * multiplier[k];
		}

		//test if the result is the correct amount
		if(result == LITERS_TO_STORE){
			nr_combinations++;
		}

		result = 0;
	}

	printf("answer=%d\n", nr_combinations);

	return EXIT_SUCCESS;
}