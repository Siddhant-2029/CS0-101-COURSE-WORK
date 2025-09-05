#include<stdio.h>
int main(){
    printf("enter n: ");
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int j=n-i+1;
        for(;j>0;){
            printf("%d ",j);
            j--;
        }
        printf("\n");
    }
    
}