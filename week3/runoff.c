#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

//Recall that for a voter i, their top choice candidate is represented by preferences[i][0], their second choice candidate by preferences[i][1], etc.

// I did not handle “instant runoff” in my function
// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Update vote counts for non-eliminated candidates
    for (int voter = 0; voter < voter_count; voter++)
    {
        for (int choice = 0; choice < candidate_count; choice++)
        {
            if (preferences[voter][0] == choice)
            {
                candidates[choice].votes += 1;
                //candidates[voter].eliminated = false;
                //break;
            }
        }

    }

    // Create an array that stores candidates‘ names
    // before they are sorted
    // then compare those names to the ones in the sorted array
    // if candidates[i].name == test[i].names
    //        test[i].eliminated == candidates[i].eliminated

    string name[candidate_count];
    int votes[candidate_count];
    bool eliminated[candidate_count];

    for (int i = 0; i < candidate_count; i++)
    {
         name[i] = candidates[i].name;
         votes[i] = candidates[i].votes;
         //eliminated[i] = candidates[i].eliminated;
    }




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


    // Eliminate the candidates with fewest votes
    for (int j = 1; j < candidate_count; j++)
    {
        if (candidates[0].votes == candidates[j].votes)
        {
            candidates[j].eliminated = false;
        }
        else
        {
            candidates[j].eliminated = true;

        }
    }

       
    /* handling second round */
    
       // voter whose top choice is eliminated
       // eliminated candidate who was top choice

// If no candidate has more than 50% of the vote, then an “instant runoff” occurrs.
// The candidate who received the fewest number of votes is eliminated from the election,
// and anyone who originally chose that candidate as their first preference now has their second preference considered.

// Recall that for a voter i, their top choice candidate is represented by preferences[i][0], their second choice candidate by preferences[i][1], etc.

// :( tabulate handles multiple rounds of preferences
// Recall that at each stage in the runoff, every voter effectively votes for their top-preferred candidate who has not already been eliminated.

    // mettre ça dans une while loop
    // en mettant comme condition tant que il y a un eliminated qui est true
    
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (name[i] == candidates[j].name)
            {
                eliminated[i] = candidates[j].eliminated;
            }
        }
    }
    
    for (int j = 0; j < voter_count; j++)
        for (int k = 0; k < candidate_count; k++)

            if (eliminated[k] == true && preferences[j][0] == k)
            {
                votes[preferences[j][0]] -= 1;
                preferences[j][0] = preferences[j][1];
                //printf("%i\n", );
                votes[preferences[j][0]] += 1;
                break;
                //eliminated[preferences[j][1]] = true;
            }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (name[i] == candidates[j].name)
            {
                // changer le i pour j pour égalité de gauche
                candidates[j].votes = votes[i];
            }
        }
    }
    
    // Eliminate the candidates with fewest votes 2nd round
    for (int j = 1; j < candidate_count; j++)
    {
        if (candidates[0].votes == candidates[j].votes)
        {
            candidates[j].eliminated = false;
        }
        else
        {
            candidates[j].eliminated = true;

        }
    }
    
  

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void) //*
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes >= candidates[i + 1].votes)
        {
            return candidates[i].votes;
        }
    }

    return 0;
}

// Recall that a tie happens if every candidate still in the election has the same number of votes. 
// Note, too, that the is_tie function takes an argument min, which is the smallest number of votes any candidate currently has.
//How might you use that information to determine if the election is a tie (or, conversely, not a tie)?

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 1; i < candidate_count; i++)
    {
        // :) is_tie detects tie after some candidates have been eliminated
        // if (candidates[0].votes == min && candidates[0].votes == candidates[i].votes) 
        
        // :) is_tie returns false when only some of the candidates are tied
        if (candidates[0].votes == candidates[i].votes && candidates[0].votes == candidates[candidate_count - 1].votes)
        {
            //printf("%s\n",candidates[i].name);
            return true;
        }
    }

    return false;
}

//:( eliminates multiple candidates in tie for last

// Eliminate the candidate (or candidates) in last place
void eliminate(int min) //*
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    // TODO
    return;
}
