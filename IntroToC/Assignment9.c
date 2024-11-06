<<<<<<< HEAD
/* Assignment 9
Tyler Bazemore
3/10/2023
COP3223C*/
#include <stdio.h>
int main() {
    int gradeTable [4][5], average;
    printf("Input scores for all students");
    int i,j;
// nested for loop that gets all scores
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
            scanf("%d", &gradeTable[i][j]);
        }
    }
    // nested for loop to show matrix in full of all scores
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
            printf("%d ", gradeTable[i][j]);
        }
        printf("\n");
    }
    //nested for loop to calculate averages of each individual student
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
        average += gradeTable[i][j];
        }
    printf("Average score of student %d is %d\n", i+1, average/5);
    average = 0;
    }
    // nested for loop to show average of each quiz, just the opposite of last nested for loop
    for(j=0;j<5;j++){
        for(i=0;i<4;i++){
            average += gradeTable[i][j];
        }
    printf("Average score of quiz %d is %d\n", j+1, average/4);
    average = 0;
    }
    //average for all quizes, just adds to one variable
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
        average += gradeTable[i][j];
        }
    }
    printf("Average score of students across all quizzes is %d\n", average/20);
=======
/* Assignment 9
Tyler Bazemore
3/10/2023
COP3223C*/
#include <stdio.h>
int main() {
    int gradeTable [4][5], average;
    printf("Input scores for all students");
    int i,j;
// nested for loop that gets all scores
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
            scanf("%d", &gradeTable[i][j]);
        }
    }
    // nested for loop to show matrix in full of all scores
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
            printf("%d ", gradeTable[i][j]);
        }
        printf("\n");
    }
    //nested for loop to calculate averages of each individual student
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
        average += gradeTable[i][j];
        }
    printf("Average score of student %d is %d\n", i+1, average/5);
    average = 0;
    }
    // nested for loop to show average of each quiz, just the opposite of last nested for loop
    for(j=0;j<5;j++){
        for(i=0;i<4;i++){
            average += gradeTable[i][j];
        }
    printf("Average score of quiz %d is %d\n", j+1, average/4);
    average = 0;
    }
    //average for all quizes, just adds to one variable
    for(i=0;i<4;i++){
        for(j=0;j<5;j++){
        average += gradeTable[i][j];
        }
    }
    printf("Average score of students across all quizzes is %d\n", average/20);
>>>>>>> b756d6d (Updating repositroy using git)
}