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
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt user to enter a string
    string text = get_string("Text: ");

    // Letters and sentences per 100 words
    float l = (100 * (float) count_letters(text)) / (float) count_words(text);
    float s = (100 * (float) count_sentences(text)) / (float) count_words(text);
    
    // Coleman-Liau index formula
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

int count_letters(string text)
{
    int len = strlen(text);
    int letters = 0;

    for (int i = 0; i != len; i++)
    {
        if (!isspace(text[i]) && isalnum(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    int len = strlen(text);
    int words = 0;

    for (int i = 0; i != len; i++)
    {
        if (isspace(text[i]) && !isalnum(text[i]))
        {
            words++;
        }

    }
    return words + 1;
}

int count_sentences(string text)
{
    int len = strlen(text);
    int sent = 0;

    for (int i = 0; i != len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sent++;
        }
    }
    return sent;
}
