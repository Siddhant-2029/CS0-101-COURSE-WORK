#include<stdio.h>
int main(){
    int a=2,b=4,c=8;
    if(a>b && b>c ){printf("The 2nd greatest is b");}
    else if(b>c && c>a){printf("The 2nd greatest is c");}
    else if(c>a && a>c) {printf("The 2nd greatest is a");}
    return 0;
}
