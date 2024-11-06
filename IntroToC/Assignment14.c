<<<<<<< HEAD
/* Assignment14
Tyler Bazemore
4/12/2023
COP3223C*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//First creating struct to create a date as well as person struct and type def
struct date {
    int day, month, year;
};
typedef struct person{
    char gender;
    char name[50];
    double annualinc;
    struct date bDate;

}Person;
// Function that prompts income and checks if it is under 1 million 
// Function to create table of information at the end
void personChart(Person per1, Person per2, Person per3){
    printf("Person  |Name\t\t\tGender\t\tBirth Date\t\tIncome Annual \n");
    printf("Person 1|%s\t\t%c\t\t%d/%d/%d\t\t%.2lf \n", per1.name, per1.gender, per1.bDate.month, per1.bDate.day, per1.bDate.year, per1.annualinc);
    printf("Person 2|%s\t\t%c\t\t%d/%d/%d\t\t%.2lf \n", per2.name, per2.gender, per2.bDate.month, per2.bDate.day, per2.bDate.year, per2.annualinc);
    printf("Person 3|%s\t\t%c\t\t%d/%d/%d\t\t%.2lf \n", per3.name, per3.gender, per3.bDate.month, per3.bDate.day, per3.bDate.year, per3.annualinc);
}
// Function to check if the date is a real date including leap years
Person dateChecker(Person p){
    int i =0;
    while (i ==0) {
        if (p.bDate.year % 400 == 0) {
            if (p.bDate.month == 1 || p.bDate.month == 3 || p.bDate.month == 5 || p.bDate.month == 7 ||
                p.bDate.month == 8 || p.bDate.month == 10 || p.bDate.month == 12) {
                if (p.bDate.day > 32 || p.bDate.day < 0) {
                    printf("This is not a vaild date please enter a valid one");
                } else {
                    return p;
                }
            } else if (p.bDate.month == 2) {
                if (p.bDate.day > 30 || p.bDate.day < 0) {
                    printf("This is not a vaild date please enter a valid one");
                } else {
                    return p;
                }
            } else if (p.bDate.month == 4 || p.bDate.month == 6 || p.bDate.month == 9 || p.bDate.month == 11) {
                if (p.bDate.day > 31 || p.bDate.day < 0) {
                    printf("This is not a vaild date please enter a valid one");
                } else {
                    return p;
                }
            }
        } else {
            if (p.bDate.month == 1 || p.bDate.month == 3 || p.bDate.month == 5 || p.bDate.month == 7 ||
                p.bDate.month == 8 || p.bDate.month == 10 || p.bDate.month == 12) {
                if (p.bDate.day > 32 || p.bDate.day < 0) {
                    printf("This is not a vaild date please enter a valid one");
                } else {
                    return p;
                }
            } else if (p.bDate.month == 2) {
                if (p.bDate.day > 29 || p.bDate.day < 0) {
                    printf("This is not a vaild date please enter a valid one");
                } else {
                    return p;
                }
            } else if (p.bDate.month == 4 || p.bDate.month == 6 || p.bDate.month == 9 || p.bDate.month == 11) {
                if (p.bDate.day > 31 || p.bDate.day < 0) {
                    printf("This is not a vaild date please enter a valid one");
                } else {
                    return p;
                }
            }
        }
    }
}
int main(){
    Person p1, p2, p3;
    int i = 0, x = 0, y = 0, z = 0;
    // Person 1 information
    printf("What is the name of person 1\n");
    scanf(" %[^\n]",p1.name);
    while (i == 0) {
        printf("What is the gender of person 1\n");
        scanf(" %c", &p1.gender);
        if (p1.gender == 'M' || p1.gender == 'O' || p1.gender == 'F'){
            break;
        }
        else{
            printf("Not a valid choice, choose either M, F, or O");
        }
    }
    printf("What is the birthdate of the person\n");
    scanf("%d/%d/%d",&p1.bDate.month, &p1.bDate.day, &p1.bDate.year);
    dateChecker(p1);
    printf("What is the annual income of the person\n");
    while (i == 0){
        scanf(" %lf", &p1.annualinc);
        if (p1.annualinc <= 1000000 || p1.annualinc >= 0){
            break;
        }
        else {
            printf("Not in range");
        }
    }

    // Person 2 information
    printf("What is the name of the person 2\n");
    scanf(" %[^\n]",p2.name);
    while (i == 0) {
        printf("What is the gender of person 2\n");
        scanf(" %c", &p2.gender);
        if (p2.gender == 'M' || p2.gender == 'O' || p2.gender == 'F'){
            break;
        }
        else{
            printf("Not a valid choice, choose either M, F, or O");
        }
    }
    printf("What is the birthdate of the person\n");
    scanf("%d/%d/%d",&p2.bDate.month, &p2.bDate.day, &p2.bDate.year);
    dateChecker(p2);
    printf("What is the annual income of the person\n");
    while (i == 0){
        scanf(" %lf", &p2.annualinc);
        if (p2.annualinc <= 1000000 || p2.annualinc >= 0){
            break;
        }
        else {
            printf("Not in range");
        }
    }

    //Person 3 information
    printf("What is the name of person 3\n");
    scanf(" %[^\n]",p3.name);
    while (i == 0) {
        printf("What is the gender of person 3\n");
        scanf(" %c", &p3.gender);
        if (p3.gender == 'M' || p3.gender == 'O' || p3.gender == 'F'){
            break;
        }
        else{
            printf("Not a valid choice, choose either M, F, or O");
        }
    }
    printf("What is the birthdate of the person\n");
    scanf("%d/%d/%d",&p3.bDate.month, &p3.bDate.day, &p3.bDate.year);
    dateChecker(p3);
    printf("What is the annual income of the person\n");
    while (i == 0){
        scanf(" %lf", &p3.annualinc);
        if (p3.annualinc <= 1000000 || p3.annualinc >= 0){
            break;
        }
        else {
            printf("Not in range");
        }
    }

    //Information displayer
    personChart(p1,p2,p3);
    return 0;
}



Person personAnnualInc(Person p){
    int i = 0;
    printf("What is the annual income of the person\n");
    while (i == 0){
        scanf(" %lf", &p.annualinc);
        if (p.annualinc <= 1000000 || p.annualinc >= 0){
            printf("123");
            return p;
        }
        else {
            printf("Not in range");
        }
    }
=======
/* Assignment14
Tyler Bazemore
4/12/2023
COP3223C*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//First creating struct to create a date as well as person struct and type def
struct date {
    int day, month, year;
};
typedef struct person{
    char gender;
    char name[50];
    double annualinc;
    struct date bDate;

}Person;
// Function that prompts income and checks if it is under 1 million 
// Function to create table of information at the end
void personChart(Person per1, Person per2, Person per3){
    printf("Person  |Name\t\t\tGender\t\tBirth Date\t\tIncome Annual \n");
    printf("Person 1|%s\t\t%c\t\t%d/%d/%d\t\t%.2lf \n", per1.name, per1.gender, per1.bDate.month, per1.bDate.day, per1.bDate.year, per1.annualinc);
    printf("Person 2|%s\t\t%c\t\t%d/%d/%d\t\t%.2lf \n", per2.name, per2.gender, per2.bDate.month, per2.bDate.day, per2.bDate.year, per2.annualinc);
    printf("Person 3|%s\t\t%c\t\t%d/%d/%d\t\t%.2lf \n", per3.name, per3.gender, per3.bDate.month, per3.bDate.day, per3.bDate.year, per3.annualinc);
}
// Function to check if the date is a real date including leap years
Person dateChecker(Person p){
    int i =0;
    while (i ==0) {
        if (p.bDate.year % 400 == 0) {
            if (p.bDate.month == 1 || p.bDate.month == 3 || p.bDate.month == 5 || p.bDate.month == 7 ||
                p.bDate.month == 8 || p.bDate.month == 10 || p.bDate.month == 12) {
                if (p.bDate.day > 32 || p.bDate.day < 0) {
                    printf("This is not a vaild date please enter a valid one");
                } else {
                    return p;
                }
            } else if (p.bDate.month == 2) {
                if (p.bDate.day > 30 || p.bDate.day < 0) {
                    printf("This is not a vaild date please enter a valid one");
                } else {
                    return p;
                }
            } else if (p.bDate.month == 4 || p.bDate.month == 6 || p.bDate.month == 9 || p.bDate.month == 11) {
                if (p.bDate.day > 31 || p.bDate.day < 0) {
                    printf("This is not a vaild date please enter a valid one");
                } else {
                    return p;
                }
            }
        } else {
            if (p.bDate.month == 1 || p.bDate.month == 3 || p.bDate.month == 5 || p.bDate.month == 7 ||
                p.bDate.month == 8 || p.bDate.month == 10 || p.bDate.month == 12) {
                if (p.bDate.day > 32 || p.bDate.day < 0) {
                    printf("This is not a vaild date please enter a valid one");
                } else {
                    return p;
                }
            } else if (p.bDate.month == 2) {
                if (p.bDate.day > 29 || p.bDate.day < 0) {
                    printf("This is not a vaild date please enter a valid one");
                } else {
                    return p;
                }
            } else if (p.bDate.month == 4 || p.bDate.month == 6 || p.bDate.month == 9 || p.bDate.month == 11) {
                if (p.bDate.day > 31 || p.bDate.day < 0) {
                    printf("This is not a vaild date please enter a valid one");
                } else {
                    return p;
                }
            }
        }
    }
}
int main(){
    Person p1, p2, p3;
    int i = 0, x = 0, y = 0, z = 0;
    // Person 1 information
    printf("What is the name of person 1\n");
    scanf(" %[^\n]",p1.name);
    while (i == 0) {
        printf("What is the gender of person 1\n");
        scanf(" %c", &p1.gender);
        if (p1.gender == 'M' || p1.gender == 'O' || p1.gender == 'F'){
            break;
        }
        else{
            printf("Not a valid choice, choose either M, F, or O");
        }
    }
    printf("What is the birthdate of the person\n");
    scanf("%d/%d/%d",&p1.bDate.month, &p1.bDate.day, &p1.bDate.year);
    dateChecker(p1);
    printf("What is the annual income of the person\n");
    while (i == 0){
        scanf(" %lf", &p1.annualinc);
        if (p1.annualinc <= 1000000 || p1.annualinc >= 0){
            break;
        }
        else {
            printf("Not in range");
        }
    }

    // Person 2 information
    printf("What is the name of the person 2\n");
    scanf(" %[^\n]",p2.name);
    while (i == 0) {
        printf("What is the gender of person 2\n");
        scanf(" %c", &p2.gender);
        if (p2.gender == 'M' || p2.gender == 'O' || p2.gender == 'F'){
            break;
        }
        else{
            printf("Not a valid choice, choose either M, F, or O");
        }
    }
    printf("What is the birthdate of the person\n");
    scanf("%d/%d/%d",&p2.bDate.month, &p2.bDate.day, &p2.bDate.year);
    dateChecker(p2);
    printf("What is the annual income of the person\n");
    while (i == 0){
        scanf(" %lf", &p2.annualinc);
        if (p2.annualinc <= 1000000 || p2.annualinc >= 0){
            break;
        }
        else {
            printf("Not in range");
        }
    }

    //Person 3 information
    printf("What is the name of person 3\n");
    scanf(" %[^\n]",p3.name);
    while (i == 0) {
        printf("What is the gender of person 3\n");
        scanf(" %c", &p3.gender);
        if (p3.gender == 'M' || p3.gender == 'O' || p3.gender == 'F'){
            break;
        }
        else{
            printf("Not a valid choice, choose either M, F, or O");
        }
    }
    printf("What is the birthdate of the person\n");
    scanf("%d/%d/%d",&p3.bDate.month, &p3.bDate.day, &p3.bDate.year);
    dateChecker(p3);
    printf("What is the annual income of the person\n");
    while (i == 0){
        scanf(" %lf", &p3.annualinc);
        if (p3.annualinc <= 1000000 || p3.annualinc >= 0){
            break;
        }
        else {
            printf("Not in range");
        }
    }

    //Information displayer
    personChart(p1,p2,p3);
    return 0;
}



Person personAnnualInc(Person p){
    int i = 0;
    printf("What is the annual income of the person\n");
    while (i == 0){
        scanf(" %lf", &p.annualinc);
        if (p.annualinc <= 1000000 || p.annualinc >= 0){
            printf("123");
            return p;
        }
        else {
            printf("Not in range");
        }
    }
>>>>>>> b756d6d (Updating repositroy using git)
}