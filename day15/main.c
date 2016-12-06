#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int properties[4][5];
int line_count = 0, property_count = 0;

int main(){
   FILE * fp_data;
   fp_data = fopen("data", "r");

   char * data_read = NULL;
   size_t len = 0;
   ssize_t read;

   //parse data to properties
   while((read = getline(&data_read, &len, fp_data)) != -1){
      for(int char_count = 0; char_count < len; char_count++){
         char c = data_read[char_count];

         if(c == '-'){
            properties[line_count][property_count] = (data_read[char_count + 1] - '0') * -1;
            property_count++;
            char_count++;
         }
         else if(isdigit(c) != 0){
            properties[line_count][property_count] = data_read[char_count] - '0';
            property_count++;
         }
      }

      line_count++;
      property_count = 0;
   }

   //print parsed data
   for(int i = 0; i < 4; i++){
      for(int j = 0; j < 5; j++){
         printf("%d ", properties[i][j]);
      }
      printf("\n");
   }

   //go through data
   int capacity, durability, flavor, texture;
   int score, max_score = 0;
   for(int a = 0; a <= 100; a++){
      for(int b = 0; b <= 100; b++){
         for(int c = 0; c <= 100; c++){
            int d = 100 - a - b - c;

            capacity =  a * properties[0][0] + b * properties[1][0] + c * properties[2][0] + d * properties[3][0];
            durability =a * properties[0][1] + b * properties[1][1] + c * properties[2][1] + d * properties[3][1];
            flavor =    a * properties[0][2] + b * properties[1][2] + c * properties[2][2] + d * properties[3][2];
            texture =   a * properties[0][3] + b * properties[1][3] + c * properties[2][3] + d * properties[3][3];

            capacity = MAX(capacity, 0);
            durability = MAX(durability, 0);
            flavor = MAX(flavor, 0);
            texture = MAX(texture, 0);

            score = capacity * durability * flavor * texture;
            if(score > max_score){
               max_score = score;
            }
         }
      }
   }

   printf("max score = %d\n", max_score);
   return 0;
}
