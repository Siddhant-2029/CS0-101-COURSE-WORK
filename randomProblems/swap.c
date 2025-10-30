#include<stdio.h>
// int find_largest(int *a,int n){
//     int result=0;
//     for (int *i = &a; i =< &(a+1); i++)
//     {
//         result=max(result,*i);
//     }
//     return result;

//}

int main(){
    int n=10;
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int result;
    int *p ;
    p=&a[0];
    int (*c)[10];
    c = &a + 1;
    printf("%p  %p", p ,c);

}