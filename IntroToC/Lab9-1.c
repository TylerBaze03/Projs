<<<<<<< HEAD
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *movieFile;
    char movieArr[1000] = {'\0'};
    char currMovie[44] = {'\0'};
    char reader = 'c';
    char *token, *oldToken;
    int l = 0, i = 0, j = 0, k = 0;
    char movieTimes[44] = {'\0'};
    char movieRating[43] = {'\0'};
    
    movieFile = fopen("movies.txt", "r");
    
    while(fgets(movieArr, 1000, movieFile)){
    	l = 0;
    	l = strlen(movieArr);
    	token = strtok(movieArr, ",");
    	token = strtok(NULL, ",");
    	printf("%s", token);
    	if (token != oldToken){
    	 oldToken =  strtok(movieArr, ",");
    	 oldToken = strtok(NULL, ",");
    	  for(i = 0; i< l; i++){
    	    currMovie[i] = oldToken[i];
    	  }
    	  for(j = i; j< 44; j++){
    	    currMovie[j] = '\0';
    	  }
    	  
    	  printf("\n");
    	  printf("%s", currMovie);
    	}
    	else{
    	    printf("I\n");
    	}
	}
    
=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    FILE *movieFile;
    char movieArr[1000] = {'\0'};
    char currMovie[44] = {'\0'};
    char reader = 'c';
    char *token, *oldToken;
    int l = 0, i = 0, j = 0, k = 0;
    char movieTimes[44] = {'\0'};
    char movieRating[43] = {'\0'};
    
    movieFile = fopen("movies.txt", "r");
    
    while(fgets(movieArr, 1000, movieFile)){
    	l = 0;
    	l = strlen(movieArr);
    	token = strtok(movieArr, ",");
    	token = strtok(NULL, ",");
    	printf("%s", token);
    	if (token != oldToken){
    	 oldToken =  strtok(movieArr, ",");
    	 oldToken = strtok(NULL, ",");
    	  for(i = 0; i< l; i++){
    	    currMovie[i] = oldToken[i];
    	  }
    	  for(j = i; j< 44; j++){
    	    currMovie[j] = '\0';
    	  }
    	  
    	  printf("\n");
    	  printf("%s", currMovie);
    	}
    	else{
    	    printf("I\n");
    	}
	}
    
>>>>>>> b756d6d (Updating repositroy using git)
}