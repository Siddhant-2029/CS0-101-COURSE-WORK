#include<stdio.h>
#define PRICE_SILVER 180
#define PRICE_GOLD 250
#define PRICE_PLATINUM 320
#define PRICE_RECLINER 450
#define FEE_CONVENIENCE 20
#define PRICE_POPCORN 120
#define PRICE_WATER 20
#define GST_RATE 0.18
int main(){
    char name[31];
    char phone[11];
    int seatTypeCode;
    int perTicketPrice;
    int tickets;
    int popcornQty;
    int waterQty;
    double ticketSubtotal, bulkDiscount, afterDiscount, convenience, addons, taxable, gst,
            grandTotal,bulkrate;

    scanf("%s",&name);
    scanf("%d",&phone);
    scanf("%d",&seatTypeCode);
    scanf("%d",&tickets);
    scanf("%d",&popcornQty);
    scanf("%d",&waterQty);
    if (seatTypeCode!=1 && seatTypeCode !=2 && seatTypeCode!=3){printf("INVALID INPUT");
        return 0;}
    if(tickets<0 || tickets>12){printf("INVALID INPUT");
        return 0;}   
    if(popcornQty<0 || popcornQty>tickets){printf("INVALID INPUT");
        return 0;}  
    if(waterQty<0 || waterQty>tickets){printf("INVALID INPUT");
        return 0;}  
    
    if(seatTypeCode==1){perTicketPrice=PRICE_SILVER;}
    if(seatTypeCode==2){perTicketPrice=PRICE_GOLD;}
    if(seatTypeCode==3){perTicketPrice=PRICE_PLATINUM;}
    if(seatTypeCode==4){perTicketPrice=PRICE_RECLINER;}
    ticketSubtotal=tickets*perTicketPrice;
    if(tickets>=10){bulkrate=0.10;}
    if(tickets>=5){bulkrate=0.05;}
    bulkDiscount = ticketSubtotal * bulkrate;
   afterDiscount = ticketSubtotal - bulkDiscount;
   convenience = tickets * FEE_CONVENIENCE;
   addons = popcornQty * PRICE_POPCORN + waterQty * PRICE_WATER;
   taxable = afterDiscount + convenience + addons;
   gst = taxable * GST_RATE;
   grandTotal = taxable + gst;
   printf("========== CINEMA BOOKING REPORT ==========\n");
   printf("Customer : %s\n",name);
    if(seatTypeCode==1){printf("SILVER\n");}
    if(seatTypeCode==2){printf("GOLD\n");}
    if(seatTypeCode==3){printf("PLATINUM\n");}
    if(seatTypeCode==4){printf("RECLINER\n");};
    printf("Tickets : %d\n",tickets);
    printf("Add-ons : Popcorn=%d, Water=%d\n\n",popcornQty,waterQty);
    printf("--- Charges ---\n");
    printf("Ticket Subtotal : %.2f\n",ticketSubtotal);
    printf("Bulk discount : %.2f\n",bulkDiscount);
    printf("After discount : %.2f\n",afterDiscount);
    printf("convinence fee : %.2f\n",convenience);
    printf("Add-on total : %.2f\n",addons);
    printf("Taxable amount : %.2f\n",taxable);
    printf("GST @18 percent : %.2f\n",gst);
    printf("-------------------------------------------\n");
    printf("Grand Total: %.2f\n",grandTotal);
    printf("===========================================");


    return 0;
}