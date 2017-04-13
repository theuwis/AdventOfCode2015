#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE_GRID 100
#define NR_OF_TIMES 100

//grid is taken larger for edge cases
bool lights[SIZE_GRID + 2][SIZE_GRID + 2] = {false};
bool dummy[SIZE_GRID + 2][SIZE_GRID + 2] = {false};

int main(void){
	//start parsing the data
	FILE * fp_data;
	fp_data = fopen("data", "r");
	char * data_read = NULL;
	size_t len = 0;
	ssize_t read;
	int x_coord = 1, y_coord = 1;
	int nr_neighbours = 0, nr_lights_on = 0;

	//initialize the lights
	while((read = getline(&data_read, &len, fp_data)) != -1){
		while(y_coord < SIZE_GRID + 1){
			if(data_read[y_coord - 1] == '#'){
				lights[x_coord][y_coord] = true;
			}
			else{
				lights[x_coord][y_coord] = false;
			}
			y_coord++;
		}
		y_coord = 1;
		x_coord++;
	}

	//repeat the algo x times
	for(int times = 0; times < NR_OF_TIMES; times++){
		//make a copy in dummy
		for(int i = 1; i < SIZE_GRID + 1; i++){
			for(int j = 1; j < SIZE_GRID + 1; j++){
				dummy[i][j] = lights[i][j];
			}
		}

		for(int i = 1; i < SIZE_GRID + 1; i++){
			for(int j = 1; j < SIZE_GRID + 1; j++){
				//count amount of neighbours
				for(int k = -1; k < 2; k++){
					for(int l = -1; l < 2; l++){
						if(dummy[i + k][j + l]){
							nr_neighbours++;
						}
					}
				}
				//the light doens't count if is on itself
				if(dummy[i][j]) nr_neighbours--;

				if(dummy[i][j]){
					//turn OFF if it was on and no 2 or 3 neighbours
					if((nr_neighbours != 2) && (nr_neighbours != 3)){
						lights[i][j] = false;
					}
				}
				else{
					//turn ON if 3 neighbours
					if(nr_neighbours == 3){
						lights[i][j] = true;
					}
				}

				nr_neighbours = 0;
			}
		}
	}

	for(int i = 1; i < SIZE_GRID + 1; i++){
		for(int j = 1; j < SIZE_GRID + 1; j++){
			if(lights[i][j]) nr_lights_on++;
		}
	}

	printf("answer=%d\n", nr_lights_on);

	return EXIT_SUCCESS;
}