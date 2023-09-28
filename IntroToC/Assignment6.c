/* Assignment 6
Tyler Bazemore
2/13/2023
COP3223C*/
#include <stdio.h>
int main() {
    int newNum, minNum, maxNumm = 0; 
    double total = 0, numsEntered = 0;
    printf("PLease enter an integer, to stop the program enter -1:");
    scanf("%d", &newNum);
    minNum = newNum;
    while (newNum != -1){
        total += newNum;
        numsEntered++;
        if (newNum <= minNum){
            minNum = newNum;
        }
        else if (newNum >= maxNumm){
            maxNumm = newNum;
        }
        scanf("%d", &newNum);
    }
    printf("The Lowest Number was: %d\nThe Highest number was: %d\n", minNum, maxNumm);
    printf("The number of values entered was: %.0f\nThe average of the numbers was: %.2f",numsEntered, total  / numsEntered);
}