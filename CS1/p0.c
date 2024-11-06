<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char reallocateMem(char *sign){
    int i = 0, length = 0;
    for (i = 0; i < 100002; i++){
        if (sign[i] != '\0'){
            length = i;
        }
        else{
            ;
        }
    }
    sign = (char *)realloc(sign, length);
    return *sign;
}
int frequencyLetters (char* sign, int *freq){
    int i = 0, x = 0;
    while (sign[i] != '\0') {

      if (sign[i] >= 'A' && sign[i] <= 'Z') {
         x = sign[i] - 'A';
         freq[x]++;
      }

      i++;
   }
   return *freq;
}
int main(void){
    double time_spent = 0.0;
    clock_t begin = clock();
    
    int i = 0, total = 0, newletters = 0, f = 0;
    int freq1[26] = {0};
    int freq2[26] = {0};
    char *sign1, *sign2;
    sign1 = (char*)malloc(100002 *sizeof(char));
    sign2 = (char*)malloc(100002 *sizeof(char));
    fgets(sign1, 100002, stdin);
    //Initializing and finding length of string to reallocate than reallocating memory
    reallocateMem(sign1);
    fgets(sign2, 100002, stdin);
    reallocateMem(sign2);
    // getting frquencies of all letters in both strings
    frequencyLetters(sign1, freq1);
    frequencyLetters(sign2, freq2);
/*    //Total new letters in original sign
   for (f = 0;f<26;f++){
    total += freq1[f];
   }
   printf("%d\n", total);
   total = 0;
   for (f = 0;f<26;f++){
    total += freq2[f];
   }
   
printf("%d\n", total);
*/
   for (i = 0;i < 26;i++){
    if(freq1[i] < freq2[i]){
        int diff = 0;
        diff = (freq2[i] - freq1[i]);
        newletters = newletters + diff;
    }
    
   }
printf("%d", newletters);


clock_t end = clock();
time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
printf("The elapsed time is %f seconds", time_spent);
    
=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
char reallocateMem(char *sign){
    int i = 0, length = 0;
    for (i = 0; i < 100002; i++){
        if (sign[i] != '\0'){
            length = i;
        }
        else{
            ;
        }
    }
    sign = (char *)realloc(sign, length);
    return *sign;
}
int frequencyLetters (char* sign, int *freq){
    int i = 0, x = 0;
    while (sign[i] != '\0') {

      if (sign[i] >= 'A' && sign[i] <= 'Z') {
         x = sign[i] - 'A';
         freq[x]++;
      }

      i++;
   }
   return *freq;
}
int main(void){
    double time_spent = 0.0;
    clock_t begin = clock();
    
    int i = 0, total = 0, newletters = 0, f = 0;
    int freq1[26] = {0};
    int freq2[26] = {0};
    char *sign1, *sign2;
    sign1 = (char*)malloc(100002 *sizeof(char));
    sign2 = (char*)malloc(100002 *sizeof(char));
    fgets(sign1, 100002, stdin);
    //Initializing and finding length of string to reallocate than reallocating memory
    reallocateMem(sign1);
    fgets(sign2, 100002, stdin);
    reallocateMem(sign2);
    // getting frquencies of all letters in both strings
    frequencyLetters(sign1, freq1);
    frequencyLetters(sign2, freq2);
/*    //Total new letters in original sign
   for (f = 0;f<26;f++){
    total += freq1[f];
   }
   printf("%d\n", total);
   total = 0;
   for (f = 0;f<26;f++){
    total += freq2[f];
   }
   
printf("%d\n", total);
*/
   for (i = 0;i < 26;i++){
    if(freq1[i] < freq2[i]){
        int diff = 0;
        diff = (freq2[i] - freq1[i]);
        newletters = newletters + diff;
    }
    
   }
printf("%d", newletters);


clock_t end = clock();
time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
printf("The elapsed time is %f seconds", time_spent);
    
>>>>>>> b756d6d (Updating repositroy using git)
}