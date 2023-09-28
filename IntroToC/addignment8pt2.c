/* Assignment 8
Tyler Bazemore
3/10/2023
COP3223C*/
#include <stdio.h>
#include <math.h>
void readGrades(double grades[], int *n) {
    int newGrade,x;
    scanf("%d", &newGrade);
    for(*n = 0; newGrade!= -999; ++*n){
        grades[*n]= newGrade;
        scanf("%d", &newGrade);
    }
}

void frequency(double grades[], int n){
    int hist[100];
    int i, j;
    for (i = -1;i < 100; i+= 5){
        for (j = 0; j < n; j++){
            if (grades[j] >= i && grades[j] < i+5){
                hist[i]++;
            }
        }
    }
    for (i = -1; i < 99; i+=5){
        printf("%d - %d| ",i+1, i+5);
        for(j=0; j < hist[i]; j++){
            printf("*");
        }
        printf("\n");
    }
    printf("100| ");
    for(j=100; j < hist[100]; j++){
        printf("*");
    }

}
int maximum(double grades[], int n){
    int i,maximumLoc;
    int maximumNum = grades[0];
    for (i = 1; i < n; i++){
        if (grades[i] > maximumNum) {
            maximumNum = grades[i];
        }
    }
    for (i=0; i < n; i++){
        if (grades[i] == maximumNum){
            maximumLoc = i;
        }
    }
    return maximumLoc;
}
int minimum(double grades[], int n){
    int i, minimumLoc;
    int minimumNum = grades[0];
    for (i = 1; i < n; i++){
        if (grades[i] < minimumNum) {
            minimumNum = grades[i];
        }
    }
    for (i=0; i < n; i++){
        if (grades[i] == minimumNum){
            minimumLoc = i;
        }
    }
    return minimumLoc;
}
void deleteElement(double grades[], int *n, int loc){
    int i;
    for(i = loc ; i < *n; i++){
        grades[i] = grades[i + 1];
    }
    --*n;
}
double mean(double grades[], int n){
    int i;
    double meanVal, average;
    for(i=0;i<n;i++){
        average += grades[i];
    }
    meanVal = average / n;
}
double StandardDeviation(double grades[], int n){
    double total, mean, SD;
    int i;
    for (i = 0; i < 10; ++i){
        total += grades[i];
    }
    mean = total / n;
    for (i = 0; i < 10; ++i){
        SD += pow(grades[i] - mean, 2);
    }
    return sqrt(SD / n);
}

int main() {
    double gradesAll[100] = {0};
    int i, n, length, x, minloc, maxloc;
    readGrades(gradesAll, &length);
    printf("%d\n",length);
    minloc = minimum(gradesAll, length);
    printf("The data has been adjusted by removing the minimum %.2f\n", gradesAll[minloc]);
    deleteElement(gradesAll, &length, gradesAll[minloc]);
    maxloc = maximum(gradesAll, length);
    printf("The data has been adjusted by removing the maximum %.2f\n", gradesAll[maxloc]);
    deleteElement(gradesAll, &length, gradesAll[maxloc]);
    for (x = 0; x < length; x++) {
        printf("%f ", gradesAll[x]);
    }
}