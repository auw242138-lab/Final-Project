#include <stdio.h>
#include <string.h>

int main() {
    int num;
    for ( num=1; num<4; num++){
    char name[50];
    char movies[6][50]= {"Ava", "Batman", "Barbie", "Openhaimer", "Homeless", "Avatar"};
     for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6 - i - 1; j++) {
            if (strcmp(movies[j], movies[j + 1]) > 0) {
                char temp[20];
                strcpy(temp, movies[j]);
                strcpy(movies[j], movies[j + 1]);
                strcpy(movies[j + 1], temp);}}}
    printf("Available Movies: ");
    for (int i=0; i<6; i++)
    {
        printf(" \n%s ",movies[i]);
    }

    int ticketprice[6] = {500, 600, 440, 190, 170, 140};

    int min=0;
    int max=0;
    for (int i=0; i<6; i++)
    {
        if (ticketprice[i] < ticketprice[min]){
            ticketprice[min] = ticketprice[i];
            }
        if (ticketprice[i] > ticketprice[max]){
            ticketprice[max] = ticketprice[i];
            } }
            printf("\n\nCheapest Available Movie: %s (Prcie: %d)", movies[min], min);
            printf("Most Expensive Available Movie: %s (Prcie: %d)\n", movies[max], max);


    char viral [3][50] = {"Ava", "Batman", "Barbie"};
    int found = 0;
    while (!found) {
        printf("\nEnter Movie Name: ");
        scanf("%s", name);
        for (int i = 0; i < 6; i++) {
            if (strcmp(name, movies[i]) == 0) {

                int numticket;
                printf("Enter Number of Tickets: ");
                scanf("%d",&numticket);
                if (numticket>5){
                    printf("Sold Out!");
                    break;
                }




                if (strcmp(viral[i],movies[i])==0){
                    ticketprice[i] = (ticketprice[i] + (ticketprice[i]*10/100)) * numticket;
                    printf("Available.\nTicket Price: %d (Viral Movie! 10 percent increase)", ticketprice[i]);
                }
                else {printf("Available.\nTicket Price: %d \n",(ticketprice[i] * numticket));}

                found = 1;
                break; }}

        if (!found) {
            printf("Not Available. Please try again.\n");
        } }

    return 0;
}}
