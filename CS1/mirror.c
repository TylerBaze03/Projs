<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 21
char** createArr();
int main(){
   int tests = 0, col = 0, row = 0;
   int i = 0, tmp_len = 0;
   int a = 0,j = 0, y = 0, z = 0;
   char tmp_char;
   char* tmp_string = calloc(SIZE+1, sizeof(char));
   scanf("%d", &tests);
   char** arr = createArr();
    for (a = 0;a<tests;a++){
        scanf("%d %d",&row, &col);
        col++;
        tmp_len = row;
        for(j = 0;j<row;j++){
            scanf("%s",arr[j]);
        }
        printf("Test %d\n", a+1);
        for (i = row-1; i >=0;i--){

            int min = 0;
            int max = col - 1;

            for(int v= col-2;v>=0;v--){
                printf("%c", arr[i][v]);
            }

            printf("\n");

        }
    }


   for (int x = 0; x < SIZE+1; x++){
      free(arr[x]);  
   }
 
    free(arr);
 
    return 0;
}

char** createArr(){
    char** arr = calloc(SIZE+1, sizeof(char*));
    for (int i = 0;i<SIZE;i++){
        arr[i] = calloc(SIZE+1, sizeof(char));

    }
    return arr;
=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 21
char** createArr();
int main(){
   int tests = 0, col = 0, row = 0;
   int i = 0, tmp_len = 0;
   int a = 0,j = 0, y = 0, z = 0;
   char tmp_char;
   char* tmp_string = calloc(SIZE+1, sizeof(char));
   scanf("%d", &tests);
   char** arr = createArr();
    for (a = 0;a<tests;a++){
        scanf("%d %d",&row, &col);
        col++;
        tmp_len = row;
        for(j = 0;j<row;j++){
            scanf("%s",arr[j]);
        }
        printf("Test %d\n", a+1);
        for (i = row-1; i >=0;i--){

            int min = 0;
            int max = col - 1;

            for(int v= col-2;v>=0;v--){
                printf("%c", arr[i][v]);
            }

            printf("\n");

        }
    }


   for (int x = 0; x < SIZE+1; x++){
      free(arr[x]);  
   }
 
    free(arr);
 
    return 0;
}

char** createArr(){
    char** arr = calloc(SIZE+1, sizeof(char*));
    for (int i = 0;i<SIZE;i++){
        arr[i] = calloc(SIZE+1, sizeof(char));

    }
    return arr;
>>>>>>> b756d6d (Updating repositroy using git)
}