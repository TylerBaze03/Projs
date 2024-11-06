<<<<<<< HEAD
/* Lab 7-2
Tyler Bazemore
2/25/2023
COP3223C*/
#include <stdio.h>
int main() {
    int i = 0, x, input = 0, middle;
    int myNumbers[9];
    printf("Enter a number:");
    scanf("%d", &input);
    while (input > 0 && i <=9){
        myNumbers[i] = input;
        i++;
        printf("Enter a number:");
        scanf("%d", &input);
    }
    if (i == 10){
        printf("Too many numbers, the last number was not included\n");
        i--;
    }
    for (x = 0; x<i; x++){
        printf("%d\n", myNumbers[x]);
    
    }
    middle = i/2;
    printf("The middle number is %d", myNumbers[middle]);


return 0;
}
=======
/* Lab 7-2
Tyler Bazemore
2/25/2023
COP3223C*/
#include <stdio.h>
int main() {
    int i = 0, x, input = 0, middle;
    int myNumbers[9];
    printf("Enter a number:");
    scanf("%d", &input);
    while (input > 0 && i <=9){
        myNumbers[i] = input;
        i++;
        printf("Enter a number:");
        scanf("%d", &input);
    }
    if (i == 10){
        printf("Too many numbers, the last number was not included\n");
        i--;
    }
    for (x = 0; x<i; x++){
        printf("%d\n", myNumbers[x]);
    
    }
    middle = i/2;
    printf("The middle number is %d", myNumbers[middle]);


return 0;
}
>>>>>>> b756d6d (Updating repositroy using git)
2 3 4 8 11 -1 