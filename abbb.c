#include<stdio.h>
int main(){
    char character;
    scanf("%c", &character);
    if(character=='a' || character=='e' || character=='i' || character=='o' || character=='u'){printf("its a vovel");}
    else if(character=='A' || character=='E' || character=='I' || character=='O' || character=='U'){printf("its a vovel");}
    else if((character>=65 && character<=91) || (character>=97 && character<=123)  ){printf("its a consonent");}
    else printf("its a special chracter");
    return 0;
}