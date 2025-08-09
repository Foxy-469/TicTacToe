#include <stdio.h>
#include <stdlib.h>

int input(char r1[4], char r2[4], char r3[4], char a) {
    int i = 0;
    scanf("%d", &i);
    if (i == 1 || i == 2 || i == 3) {
        i--;
        if (r1[i] != 'X' &&  r1[i] != 'O'){
            r1[i] = a;
        }
        else{
            printf("Wrong input\n");
            printf("Enter number: ");
            input(r1, r2, r3, a);
        }
    } else if (i == 4 || i == 5 || i == 6) {
        i = i - 4;
        if (r2[i] != 'X' && r2[i] != 'O'){
            r2[i] = a;
        }
        else{
            printf("Wrong input\n");
            printf("Enter number: ");
            input(r1, r2, r3, a);
        }

    } else if (i == 7 || i == 8 || i == 9) {
        i = i - 7;
        if (r3[i] != 'X' && r3[i] != 'O'){
            r3[i] = a;
        }
        else{
            printf("Wrong input\n");
            printf("Enter number: ");
            input(r1, r2, r3, a);
        }
   } else {
        printf("Wrong input\n");
        printf("Enter number: ");
        input(r1, r2, r3, a);
    }
}

int win_check(char r1[4], char r2[4], char r3[4]) {
    // Diagonal check
    if ((r1[0] == r2[1] && r2[1] == r3[2]) || (r1[2] == r2[1] && r2[1] == r3[0])) {
        return (r2[1] == 'O') ? 1 : 2;
    }

    // Row check
    if (r1[0] == r1[1] && r1[1] == r1[2]) {
        return (r1[0] == 'O') ? 1 : 2;
    } else if (r2[0] == r2[1] && r2[1] == r2[2]) {
        return (r2[0] == 'O') ? 1 : 2;
    } else if (r3[0] == r3[1] && r3[1] == r3[2]) {
        return (r3[0] == 'O') ? 1 : 2;
    }

    // Column check
    if (r1[0] == r2[0] && r2[0] == r3[0]) {
        return (r3[0] == 'O') ? 1 : 2;
    } else if (r1[1] == r2[1] && r2[1] == r3[1]) {
        return (r3[1] == 'O') ? 1 : 2;
    } else if (r1[2] == r2[2] && r2[2] == r3[2]) {
        return (r3[2] == 'O') ? 1 : 2;
    }

    return 0; // No winner yet
}

int game() {
    // Board creation
    char r1[4] = "123";
    char r2[4] = "456";
    char r3[4] = "789";

    // Game loop
    for (int j = 0; j < 9; j++) {
        // Board
        system("clear");
        printf("%c %c %c \n%c %c %c \n%c %c %c\n", r1[0], r1[1], r1[2], r2[0], r2[1], r2[2], r3[0], r3[1], r3[2]);

        // Player turn
        if (j % 2 == 0) {
            printf("Player 1 turn enter number: ");
            input(r1, r2, r3, 'O');
        } else {
            printf("Player 2 turn enter number: ");
            input(r1, r2, r3, 'X');
        }

        // Game status check
        int status = win_check(r1, r2, r3);
        if (status == 1) {
            system("clear");
            printf("%c %c %c \n%c %c %c \n%c %c %c\n", r1[0], r1[1], r1[2], r2[0], r2[1], r2[2], r3[0], r3[1], r3[2]);
            printf("Player 1 wins\n");
            return 0;
        } else if (status == 2) {
            system("clear");
            printf("%c %c %c \n%c %c %c \n%c %c %c\n", r1[0], r1[1], r1[2], r2[0], r2[1], r2[2], r3[0], r3[1], r3[2]);
            printf("Player 2 wins\n");
            return 0;
        } else if (j == 8) {
            system("clear");
            printf("%c %c %c \n%c %c %c \n%c %c %c\n", r1[0], r1[1], r1[2], r2[0], r2[1], r2[2], r3[0], r3[1], r3[2]);
            printf("Draw\n");
            return 0;
        }
    }
    return 0;
}

int main() {
    game();
    return 0;
}
