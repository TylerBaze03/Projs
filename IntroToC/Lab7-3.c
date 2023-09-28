/* Lab 7-2
Tyler Bazemore
2/25/2023
COP3223C*/
#include <stdio.h>
int main() {
    int  x, i, a, num,y, length;
    int myNumbers[20];
    printf("How man numbers do you want to input between 1 and 20?");
    scanf("%d", &length);
    for (i = 0; i < length; ++i){
        printf("Input a number:");
        scanf("%d", &myNumbers[i]);
    }
    for (x = 0; x < length;  ++x){
        for (a = x + 1; a < length; ++a){
            if (myNumbers[a] > myNumbers[x]){
                num = myNumbers[a];
                myNumbers[a] = myNumbers[x];
                myNumbers[x] = num;
            }
        }
    }
    for (y = 0; y < i; ++y){
    printf("%d,", myNumbers[y]);
    }

return 0;
}