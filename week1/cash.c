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

    // As long as the change is greater or equals to the largest coin, use it
    // and count the number of times you do an operation, ie number of coins used
    int coins = 0;
    string array[] = {"25", "10", "5", "1"};

    for (int i = 0; i < N; i++)
    {
        while (change >= atoi(array[i]))
        {
            change = change - atoi(array[i]);
            coins++;
        }
    }

    printf("Number of coins: %i\n", coins);
}
