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
    int highest_vote = candidates[0].votes;
    //int tie = candidates[0].votes;
    string highest_name;
    string tie[candidate_count];

    // Starting the loop at 1, it was printing the last vote entered
    // even if it had not the most votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= highest_vote)
        {
            highest_vote = candidates[i].votes;
            highest_name =  candidates[i].name;
        }

    }

    printf("%s\n", highest_name);
    return 0;
}

