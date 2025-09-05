#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int m=n-1;
    printf(" ");
    for(int i=1;i<=n;i++){printf("  %d",i);}
    printf("\n");
    for(int i=1;i<=n;i++){
          printf("%d  ",i);
           int k=i;
           m++;
        for(int j=i;j<=m;j++){
            printf("%d  ",k++);
        }
        printf("\n");
    }
}