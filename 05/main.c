#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void){
	//start parsing the data
	FILE * fp_data;
	fp_data = fopen("data", "r");
	char * data_read = NULL;
	size_t len = 0;
	ssize_t read;

	int current_char = 0, nr_nice_strings = 0;
	int nr_vowels = 0;
	bool twice_row = false, banned_string = false;


	while((read = getline(&data_read, &len, fp_data)) != -1){
		//check all the conditions
		while(data_read[current_char] != '\0'){
			//count amount of vowels
			if((data_read[current_char] == 'a') || (data_read[current_char] == 'e') || 
				(data_read[current_char] == 'i') || (data_read[current_char] == 'o') || 
				(data_read[current_char] == 'u')){
				nr_vowels++;
			}

			//check if letter twice in a row (exclude first char!)
			if((current_char > 0) && (data_read[current_char] == data_read[current_char - 1])){
				twice_row = true;
			}
			
			current_char++;
		}

		//check for bad strings
		if((strstr(data_read, "ab") != NULL) || (strstr(data_read, "cd") != NULL) || 
			(strstr(data_read, "pq") != NULL) || (strstr(data_read, "xy") != NULL)){
			banned_string = true;
		}

		//test all conditions
		if((nr_vowels >= 3) && twice_row && !banned_string){
			nr_nice_strings++;
		}

		nr_vowels = 0;
		current_char = 0;
		twice_row = false;
		banned_string = false;
	}

	printf("answer=%d\n", nr_nice_strings);

	return EXIT_SUCCESS;
}