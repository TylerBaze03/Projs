/* LAB6-1
Tyler Bazemore
2/19/2023
COP3223C*/
#include <stdio.h>
void celsiusToF(){
    float userDegrees;
    float userNew;
    printf("What is your number?:");
    scanf("%f", &userDegrees);
    userNew = 1.8 * userDegrees + 32;
    printf("%.2f degrees C = %.2f degrees F", userDegrees,userNew);
}
void fahrenheitToC(){
    double userDegrees;
    double userNew;
    printf("What is your number?:");
    scanf("%lf", &userDegrees);
    userNew = .555555556 * (userDegrees-32);
    printf("%.2lf degrees F = %.2lf degrees C",userDegrees,userNew);
}
int main() {
    int switchCmd;
    printf("Would you like to go from celcuis to farenheit or farenheit to celcius?\n");
    printf("Type 1 for celsius to farenheit or 2 for farenheit to celcius");
    scanf("%d",&switchCmd);
    switch(switchCmd){
        case 1:
        celsiusToF();
        break;
        case 2:
        fahrenheitToC();
        break;
        default:
        printf("That is not an option");
        break;
    }
}