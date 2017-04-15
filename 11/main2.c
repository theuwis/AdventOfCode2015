#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(void){
	char input[8] = "hepxxzaa";
	bool incr_straight = false, banned_letter = false;
	int amount_sequence = 0;
	char first_pair[1];

	printf("%s\n", input);

	while(1){
		//check for increasing straight
		for(int i = 0; i < 5; i++){
			if((input[i] + 1 == input[i + 1]) && (input[i + 1] + 1 == input[i + 2])){
				incr_straight = true;
				break;
			}
		}

		//check for banned letters
		if((strstr(input, "i") != NULL) || (strstr(input, "o") != NULL) ||
			(strstr(input, "l") != NULL)){
			banned_letter = true;
		}

		//check for sequence
		for(int i = 0; i < 7; i++){
			if(input[i] == input[i + 1]){
				if(amount_sequence == 0){
					amount_sequence++;
					first_pair[0] = input[i];
				}

				else if(input[i] != first_pair[0]){
					amount_sequence++;
				}
			}
		}

		//check if the new password is allowed => if so exit the loop
		if(incr_straight && !banned_letter && (amount_sequence > 1)){
			break;
		}

		//increment the password
		input[7]++;
		for(int i = 7; i > 0; i--){
			if(input[i] == '{'){
				input[i] = 'a';
				input[i - 1]++;
			}
			else{
				break;
			}
		}

		//reset everything for next round
		incr_straight = false;
		banned_letter = false;
		amount_sequence = 0;
	}

	printf("%s\n", input);

	return EXIT_SUCCESS;
}