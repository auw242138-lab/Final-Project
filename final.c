#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    char movies[6][50] = {"Spider Man", "Batman", "Barbie", "Openhaimer", "Harry Potter", "Avatar"};
    char viral [3][50] = {"Spider Man", "Batman", "Barbie"};
    int ticketprice[6] = {500, 600, 440, 190, 170, 140};
    int movieid[6] = {1, 2, 3, 4, 5, 6};

    int found = 0;
    while (!found) {
        printf("Enter Movie Name: ");
        scanf("%s", name);


        for (int i = 0; i < 6; i++) {
            if (strcmp(name, movies[i]) == 0) {
                int numticket;
                printf("\nEnter Number of Tickets: ");
                scanf("%d",&numticket);
                if (strcmp(viral[i],movies[i])==0){
                    ticketprice[i] = (ticketprice[i] + (ticketprice[i]*10/100)) * numticket;
                    printf("Available. \nTicket Price: %d (10 percent increase) \nMovie ID: %d\n", ticketprice[i], movieid[i]);
                }
                else {printf("Available. \nTicket Price: %d \nMovie ID: %d\n", (ticketprice[i] * numticket), movieid[i]);}

                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Not Available. Please try again.\n");
        }
    }

    return 0;
}
