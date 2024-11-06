<<<<<<< HEAD
/* Assignment 11
Tyler Bazemore
3/23/2023
COP3223C*/
#include <string.h>
#include <stdio.h>

int main(){
    int prompt = 0,i=0, x = 0,length, t = 0, position = 0; 
    char message[100],codedMessage[100];
    char letter, *letterPositionAlpha, *letterPositionCoded; 
    char decode[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char code[26] = "HIVJKWLAMYNBXOZCTPUDQSREGF";
    //while loop to keep prompting the user to create new strings
    while (prompt == 0) {
        printf("Input a word in all caps\n");
        scanf("%s", message);
        printf("%s\n", message);
        length = strlen(message);
        // nested for loops to first loop through the message than find the position of the letter in the alphabet, and subsequently code it from our coded array
        for(i=0;i<length;i++){
            codedMessage[i] = message[i];
            for (x = 0;x<26;x++){
                if (message[i] == decode[x]){
                    codedMessage[i] = code[x];
                }
            }

        }
        //print out coded message and prompt user to break while loop or stay in it
        printf("%s\n", codedMessage);
        printf("Press 0 to do another string and 1 to quit\n");
        scanf("%d",&prompt);
    }

    return 0;
=======
/* Assignment 11
Tyler Bazemore
3/23/2023
COP3223C*/
#include <string.h>
#include <stdio.h>

int main(){
    int prompt = 0,i=0, x = 0,length, t = 0, position = 0; 
    char message[100],codedMessage[100];
    char letter, *letterPositionAlpha, *letterPositionCoded; 
    char decode[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char code[26] = "HIVJKWLAMYNBXOZCTPUDQSREGF";
    //while loop to keep prompting the user to create new strings
    while (prompt == 0) {
        printf("Input a word in all caps\n");
        scanf("%s", message);
        printf("%s\n", message);
        length = strlen(message);
        // nested for loops to first loop through the message than find the position of the letter in the alphabet, and subsequently code it from our coded array
        for(i=0;i<length;i++){
            codedMessage[i] = message[i];
            for (x = 0;x<26;x++){
                if (message[i] == decode[x]){
                    codedMessage[i] = code[x];
                }
            }

        }
        //print out coded message and prompt user to break while loop or stay in it
        printf("%s\n", codedMessage);
        printf("Press 0 to do another string and 1 to quit\n");
        scanf("%d",&prompt);
    }

    return 0;
>>>>>>> b756d6d (Updating repositroy using git)
}