<<<<<<< HEAD
/* Lab2 Speeding ticket
Tyler Bazemore
2/6/2023
COP3223C*/
#include <stdio.h>
int main() {
    int speed = 0, speedLimit;
    printf("What speed were you going and what was the speed limit:");
    scanf("%d %d", &speedLimit, &speed);
    if (speed - speedLimit <= -10){
        printf("50");
    }
    else if (speed - speedLimit  >= 6 && speed - speedLimit < 21){
        printf("75");
    }
    else if (speed - speedLimit  >= 21 && speed - speedLimit  < 40){
        printf("150");
    }
    else if (speed - speedLimit  >= 40){
        printf("300");
    }
    else{
        printf("0");
    }
    return 0;
=======
/* Lab2 Speeding ticket
Tyler Bazemore
2/6/2023
COP3223C*/
#include <stdio.h>
int main() {
    int speed = 0, speedLimit;
    printf("What speed were you going and what was the speed limit:");
    scanf("%d %d", &speedLimit, &speed);
    if (speed - speedLimit <= -10){
        printf("50");
    }
    else if (speed - speedLimit  >= 6 && speed - speedLimit < 21){
        printf("75");
    }
    else if (speed - speedLimit  >= 21 && speed - speedLimit  < 40){
        printf("150");
    }
    else if (speed - speedLimit  >= 40){
        printf("300");
    }
    else{
        printf("0");
    }
    return 0;
>>>>>>> b756d6d (Updating repositroy using git)
}