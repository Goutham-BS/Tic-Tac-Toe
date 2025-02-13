#include <stdio.h>

//To alternate between X and O
char turn(int c) {
    return (c % 2 == 0) ? 'X' : 'O';
}

//Game board
void board(char plots[]) {
    printf("|%c|%c|%c|\n|%c|%c|%c|\n|%c|%c|%c|\n", 
            plots[0], plots[1], plots[2], 
            plots[3], plots[4], plots[5], 
            plots[6], plots[7], plots[8]);
}

//Main function
int main() {
    char plots[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    int choice, count = 0;
    
    while (1) {
        board(plots);
        printf("Player %c, enter a choice: ", turn(count));
        scanf("%d", &choice);

        if (choice < 0 || choice > 8) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        plots[choice] = turn(count);
        count++;
    }  
    return 0;
}
