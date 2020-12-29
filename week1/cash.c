#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
/*
 * Author: Lionel Ngoubou
 * Purpose: Greedy Algorithm implementation :
 Return the minimum number of coins needed for a change.
 */

//Update : Improved my solution using array and a for loop

// Number of values in my array
const int N = 4;

int main(void)
{

    // Prompt the user to enter a positive float;
    // if he fails to, re-prompt him for a valid input
    float dollars;
    do
    {
        dollars = get_float("How much: ");
    }
    while (dollars < 0);

    // To handle float imprecision, we round the value to 100
    int change = round(dollars * 100);

    int coins = 0;
    int array[] = {25, 10, 5, 1};
 
    // Minimum number of coins at each iteration is given by the quotient
    // The updated change is the remainder of the division
    for (int i = 0; i < N; i++)
    {
        while (change >= array[i])
        {
            coins += change / array[i];
            change %= array[i];
        }
    }

    printf("Number of coins: %i\n", coins);
}
