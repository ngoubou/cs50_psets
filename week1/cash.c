#include <cs50.h>
#include <stdio.h>
#include <math.h>

/*
 * Author: Lionel Ngoubou
 * Purpose: Greedy Algorithm implementation :
 Return the minimum number of coins needed for a change.
 */

int main(void)
{
    float dollars;
    
    // prompt the user to enter a positive float; 
    // if he fails to, re-prompt him for a valid input

    do
    {
        
        dollars = get_float("How much: ");
    }
    while (dollars < 0);
    // to handle float imprecision, we round the value to 100
    int change = round(dollars * 100);
    // as long as the change is greater or equals to the largest coin, use it
    // and count the number of times you do an operation, ie number of coins used
    int coins = 0;
    while (change >= 25)
    {
        change = change - 25;
        coins++;
    }
    while (change >= 10)
    {
        change = change - 10;
        coins++;
    }  
    while (change >= 5)
    {
        change = change - 5;
        coins++;
    }
    while (change >= 1)
    {
        change = change - 1;
        coins++;
    }
   
    printf("number of coins: %i\n", coins);
}
