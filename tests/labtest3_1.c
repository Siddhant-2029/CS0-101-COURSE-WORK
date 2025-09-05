// #include<stdio.h>
// int main(){
//     printf("enter n: ");
//     int n;
//     scanf("%d",&n);
//     printf(" ");
//     for(int i=1;i<=n;i++){printf("  %4d",i);}
//     printf("\n");
//     int m=n-1;
//     for(int i=1;i<=n;i++){
//           printf("%d  ",i);
//            int k=i;
//            m++;
//        while(m--){
//             printf("%4d  ",k++);
//         }
//         printf("\n");
//     }
// }
#include<stdio.h>
int main(){
     printf("enter n: ");
     int n;
      scanf("%d",&n);
      printf("    ");
      for(int i=1;i<=n;i++){printf("%4d",i);}
      printf("\n");
      for(int i=1;i<=n;i++){
        int j=i;
        printf("%4d",i);
        for(int k=1;k<=n;k++){
            printf("%4d",j);
            j=j+i;
        }
        printf("\n");
      }
}