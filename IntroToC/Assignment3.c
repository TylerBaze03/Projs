/* Assignment 3 Shipping Calculator
Tyler Bazemore
1/28/2023
COP3223C*/
#include <stdio.h>
#include <math.h>
int main() {
    double distance;
    double weight, cost;
    printf("Input the weight:");
    scanf("%lf", &weight);
    printf("Input the distance:");
    scanf("%lf", &distance);
    if (weight >= 50)
    {
        printf("Sorry, we only ship packages of 50 pounds or less");
    }
    else
    {
        if (weight <= 10)
        {
            if (distance > 1000)
            {
                distance = ceil(distance/500);
                cost = ((distance * 3.00) + 10);
                printf("Your shipping charge is $%.2lf", cost);
            }
            else
            {
                distance = ceil(distance/500);
                cost = ((distance * 3.00));
                printf("Your shipping charge is $%.2lf", cost);
            }
        }
        else
        {
            if (distance > 1000)
            {
                distance = ceil(distance/500);
                cost = (((distance) * 5.00)+10);
                printf("Your shipping charge is $%.2lf", cost);
            }
            else
            {
                distance = ceil(distance/500);
                cost = ((distance) * 5.00);
                printf("Your shipping charge is $%.2lf", cost);
            }
        }
    }
    return 0;
}