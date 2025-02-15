#include <stdio.h>

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
int check_repeat(char plots[], int choice) {
    return (plots[choice] == 'X' || plots[choice] == 'O'); // If any of these characters have been placed, no other player can place in here (duh)
}

// Function to check if a player has won
int check_win(char plots[]) {
    int win_conditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };
    
    for (int i = 0; i < 8; i++) {
        if (plots[win_conditions[i][0]] == plots[win_conditions[i][1]] &&
            plots[win_conditions[i][1]] == plots[win_conditions[i][2]]) {
            return 1;
        }
    }
    return 0; // No winner yet
}

// Main function
int main() {
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

        if (check_repeat(plots, choice)) {
            printf("Move already taken! Try again.\n");
            continue;
        }
        
        plots[choice] = turn(count);
        
        if (check_win(plots)) {
            board(plots);
            printf("Player %c wins!\n", turn(count));
            return 0;
        }
        count++;
    }
    
    board(plots);
    printf("It's a draw!\n");
    return 0;
}
