#include <stdbool.h>
#include <stdio.h>

// takes input of the board and returns true if the game was won and false if not
bool determine_game_won(char board[]) {
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ') {
        // If top is all x's or all o's game was won
        return true;
    } else if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ') {
        // if left is all x's or all o's game was won
        return true;
    } else if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ') {
        // if top left to bottom right is all x's or all o's game was won
        return true;
    } else if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ') {
        // if middle column is all x's or all o's game was won
        return true;
    } else if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ') {
        // if right column is all x's or all o's game was won
        return true;
    } else if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ') {
        // if top right to bottom left is all x's or all o's game was won
        return true;
    } else if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ') {
        // if middle row is all x's or all o's game was won
        return true;
    } else if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ') {
        // if bottom row is all x's or all o's game was won
        return true;
    } else {
        // game was not won
        return false;
    }
}

// prints the board
void print_board(char board[]) {
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
}

int main() {
    // initially set game_won to false since it has not been initialized yet
    bool game_won = false;
    // initialize the board
    char board[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    // create a board showing the moves
    char key_board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    print_board(key_board);
    // initialize the turn to 0
    int turn = 0;
    // main game loop
    while (turn < 10 || game_won == false) {
        // print the board
        print_board(board);
        // initialize an empty variable to store the move
        int move;
        // prompt the user for a move
        printf("Enter a move: ");
        scanf("%d", &move);
        if (board[move] == ' ') {
            if (turn % 2 == 0) {
                board[move] = 'X';
            } else {
                board[move] = 'O';
            }
            turn++;
        } else {
            printf("Invalid move\n");
        }
        game_won = determine_game_won(board);
        if (game_won) {
            if (turn % 2 == 0) {
                printf("O wins\n");
            } else {
                printf("X wins\n");
            }
        }
    }
    return 0;
}