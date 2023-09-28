/* Calculate total profit
Tyler Bazemore
1/13/2023
COP3223C*/

#include <stdio.h>
int main() {
    float total_revenue, total_cost;

    printf("Enter total revenue:");
    scanf("%f", &total_revenue);

    printf("Enter total cost:");
    scanf("%f", &total_cost);

    printf("Your profit is $");
    printf("%.2f", total_revenue - total_cost);
    printf("\n");
    return 0;
}