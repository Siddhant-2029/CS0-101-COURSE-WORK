#include<stdio.h>
const int fixed_charge=150;
const float unit_charge= 5.5;
float calculateBill(int a);
void displayBill(char name[100],unsigned int,int);
int main(){
    char cstmr_name[100];
    unsigned int cstmr_id;
    int unit_consumed;
    printf("Size of int " "%d\n",  sizeof(int));
    printf("Size of float ""%d\n" ,sizeof(float));
    printf("Size of char " "%d\n",sizeof(char));
    printf("Enter customer id : \n");
    scanf("%d", &cstmr_id);
    printf("Enter customer name : \n");
    scanf("%s",&cstmr_name);
    printf("Enter unit consumed: \n" );
    scanf("%d", &unit_consumed);
    displayBill(cstmr_name,cstmr_id,unit_consumed);
}
float calculateBill(int a){
    return (fixed_charge+(unit_charge*a));
}
void displayBill(char name[100],unsigned int cstmr_id ,int unit_consumed){
    printf("Customer ID- " "%d\n" ,cstmr_id);
    printf("Customer name- " "%s\n" ,name);
    printf("Units Consumed- " "%d\n" ,unit_consumed);
    printf("Total Bill- Rs " "%.1f\n",calculateBill(unit_consumed));
}
