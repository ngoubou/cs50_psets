#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*
 * Author: Lionel Ngoubou
 * Purpose: Coleman-Liau index implementation :
  Compute the approximate grade level needed to comprehend some text
 */

int main(void)
{
    // prompt user to enter a string
    string text = get_string("Text: ");

    // number of letters
    int len = strlen(text);
    int letters = 0;
    for (int i = 0; i != len; i++)
    {
        if (!isspace(text[i]) && isalnum(text[i]))
        {
            letters++;
        }
    }

    // number of words
    int words = 1;
    for (int i = 0; i != len; i++)
    {
        if (isspace(text[i]) && !isalnum(text[i]))
        {
            words++;
        }
    }

    // number of sentences
    int sentences = 0;
    for (int i = 0; i != len; i++)
    {
        // number of sentences
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }

    //letters and sentences per 100 words
    float l = (100 * (float) letters) / (float) words;
    float s = (100 * (float) sentences) / (float) words;

    int index = round(0.0588 * l - 0.296 * s - 15.8);


    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}


