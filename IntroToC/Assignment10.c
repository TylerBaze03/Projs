<<<<<<< HEAD
/* Assignment 10
Tyler Bazemore
3/22/2023
COP3223C*/
#include <string.h>
#include <stdio.h>

void output(){
    int i,x = 0,length, t = 0, prompt = 0;
    char message[100];
    scanf("%[^\n]", message);
    printf("%s\n", message);
    length = strlen(message);
    //Prints string backwards
    for (i = length - 1; i >= 0; i--) {
        printf("%c", message[i]);
    }
    printf("\n");
    // prints out each letter individually on individual lines
    for (i = 0; i < length; i++) {
        printf("%c\n", message[i]);
    }
    // Creating right triangle  using nested for loops
    for (i = length; i >= 0; i--) {
        printf("\n");
        for (t = 0; t < i; t++) {
            printf("%c", message[t]);
        }
    }
}
int main(){
    int prompt = 0,i=0;
        char message[100];
    while(prompt == 0) {
        printf("Input a string upto 100 characters\n");
        int i,x = 0,length, t = 0, prompt = 0;

        scanf("%[^\n]", message);
        printf("%s\n", message);
        length = strlen(message);
        //Prints string backwards
        for (i = length - 1; i >= 0; i--) {
            printf("%c", message[i]);
        }
        printf("\n");
        // prints out each letter individually on individual lines
        for (i = 0; i < length; i++) {
            printf("%c\n", message[i]);
        }
        // Creating right triangle  using nested for loops
        for (i = length; i >= 0; i--) {
            printf("\n");
            for (t = 0; t < i; t++) {
                printf("%c", message[t]);
            }   
    }
        printf("Press 0 to do another string and 1 to quit\n");
        scanf("%d",&prompt);
    }

    return 0;
}
=======
/* Assignment 10
Tyler Bazemore
3/22/2023
COP3223C*/
#include <string.h>
#include <stdio.h>

void output(){
    int i,x = 0,length, t = 0, prompt = 0;
    char message[100];
    scanf("%[^\n]", message);
    printf("%s\n", message);
    length = strlen(message);
    //Prints string backwards
    for (i = length - 1; i >= 0; i--) {
        printf("%c", message[i]);
    }
    printf("\n");
    // prints out each letter individually on individual lines
    for (i = 0; i < length; i++) {
        printf("%c\n", message[i]);
    }
    // Creating right triangle  using nested for loops
    for (i = length; i >= 0; i--) {
        printf("\n");
        for (t = 0; t < i; t++) {
            printf("%c", message[t]);
        }
    }
}
int main(){
    int prompt = 0,i=0;
        char message[100];
    while(prompt == 0) {
        printf("Input a string upto 100 characters\n");
        int i,x = 0,length, t = 0, prompt = 0;

        scanf("%[^\n]", message);
        printf("%s\n", message);
        length = strlen(message);
        //Prints string backwards
        for (i = length - 1; i >= 0; i--) {
            printf("%c", message[i]);
        }
        printf("\n");
        // prints out each letter individually on individual lines
        for (i = 0; i < length; i++) {
            printf("%c\n", message[i]);
        }
        // Creating right triangle  using nested for loops
        for (i = length; i >= 0; i--) {
            printf("\n");
            for (t = 0; t < i; t++) {
                printf("%c", message[t]);
            }   
    }
        printf("Press 0 to do another string and 1 to quit\n");
        scanf("%d",&prompt);
    }

    return 0;
}
>>>>>>> b756d6d (Updating repositroy using git)
