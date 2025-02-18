#include <stdio.h>
#include <stdlib.h>

// Function to alternate between X and O
char turn(int turn) {
    return (turn % 2 == 0) ? 'X' : 'O';
}

// Function to display the board
void board(char plots[]) {
    printf("|%c|%c|%c|\n|%c|%c|%c|\n|%c|%c|%c|\n", 
            plots[0], plots[1], plots[2], 
            plots[3], plots[4], plots[5], 
            plots[6], plots[7], plots[8]);
}

// Function to check if a move has been repeated
int checkRepeat(char plots[], int choice) {
    return (plots[choice] == 'X' || plots[choice] == 'O');
}

// Function to check if a player has won
int checkWin(char plots[]) {
    int winConditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };
    
    for (int i = 0; i < 8; i++) {
        if (plots[winConditions[i][0]] == plots[winConditions[i][1]] &&
            plots[winConditions[i][1]] == plots[winConditions[i][2]]) {
            return 1;
        }
    }
    return 0;
}

// Function to ask for rematch
int rematch() {
    int choice;
    printf("Do you want to play again?\n1 - Yes\n2 - No\n");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Rematch!\n");
        return 1; // Continue playing
    }
    
    printf("Thanks for playing!\n");
    return 0; // End game
}

// Game function
void game() {
    int score[] = {0, 0}; // X and O scores

    while (1) {
        char plots[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
        int choice, count = 0;
    
        while (count < 9) {
            board(plots);
            printf("Player %c, enter your choice: ", turn(count));
            scanf("%d", &choice);
        
            if (choice < 0 || choice > 8) { 
                printf("Invalid move! Try again.\n");
                continue;
            }

            if (checkRepeat(plots, choice)) {
                printf("Move already taken! Try again.\n");
                continue;
            }
        
            plots[choice] = turn(count);
        
            if (checkWin(plots)) {
                board(plots);
                printf("Player %c wins!\n", turn(count));
                score[count % 2]++;
                printf("Score: X - %d, O - %d\n", score[0], score[1]);
                break;
            }
            count++;

            if (count == 9) { // Draw condition
                board(plots);
                printf("It's a draw!\n");
                printf("Score: X - %d, O - %d\n", score[0], score[1]);
            }
        }

        if (!rematch()) {
            break; // Exit game loop if the user chooses not to rematch
        }
    }
}

// Main function
int main() {
    printf("Welcome to Tic Tac Toe!\nLet's get started!\n");
    game();
    return 0;
}
