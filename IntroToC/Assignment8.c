<<<<<<< HEAD
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
    int hist[100] = {0};
    int i, j,x;
    for (i = -1;i < 100; i+= 5){
        for (j = 0; j < n; j++){
            if (grades[j] > i && grades[j] <= i+5){
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
    for (x = 0; x < 100; x++) {
        if (grades[x] == 100){
            printf("*");
        }
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
    int i = 0;
    for(i = loc; i < *n - 1; i++){
        grades[i] = grades[i + 1];
    }
    --*n;
}
double mean(double grades[], int n){
    int i, average;
    double meanVal;
    for(i = 0 ;i < n; i++){
        average += grades[i];
    }
    double b = n;
    meanVal = average / b;
    return meanVal;
}
double StandardDeviation(double grades[], int n){
    double total, mean, SD;
    int i;
    for (i = 0; i < n; ++i){
        total += grades[i];
    }
    mean = total / n;
    for (i = 0; i < n; ++i){
        SD += pow(grades[i] - mean, 2);
    }
    return sqrt(SD / n);
}

int main() {
    double gradesAll[100] = {0},meanMain, sdMain;
    int i, n, length, x, minloc, maxloc;
    readGrades(gradesAll, &length);
    minloc = minimum(gradesAll, length);
    maxloc = maximum(gradesAll, length);
    printf("The data has been adjusted by removing the minimum %.2f\n", gradesAll[minloc]);
    deleteElement(gradesAll, &length, minloc);
    printf("The data has been adjusted by removing the maximum %.2f\n", gradesAll[maxloc]);
    maxloc = maximum(gradesAll, length);
    deleteElement(gradesAll, &length, maxloc);
    printf("\n");
    sdMain = StandardDeviation(gradesAll, length);
    meanMain = mean(gradesAll, length);
    printf("The adjusted mean is %.2f\n", meanMain);
    printf("The adjusted standard deviation is %.2f\n", sdMain);
    frequency(gradesAll, length);
}
=======
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
    int hist[100] = {0};
    int i, j,x;
    for (i = -1;i < 100; i+= 5){
        for (j = 0; j < n; j++){
            if (grades[j] > i && grades[j] <= i+5){
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
    for (x = 0; x < 100; x++) {
        if (grades[x] == 100){
            printf("*");
        }
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
    int i = 0;
    for(i = loc; i < *n - 1; i++){
        grades[i] = grades[i + 1];
    }
    --*n;
}
double mean(double grades[], int n){
    int i, average;
    double meanVal;
    for(i = 0 ;i < n; i++){
        average += grades[i];
    }
    double b = n;
    meanVal = average / b;
    return meanVal;
}
double StandardDeviation(double grades[], int n){
    double total, mean, SD;
    int i;
    for (i = 0; i < n; ++i){
        total += grades[i];
    }
    mean = total / n;
    for (i = 0; i < n; ++i){
        SD += pow(grades[i] - mean, 2);
    }
    return sqrt(SD / n);
}

int main() {
    double gradesAll[100] = {0},meanMain, sdMain;
    int i, n, length, x, minloc, maxloc;
    readGrades(gradesAll, &length);
    minloc = minimum(gradesAll, length);
    maxloc = maximum(gradesAll, length);
    printf("The data has been adjusted by removing the minimum %.2f\n", gradesAll[minloc]);
    deleteElement(gradesAll, &length, minloc);
    printf("The data has been adjusted by removing the maximum %.2f\n", gradesAll[maxloc]);
    maxloc = maximum(gradesAll, length);
    deleteElement(gradesAll, &length, maxloc);
    printf("\n");
    sdMain = StandardDeviation(gradesAll, length);
    meanMain = mean(gradesAll, length);
    printf("The adjusted mean is %.2f\n", meanMain);
    printf("The adjusted standard deviation is %.2f\n", sdMain);
    frequency(gradesAll, length);
}
>>>>>>> b756d6d (Updating repositroy using git)
