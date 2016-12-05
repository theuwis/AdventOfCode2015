#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
   //open data file
   FILE * fp_data;
   fp_data = fopen("data", "r");

   //variables to read lines
   char * data_read = NULL;
   size_t len = 0;
   ssize_t read;
   int char_count = 0, letter_count = 0, total_count = 0;
   char substr[50];

   while( (read = getline(&data_read, &len, fp_data)) != -1){
      //remove " " around the line
      strncpy(substr, data_read + 1, (int) strlen(data_read) - 4);
      substr[(int) strlen(data_read) - 4] = '\0';

      //parse the whole line
      do{
         char c = substr[char_count];

         if((c == '\\')){
            switch (substr[char_count + 1]) {
               case '\"':
                  char_count++;
                  letter_count += 3;
                  total_count++;
                  break;
               case '\\' :
                  char_count++;
                  letter_count += 3;
                  total_count++;
                  break;
               case 'x' :
                  char_count += 3;
                  letter_count += 4;
                  total_count += 3;
                  break;
            }
         }
         letter_count++;
         total_count++;
      } while(char_count++ < strlen(substr) - 1);
      letter_count += 6;//+6 since " " at beginning and end are remove (+ encoding)
      total_count += 2; //+2 since " " at beginning and end are remove
      char_count = 0;
   }

   printf("answer=%d (total=%d, string=%d)\n", letter_count - total_count, total_count, letter_count);

   return 0;
}
