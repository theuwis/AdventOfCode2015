#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool checks[3] = {false, false, true}; //3 vowels, letter twice, not string ab...
int counter = 0, vowel_counter = 0, nice_strings = 0;
char c = 'a', data[100];

int main() {
   FILE * fp_data;
   fp_data = fopen("data", "r");

   //TODO fout in de while loop ==> wilt niet printen op het einde (antwoord is 258 btw)
   while(1){
      counter = 0;
      while( ((c = fgetc(fp_data)) != '\n') ){
         data[counter] = c;
         counter++;

      }
//      if(c == EOF){
//         printf("END\n");
//         return 0;
//      }
      data[counter] = '\0';

      //printf("%s\n", data);

      for(int i = 0; i < (strlen(data) - 1); i++){
         c = data[i];

         if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            vowel_counter++;

            if(vowel_counter >= 3){
               checks[0] = true;
            }
         }

         if(c == data[i + 1]){
            checks[1] = true;
         }

         if( (c == 'a' && data[i + 1] == 'b') || (c == 'c' && data[i + 1] == 'd') ||
             (c == 'p' && data[i + 1] == 'q') || (c == 'x' && data[i + 1] == 'y') ){
            checks[2] = false;
         }
      }

      if(checks[0] && checks[1] && checks[2]){
         nice_strings++;
      }

      checks[0] = false;
      checks[1] = false;
      checks[2] =  true;
      vowel_counter = 0;
   //   printf("%d\n", nice_strings);
   }

   printf("%d\n", nice_strings);
   printf("lalalalalaal\n");


   return 0;
}
