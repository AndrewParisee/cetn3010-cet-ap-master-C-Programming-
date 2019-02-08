/* This program is to show users how to calculate based on the input entered by a user while showing how to
 * allow the user to input.
 * Created by: Andrew Parisee.
 * Date: September 11, 2018.
 * Time: 2:01PM.*/
#include <stdio.h>

int main() {

    float PI = 3.14159f;
    int num1;
    int num2;

    //num1 = 5;
    //num2 = 5;
    printf("Please enter in Number 1: ");
    scanf("%i", num1);

    printf("Please enter in Number 2: ");
    scanf("%i", num2);

    printf("Number 1 = %i, Number 2 = %i, PI = %f\n", num1, num2, PI);

    return 0;
}