/* Assignment 8
Tyler Bazemore
2/21/2023
COP3223C 00149*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
// simplest way i found to find reuturn number of digits or points was if statements with returns
int numDigits(int number){
    if (number < 10) return 1;
    if (number < 100) return 2;
    if (number < 1000) return 3;
    if (number < 10000) return 4;
    if (number < 100000) return 5;
    if (number < 1000000) return 6;
    if (number < 10000000) return 7;
    if (number < 100000000) return 8;
}
int numPoints(int timesec){
    if (timesec < 1) return 10;
    if (timesec < 2) return 9;
    if (timesec < 3) return 8;
    if (timesec < 4) return 7;
    if (timesec < 5) return 6;
    if (timesec < 6) return 5;
    if (timesec < 7) return 4;
    if (timesec < 8) return 3;
    if (timesec < 9) return 2;
    if (timesec < 10) return 1;
    if (timesec >= 10) return 0;
}
// Setting up arithemtic game  1 is additions 2 is mutliplication
int arithGame(int max, int quantity, int op){
    int number, number2, guess,penalty , sum, end, correct = 0, wrong = 0;
    srand(time(NULL));// sets up the random number generator
    if (op == 1){
        while (quantity > 0){
            number = 1 + rand()% (max -1);
            number2 = 1 + rand()% (max - 1);
            sum = number + number2;
            printf("What is %d + %d\n",number, number2);
            scanf("%d", &guess);
            if (guess == sum){
                printf ("Great job!\n");
                quantity--;
                correct++;
            }
            else{
                printf("Sorry the answer was %d\n", sum);
                penalty += 5;
                quantity--;
                wrong++;
            }
        }
    }
    else if (op == 2){
            while (quantity > 0){
            number = 1 + rand()% max;
            number2 = 1 + rand()% max;
            sum = number * number2;
            printf("What is %d * %d",number, number2);
            scanf("%d", &guess);
            if (guess == sum){
                printf ("Great job!\n");
                quantity--;
                correct++;
            }
            else{
                printf("Sorry the answer was %d\n", sum);
                quantity--;
                wrong++;
            }
        }
    }
    printf("You got %d correct and %d wrong, in ",correct, wrong);
    return penalty;
}
int guessingGame(int max){
    int number, guess, total = 1;
    srand(time(NULL));//sets up random number generator
    number = 1 + rand()% (max-1);
    printf("Whats your guess?");
    scanf("%d",&guess);
    while (guess != number){
        if (guess > number){
            printf("Incorrect, guess lower");
            scanf("%d",&guess);
            total++;
        }
        else if (guess < number){
            printf("Incorrect, guess higher");
            scanf("%d",&guess);
            total++;
        }
    }
    // Only way i found to print the number used in the function in the main function was to first print it in the guessing game function
    printf("Nice job! you guessed the correct number of %d in ",number);
    return total;
}
int main() {
    int gameChoice, op, max, quantity, total, totalScore, score, penalty, number;
    double average;
    while (gameChoice != 4){
        printf("What game would you like to play\n1 for Arithmetic Game\n2 for Guessing Game\n3 for total score\n4 to quit");
        scanf("%d", &gameChoice);
        if (gameChoice == 1){
            printf("Addition of multiplication?");
            printf("1 for addition\n2 for multiplication");
            scanf("%d", &op);
            printf("What is the maximum number you want to be used?");
            scanf("%d", &max);
            printf("How many questions do you want to do?");
            scanf("%d", &quantity);
            int start = time(0);
            arithGame(max, quantity, op);
            int end = time(0);
            int timespent = end - start;
            timespent += penalty;
            average = ceil((double)quantity / (double) timespent);
            printf("an average of %.2f seconds per problem\n", average);
            score = numPoints(timespent);
            printf("Youre score for the round is %d\n", score);
            totalScore = totalScore + score;
        }
        else if (gameChoice == 2){
            printf("What is the maximum number you want to be used?");
            scanf("%d", &max);
            int start = time(0);
            guessingGame(max);
            int end = time(0);
            int timespent = end - start;
            score = numPoints(timespent) / (2 * numDigits(max));
            printf("%d seconds.\n",timespent);
            printf("Your score for the round is %d.\n",score);
            totalScore = totalScore + score;
        }
        else if (gameChoice == 3){
            printf("Your total score is %d\n", totalScore);
        }
        else if (gameChoice == 4){
            printf("Goodbye");
            gameChoice = 4;
        }
    }

}
