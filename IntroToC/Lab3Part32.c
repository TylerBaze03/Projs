/* Assignment 5
Tyler Bazemore
2/8/2023
COP3223C*/
#include <stdio.h>
int main() {
    int mult5 = 5, twoAndSeven = 14, mult8 = 100, sumMult8 = 0, oddNums = 21, oddNumSum = 0;
    while (mult5 < 60){
        printf("%d ", mult5);
        mult5 += 5;
        
    }
    printf("\n");
    while (twoAndSeven < 200){
        if (twoAndSeven % 2 == 0 && twoAndSeven % 7 == 0){
            printf("%d ",twoAndSeven);
        }
        twoAndSeven += 2;
    }
    printf("\n");
    while (mult8 < 500){
        if(mult8 % 8 == 0){
            sumMult8 += mult8;
            mult8++;
        }
        else{
            mult8++;
        }
    }
    printf("%d", sumMult8);
    printf("\n");
    while (oddNums < 100){
        oddNumSum += oddNums;
        oddNums += 2;
        printf("%d ", oddNumSum);
    }
}

