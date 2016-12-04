#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


int x_1 = 0, y_1 = 0, x_2 = 0, y_2 = 0;
bool lights[1000][1000] = {false};
enum options {ON, OFF, TOGGLE} options;

int main(){
   //open data file
   FILE * fp_data;
   fp_data = fopen("data", "r");

   //variables to read lines
   char * data_read = NULL;
   size_t len = 0;
   ssize_t read;

   //scan data
   while(1){
      read = getline(&data_read, &len, fp_data);
      if(read == -1){ //end ==> stop while and count lights
         break;
      }

      char digit_string[50];
      for(int i = 0; i < strlen(data_read); i++){
         (isdigit(data_read[i])) ? (digit_string[i] = data_read[i]) : (digit_string[i] = ' ');
      }
      digit_string[strlen(data_read)] = '\0';

      char * pEnd;
      long int x_1, y_1, x_2, y_2;
      x_1 = strtol(digit_string, &pEnd, 10); y_1 = strtol(pEnd, &pEnd, 10);
      x_2 = strtol(pEnd, &pEnd, 10); y_2 = strtol(pEnd, NULL, 10);

      if(strstr(data_read, "turn on") != NULL){
         options = ON;
      }
      else if(strstr(data_read, "turn off") != NULL){
         options = OFF;
      }
      else if(strstr(data_read, "toggle") != NULL){
         options = TOGGLE;
      }
//      printf("(%ld,%ld) (%ld,%ld)\n", x_1, y_1, x_2, y_2);

      for(int x_coord = x_1; x_coord <= x_2; x_coord++){
         for(int y_coord = y_1; y_coord <= y_2; y_coord++){
            switch(options){
               case ON :
                  lights[x_coord][y_coord] = true;
                  break;
               case OFF :
                  lights[x_coord][y_coord] = false;
                  break;
               case TOGGLE :
                  lights[x_coord][y_coord] = !lights[x_coord][y_coord];
                  break;
            }
         }
      }
   }

   int lights_counter = 0;
   for(int x = 0; x < 1000; x++){
      for(int y = 0; y < 1000; y++){
         if(lights[x][y]){
            lights_counter++;
         }
      }
   }
   printf("lights=%d\n", lights_counter);

   return 0;
}
