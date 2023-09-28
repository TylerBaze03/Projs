/* Assignment 4 Grade Passing Calculator
Tyler Bazemore
1/28/2023
COP3223C*/
#include <stdio.h>
int main() {
    int averageGrade, gradeTotal = 0.0, passGrade = 0.0;
    int userGrade = 0;
    printf("Input a grade:");
    scanf("%d", &userGrade);
    while (userGrade != -1) {
        if (userGrade >= 70 && userGrade <= 100) {
            // Must use && to make sure it dosen't count grade above 100 as one of the valid grades
            gradeTotal++;
            passGrade++;
        }
        if (userGrade < 70) {
            gradeTotal++;
        }
        if (userGrade > 100) {
            printf("That is not a valid grade!");
        }
        printf("Enter another grade:");
        scanf("%d", &userGrade);
    }
    // end statement outside of the while loop and using doubles to make sure there is a decimal
    printf("%.1f %% of the valid grades entered were passing", ((double)passGrade / (double)gradeTotal)*100);
    return 0;
}