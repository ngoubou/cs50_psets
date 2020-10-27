#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    
    // prompt the user to enter a positive float; 
    //if he fails to, re-prompt him for a valid amount

    do
    {
        
        dollars = get_float("How much: ");
    }
    while (dollars < 0);
    int n = round(dollars * 100);
    // Go in the drawer and take the largest value
    // If it equals the user input, print 1
    // while the coin is inferior to the change (n), use it
    // and count the number of times you do an operation
    int num = 0;
    while (n >= 25)
    {
        n = n - 25;
        num++;
    }
    while (n < 25 && n >= 10)
    {
        n = n - 10;
        num++;
    }  
    while (n < 10 && n >= 05)
    {
        n = n - 05;
        num++;
    }
    while (n < 05 && n >= 01)
    {
        n = n - 01;
        num++;
    }
   
    printf("number of coins: %i\n", num);
}
