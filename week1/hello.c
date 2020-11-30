#include <cs50.h>
#include <stdio.h>

/*
 * Author: Lionel Ngoubou
 * Purpose: Greet a user by his name.
 */

int main(void)
{
    // Prompt user for their name
    string name = get_string("What is your name\n");
    printf("Hello, %s\n", name);
}
