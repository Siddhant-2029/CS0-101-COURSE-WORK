#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[10];
char topNames[3][3][30];  
int topScores[3][3];      

void menu();
void playRPS();
void playTTT();
void playGuess();
void drawBoard();
int checkWin();
void saveScore(char *gameName, char *playerName, int score);
void showScores();
void resetScores();

int main() {
    srand(time(NULL));
    menu();
    return 0;
}

void menu() {
    int choice;
    while (1) {
         printf("\n-----------------------------------------\n");
         printf("             MINI  ARCADE\n");
         printf("---------------------------------------\n");
      printf("1. Play Rock-Paper-Scissors\n");
        printf("2. Play Tic-Tac-Toe\n");
    printf("3. Play Number Guessing\n");
            printf("4. View High Scores\n");
        printf("5. Reset High Scores\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) playRPS();
 else if (choice == 2) playTTT();
 else if (choice == 3) playGuess();
 else if (choice == 4) showScores();
 else if (choice == 5) resetScores();
 else if (choice == 6) {
            printf("Thanks for playing!\n");
            break;
        } else {
            printf("Invalid input. Try again.\n");
        }
    }
}

void playRPS() {
    char name[30];
    int wins = 0, i, user, comp;
    printf("\n-----------------------------------------\n");
    printf("         ROCK-PAPER-SCISORS\n");
    printf("-----------------------------------------\n");
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Game has 10 rounds. Rock=1 Paper=2 Scisors=3\n");

    for (i = 1; i <= 10; i++) {
        printf("\nRound %d - Enter choice (1-3): ", i);
        scanf("%d", &user);
        comp = rand() % 3 + 1;
        printf("Computer chose: %d\n", comp);

        if (user == comp)
            printf("Draw!\n");
        else if ((user == 1 && comp == 3) || (user == 2 && comp == 1) || (user == 3 && comp == 2)) {
            printf("You win this round!\n");
            wins++;
        } else
            printf("Computer wins this round!\n");}

int score = wins * 10;
printf("Game over! You won %d rounds.\nYour score: %d/100\n", wins, score);
saveScore("Rock-Paper-Scissors", name, score);
}

void playTTT() {
    char name1[30], name2[30];
    int game, move, turn, i, moves;
    int p1Wins = 0, p2Wins = 0;

    printf("\n-----------------------------------------\n");
    printf("              TIC-TAC-TOE\n");
    printf("-----------------------------------------\n");
    printf("Enter Player1: ");
    scanf("%s", name1);
    printf("Enter Player2: ");
    scanf("%s", name2);

    for (game = 1; game <= 10; game++) {
        for (i = 1; i <= 9; i++) board[i] = '0' + i;
        turn = 1;
        moves = 0;
        printf("\nGame %d\n", game);

        while (1) {
            drawBoard();
            printf("%s (%c), enter your move (1-9): ", (turn == 1 ? name1 : name2), (turn == 1 ? 'X' : 'O'));
            scanf("%d", &move);

            if (move < 1 || move > 9 || board[move] == 'X' || board[move] == 'O') {
                printf("Invalid move. Try again.\n");
                break;
            }

            board[move] = (turn == 1) ? 'X' : 'O';
            moves++;

            if (checkWin()) {
                drawBoard();
                printf("Winner: %s\n", (turn == 1 ? name1 : name2));
                if (turn == 1) p1Wins++;
                else p2Wins++;
                break;
            }

            if (moves == 9) {
                drawBoard();
                printf("It's a draw!\n");
                break;
            }

            turn = 3 - turn;
        }
    }

    printf("\nFinal Results: %s won %d, %s won %d\n", name1, p1Wins, name2, p2Wins);

    int score;
    if (p1Wins > 5) {
        score = p1Wins * 10;
        printf("Player1 (%s) goes to high scores with %d/100\n", name1, score);
        saveScore("Tic-Tac-Toe", name1, score);
    } else if (p1Wins < 5) {
        score = p2Wins * 10;
        printf("Player2 (%s) goes to high scores with %d/100\n", name2, score);
        saveScore("Tic-Tac-Toe", name2, score);
    } else {
        score = p1Wins * 10;
        printf("Tie! Both players go to high scores.\n");
        saveScore("Tic-Tac-Toe", name1, score);
        saveScore("Tic-Tac-Toe", name2, score);
    }
}


void playGuess() {
    char name[30];
    int num = rand() % 100 + 1;
    int guess, tries = 0;

    printf("\n-----------------------------------------\n");
    printf("           NUMBER GUESSING GAME\n");
    printf("-----------------------------------------\n");
    printf("Enter your name: ");
    scanf("%s", name);

    while (1) {
        printf("Guess a number (1-100): ");
        scanf("%d", &guess);
        tries++;

        if (guess > num)
            printf("Too high! Try again.\n");
        else if (guess < num)
            printf("Too low! Try again.\n");
        else {
            printf("Correct! You guessed it in %d tries!\n", tries);
            int score = 100 - (tries - 1) * 5;
            if (score < 0) score = 0;
            printf("Your score: %d/100\n", score);
            saveScore("Number Guessing", name, score);
            break;
        }
    }
}

void drawBoard() {
    printf("\n %c | %c | %c\n", board[1], board[2], board[3]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[4], board[5], board[6]);
    printf("-----------\n");
    printf(" %c | %c | %c\n\n", board[7], board[8], board[9]);
}

int checkWin() {
    if (board[1]==board[2] && board[2]==board[3]) return 1;
    if (board[4]==board[5] && board[5]==board[6]) return 1;
    if (board[7]==board[8] && board[8]==board[9]) return 1;
    if (board[1]==board[4] && board[4]==board[7]) return 1;
    if (board[2]==board[5] && board[5]==board[8]) return 1;
    if (board[3]==board[6] && board[6]==board[9]) return 1;
    if (board[1]==board[5] && board[5]==board[9]) return 1;
    if (board[3]==board[5] && board[5]==board[7]) return 1;
    return 0;
}

void saveScore(char *gameName, char *playerName, int score) {
    int gameIndex = -1;

    if (gameName[0] == 'R') gameIndex = 0;      
    else if (gameName[0] == 'T') gameIndex = 1; 
    else if (gameName[0] == 'N') gameIndex = 2; 

    if (gameIndex == -1) return;

    int i, j;
    for (i = 0; i < 3; i++) {
        if (score > topScores[gameIndex][i]) {
            
            for (j = 2; j > i; j--) {
                topScores[gameIndex][j] = topScores[gameIndex][j - 1];
                int k;
                for (k = 0; k < 30; k++)
                    topNames[gameIndex][j][k] = topNames[gameIndex][j - 1][k];
            }
            topScores[gameIndex][i] = score;
            for (j = 0; j < 30; j++) {
                topNames[gameIndex][i][j] = playerName[j];
                if (playerName[j] == '\0') break;
            }
            break;
        }
    }
}

void showScores() {
    int i, g;
    char *games[3] = {"Rock-Paper-Scissors", "Tic-Tac-Toe", "Number Guessing"};
    printf("\n-----------------------------------------\n");
    printf("              HIGH SCORES\n");
    printf("-----------------------------------------\n");
    for (g = 0; g < 3; g++) {
        printf("\nGame: %s\n", games[g]);
        printf("Rank\tName\tScore\n");
        for (i = 0; i < 3; i++) {
            if (topScores[g][i] > 0)
                printf("%d\t%s\t%d\n", i + 1, topNames[g][i], topScores[g][i]);
        }
    }
}

void resetScores() {
    int g, i, j;
    for (g = 0; g < 3; g++) {
        for (i = 0; i < 3; i++) {
            topScores[g][i] = 0;
            for (j = 0; j < 30; j++) topNames[g][i][j] = '\0';
        }
    }
    printf("All high scores reset!\n");
}
