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
	char compare_str[3];
	char * data_dummy;
	bool appears_twice = false;
	int repeating_letter = 0;

	compare_str[2] = '\0';

	while((read = getline(&data_read, &len, fp_data)) != -1){
		data_dummy = data_read;

		//check all the conditions
		while(data_read[current_char] != '\0'){
			//check if sequence appears somewhere else in the string (exclude first char!)
			if((current_char > 0) && (current_char < 14)){
				compare_str[0] = data_read[current_char - 1];
				compare_str[1] = data_read[current_char];

				data_dummy = strstr(data_dummy, compare_str);

				if(strstr(data_dummy + 2, compare_str) != NULL){
					appears_twice = true;
				}
			}

			//check for repeating letter with 1 char between them
			if(current_char < 14){
				if(data_read[current_char] == data_read[current_char + 2]){
					repeating_letter++;
				}
			}
			current_char++;
		}

		//test all conditions
		if(appears_twice && (repeating_letter > 0)){
			nr_nice_strings++;
		}

		current_char = 0;
		repeating_letter = 0;
		appears_twice = false;
	}

	printf("answer=%d\n", nr_nice_strings);

	return EXIT_SUCCESS;
}