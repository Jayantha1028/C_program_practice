#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int board[100];
    int i;
    int a = 0, b = 0;
    int turn, count = 0;

    srand(time(NULL));

    // Initialize board
    for (i = 0; i < 100; i++)
        board[i] = i + 1;

    // Ladders
    board[2] = 38;
    board[8] = 31;
    board[21] = 42;
    board[28] = 84;
    board[36] = 44;
    board[51] = 67;
    board[71] = 91;
    board[78] = 98;
    board[87] = 94;

    // Snakes
    board[16] = 6;
    board[46] = 25;
    board[62] = 19;
    board[74] = 53;
    board[89] = 68;
    board[92] = 88;
    board[95] = 80;

    while (1) {
        turn = count % 2;
        int dice = rand() % 6 + 1;

        if (turn == 0) {
            a += dice;

            if (a > 100)
                a -= dice;
            else
                a = board[a - 1];

            printf("Player 1 rolled %d and is on square %d\n", dice, a);

            if (a == 100) {
                printf("\nPlayer 1 Wins!\n");
                break;
            }
        } else {
            b += dice;

            if (b > 100)
                b -= dice;
            else
                b = board[b - 1];

            printf("Player 2 rolled %d and is on square %d\n", dice, b);

            if (b == 100) {
                printf("\nPlayer 2 Wins!\n");
                break;
            }
        }

        if (dice == 6) {
            printf("Player %d gets another turn.\n\n", turn + 1);
            continue;
        }

        count++;

        if (count > 1000) {
            printf("Game Drawn!\n");
            break;
        }

    }

    return 0;
}