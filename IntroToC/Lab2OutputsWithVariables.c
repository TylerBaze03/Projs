/* Lab2 Output with Variables
Tyler Bazemore
1/18/2023
COP3223C*/

#include <stdio.h>
int main() {
    int num1, num2;
    printf("Enter integer:");
    scanf("%i", &num1);
    printf("You entered %i\n%i squared is %i", num1, num1, num1*num1);
    printf("\nEnter another integer");
    scanf("%i", &num2);
    printf("%i + %i is %i\n%i * %i is %i", num1, num2, num1+num2, num1, num2, num1*num2);
    return 0;
}