#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
string print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    // printf("%i\n", candidates[0].votes);
    // printf("%i\n", candidates[1].votes);
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
        //printf("%i\n", vote(name));
        //printf("%i\n", candidates[i].votes);
        //printf("%s\n", candidates[i].name);
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote

// A priori, the below function works
bool vote(string name)
{
    // Linear search: go through all candidates names
    // if it equals name of vote, increment vote count

    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(name, candidates[j].name) == 0)
        {
            candidates[j].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
string print_winner(void)
{
    // Sort the array in descending order
    while (candidates[0].votes < candidates[1].votes || candidates[1].votes < candidates[2].votes || candidates[2].votes < candidates[3].votes ||
            candidates[3].votes < candidates[4].votes || candidates[4].votes < candidates[5].votes || candidates[5].votes < candidates[6].votes ||
            candidates[6].votes < candidates[7].votes || candidates[7].votes < candidates[8].votes)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            // The last condition accounts for memory issues so it doesn't access elements not in array
            if (candidates[i].votes <= candidates[i+1].votes && i+1 < candidate_count)
            {
                int tmp = candidates[i].votes;
                string tmp_names = candidates[i].name;

                candidates[i].votes = candidates[i+1].votes;
                candidates[i].name = candidates[i+1].name;

                candidates[i+1].votes = tmp;
                candidates[i+1].name = tmp_names;
            }
        }
    }

    printf("%s\n", candidates[0].name);
    // Handling ties
    for (int i = 1; i < candidate_count; i++)
    {
        if (candidates[0].votes == candidates[i].votes)
        {
            printf("%s\n",candidates[i].name);
        }
    }
    return 0;
}
