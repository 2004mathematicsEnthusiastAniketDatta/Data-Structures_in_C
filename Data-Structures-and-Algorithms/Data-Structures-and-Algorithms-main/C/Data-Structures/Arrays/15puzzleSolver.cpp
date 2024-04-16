#include <stdio.h>
#include <time.h>

#define MAX_FILE_LENGTH 30
#define PUZZLE_SIDE 4
#define EMPTY_SLOT 0

void loadPuzzle(int puzzle[][PUZZLE_SIDE], FILE *fin);
int getMove();
void printPuzzle(int puzzle[][PUZZLE_SIDE]);
int doMove(int puzzle[][PUZZLE_SIDE], int move);
void swap(int *a, int *b);
int solved(int puzzle[][PUZZLE_SIDE]);

int main() {

int puzzle[PUZZLE_SIDE][PUZZLE_SIDE];
char filename[MAX_FILE_LENGTH+1];
int ans;

//srand(time(0));

printf("Welcome to the PUZZLE-15 game!\n");

// Get the puzzle file.
printf("Enter the file storing all of the puzzle configurations.\n");
scanf("%s", filename);

while (ans != 2) {

FILE *fin;
fin = fopen(filename, "r");

// Load the puzzle.
loadPuzzle(puzzle, fin);
fclose(fin);

// Let's play!
int move;

printPuzzle(puzzle);
move = getMove();

// Keep on playing until the user gives up.
while (move!=0) {

// Execute this move, seeing if it's okay.
int okay = doMove(puzzle, move);

// Print an error message for an invalid move.
if (!okay) {
printf("Sorry, that is not a valid square to slide into ");
printf(" the open slot.\nNo move has been executed.\n");
}

// Get out of the game for a winning move!
else if (solved(puzzle))
break;

// Go get the next move.
printPuzzle(puzzle);
move = getMove();
}

// Output an appropriate puzzle ending message.
if (move != 0)
printf("Great, you solved the puzzle!!!\n");
else
printf("Sorry, looks like you gave up on the puzzle.\n");

// Get their next selection.
printf("Which selection would you like?\n");
printf("1. Load a new puzzle.\n");
printf("2. Quit.\n");
scanf("%d", &ans);
}

}

// Pre-conditions: fin is pointed to the beginning of a file with a valid
// file format for this problem.
// Post-conditions: A random puzzle from the file pointed to by fin will be
// stored in puzzle.
void loadPuzzle(int puzzle[][PUZZLE_SIDE], FILE *fin) {

}

// Pre-conditions: none.
// Post-conditions: A basic menu will be prompted and the user's result returned.
int getMove() {

}

// Pre-conditions: A valid puzzle is stored in puzzle.
// Post-conditions: A depiction of the puzzle will be printed out.
void printPuzzle(int puzzle[][PUZZLE_SIDE]) {

}

// Pre-conditions: puzzle stores a valid puzzle configuration.
// Post-conditions: If move is a valid square to slide into the open slot,
// the move is executed and 1 is returned. Otherwise, 0
// is returned and no change is made to puzzle.
int doMove(int puzzle[][PUZZLE_SIDE], int move) {

}

// Pre-condition: none
// Post-condition: swaps the values in the variables pointed to by a and b.
void swap(int *a, int *b) {

}

// Pre-condition: puzzle stores a valid puzzle configuration.
// Post-condition: Returns 1 if puzzles is solved, 0 otherwise.
int solved(int puzzle[][PUZZLE_SIDE]) {

}
