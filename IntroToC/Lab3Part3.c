/* Lab2 Part3 Simple Statistics
Tyler Bazemore
1/29/2023
COP3223C*/
#include <stdio.h>
int main() {
    int num1, num2, num3, num4;
    printf("Input integers:");
    scanf("%i %i %i %i", &num1, &num2, &num3, &num4);
    double productFloat = (double)num1 * (double)num2 * (double)num3 * (double)num4;
    double averageFloat = ((double)num1 + (double)num2 + (double)num3 + (double)num4)/4;
    printf("%i %i\n%.3lf %.3lf", num1 * num2 * num3 * num4, (num1 + num2 + num3 + num4)/4, productFloat, averageFloat);
    return 0;
}