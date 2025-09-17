#include <stdio.h>

int main() {
    printf("For first matrix enter rows and columns respectively:\n");
    int n, m;
    scanf("%d %d", &n, &m);
    printf("For second matrix enter rows and columns respectively:\n");
    int p, q;
    scanf("%d %d", &p, &q);
    if (m != p) {
        printf("Can't multiply");
        return 0;
    }
    int mat_1[n][m], mat_2[p][q], mat_ans[n][q];

   printf("Enter elements of matrix 1 ");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)        
            scanf("%d", &mat_1[i][j]);

    printf("Enter elements of matrix 2 ");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            scanf("%d", &mat_2[i][j]);


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            mat_ans[i][j] = 0;
            for (int k = 0; k < m; k++) {
                mat_ans[i][j] += mat_1[i][k] * mat_2[k][j];
            }
        }
    }

    printf("Resultant Matrix (%d x %d):\n", n, q);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < q; j++) {
            printf("%4d ", mat_ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}
