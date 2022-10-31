#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
// constant with value 9
#define MAX 9

// Candidates have name and vote count
typedef struct {
  string name;
  int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[]) {
  // Check for invalid usage
  if (argc < 2) {
    printf("Usage: plurality [candidate ...]\n");
    return 1;
  }

  // Populate array of candidates
  candidate_count = argc - 1;
  if (candidate_count > MAX) {
    printf("Maximum number of candidates is %i\n", MAX);
    return 2;
  }
  for (int i = 0; i < candidate_count; i++) {
    candidates[i].name = argv[i + 1];
    candidates[i].votes = 0;
  }

  int voter_count = get_int("Number of voters: ");

  // Loop over all voters
  for (int i = 0; i < voter_count; i++) {
    string name = get_string("Vote: ");

    // Check for invalid vote
    if (!vote(name)) {
      printf("Invalid vote.\n");
    }
  }

  // Display winner of election
  print_winner();
}

// Update vote totals given a new vote
bool vote(string name) {

  //TODO
  // Linear Search
  for (int i = 0; i < candidate_count; i++) {

    string candidate_name = candidates[i].name;

    if (strcmp(candidate_name, name) == 0) {
      candidates[i].votes += 1;
      return true;
    } 

  }

  return false;
}

// Print the winner (or winners) of the election
void print_winner(void) {

  // TODO
  // Order the candidates list by ascendent order
  // Bubble Sort
  int swap_count = -1;

  while (swap_count != 0) {
    swap_count = 0;   

    for (int i = 0; i < candidate_count - 1; i++) {

      if (candidates[i].votes > candidates[i+1].votes) {
        candidate temp = candidates[i];

        candidates[i] = candidates[i+1];
        candidates[i+1] = temp;

        swap_count += 1;
      }

    }
  }

  // The candidates array now is sorted, so the winner or winners should be in the last positions
  int winner_votes = candidates[candidate_count-1].votes;

  // Look if there is more than 1 candidate that have the same numbers of votes and printed
  // Linear Search
  for (int i = 0; i < candidate_count - 1; i++) {
    if (winner_votes == candidates[i].votes) {
      printf("%s\n", candidates[i].name);
    }   
  }

  // Print the first winner
  printf("%s\n", candidates[candidate_count-1].name);

  return;
}
