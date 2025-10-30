#include <stdio.h>

int main() {
    int n;
    printf("Enter an odd integer N: ");
    scanf("%d", &n);

    if (n < 3 || n % 2 == 0) {
        printf("Error: N must be an odd integer \n");
        return 0;
    }

  int magicSquare[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = 0;

    int num = 1;
    int i = 0, j = n / 2;

    while (num <= n * n) {
        magicSquare[i][j] = num;

        int next_i = (i - 1 + n) % n; 
        int next_j = (j + 1) % n;    

        if (magicSquare[next_i][next_j] != 0) {
            i = (i + 1) % n; 
        } else {
            i = next_i;
            j = next_j;
        }

        num++;
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            printf("%4d ", magicSquare[x][y]);
        }
        printf("\n");
    }
   return 0;}
