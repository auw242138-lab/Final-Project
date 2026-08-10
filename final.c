#include <stdio.h>
#include <string.h>

int main() {
    char movies[6][50] = {"Ava", "Batman", "Barbie", "Openhaimer", "Homeless", "Avatar"};
    int ticketprice[6] = {500, 600, 440, 190, 170, 140};
    int stock[6] = {5, 5, 5, 5, 5, 5};
    char viral[3][50] = {"Ava", "Batman", "Barbie"};
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6 - i - 1; j++) {
            if (strcmp(movies[j], movies[j + 1]) > 0) {
                char tempName[50];
                strcpy(tempName, movies[j]);
                strcpy(movies[j], movies[j + 1]);
                strcpy(movies[j + 1], tempName);

                int tempPrice = ticketprice[j];
                ticketprice[j] = ticketprice[j + 1];
                ticketprice[j + 1] = tempPrice;

                int tempStock = stock[j];
                stock[j] = stock[j + 1];
                stock[j + 1] = tempStock;
            }
        }
    }
    int minIdx = 0, maxIdx = 0;
    for (int i = 0; i < 6; i++) {
        if (ticketprice[i] < ticketprice[minIdx]) minIdx = i;
        if (ticketprice[i] > ticketprice[maxIdx]) maxIdx = i;
    }
    printf("Cheapest Available Movie: %s (Price: %d)\n", movies[minIdx], ticketprice[minIdx]);
    printf("Most Expensive Available Movie: %s (Price: %d)\n\n", movies[maxIdx], ticketprice[maxIdx]);
    for (int user = 1; user <= 3; user++) {
        printf("....user %d....\n", user);

        printf("Available Movies:\n");
        for (int i = 0; i < 6; i++) {
            printf(" %s (Price: %d, Tickets left: %d)\n", movies[i], ticketprice[i], stock[i]);
        }

        char name[50];
        int found = 0;
        while (!found) {
            printf("\nEnter Movie Name: ");
            scanf("%s", name);
            int i;
            for (i = 0; i < 6; i++) {
                if (strcmp(name, movies[i]) == 0) break;
            }

            if (i == 6) {
                printf("Not Available. Please try again.\n");
                continue;
            }

            if (stock[i] == 0) {
                printf("Sold Out! No tickets left for %s.\n", movies[i]);
                continue;
            }

            int numticket;
            printf("Enter Number of Tickets: ");
            scanf("%d", &numticket);

            if (numticket <= 0) {
                printf("Please enter a valid number of tickets.\n");
                continue;
            }

            if (numticket > stock[i]) {
                printf("Only %d ticket(s) left for %s. Please enter a smaller amount.\n", stock[i], movies[i]);
                continue;
            }
            int is_viral = 0;
            for (int v = 0; v < 3; v++) {
                if (strcmp(viral[v], movies[i]) == 0) {
                    is_viral = 1;
                    break;
                }
            }

            int total;
            if (is_viral) {
                total = (ticketprice[i] + (ticketprice[i] * 10 / 100)) * numticket;
                printf("Available.\nTotal Price: %d (Viral Movie! 10 percent increase)\n", total);
            } else {
                total = ticketprice[i] * numticket;
                printf("Available.\nTotal Price: %d\n", total);
            }
            stock[i] -= numticket;   
            found = 1;
        }
        printf("\n");
    }

    return 0;
}




****
#include <stdio.h>
#include <string.h>

int main() {
    char movies[6][50] = {"Ava", "Batman", "Barbie", "Openhaimer", "Homeless", "Avatar"};
    int ticketprice[6] = {500, 160, 440, 390, 170, 140};
    int totalTicketsSold = 0;  // Track tickets across all users

    // Bubble sort movies + ticketprice together (do this once before loop)
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6 - i - 1; j++) {
            if (strcmp(movies[j], movies[j + 1]) > 0) {
                char temp[50];
                int tempPrice;

                strcpy(temp, movies[j]);
                strcpy(movies[j], movies[j + 1]);
                strcpy(movies[j + 1], temp);

                tempPrice = ticketprice[j];
                ticketprice[j] = ticketprice[j + 1];
                ticketprice[j + 1] = tempPrice;
            }
        }
    }

    // Print movies with prices once at the start
    printf("Available Movies:\n");
    for (int i = 0; i < 6; i++) {
        printf("%s (Price: %d)\n", movies[i], ticketprice[i]);
    }

    // Viral movies info
    printf("\n10%% Increase of Ticket Price for Viral movies: Ava, Batman, Barbie\n");

    // Find cheapest and most expensive
    int min = 0, max = 0;
    for (int i = 0; i < 6; i++) {
        if (ticketprice[i] < ticketprice[min]) min = i;
        if (ticketprice[i] > ticketprice[max]) max = i;
    }
    printf("\nCheapest Available Movie: %s (Price: %d)", movies[min], ticketprice[min]);
    printf("\nMost Expensive Available Movie: %s (Price: %d)\n", movies[max], ticketprice[max]);

    // Loop for 3 users
    for (int user = 1; user < 4; user++) {
        printf("\n\n.....User %d.....\n", user);

        char name[50];
        printf("Enter Movie Name: ");
        scanf("%s", name);

        int numticket;
        printf("Enter Number of Tickets: ");
        scanf("%d", &numticket);

        int corn;
        printf("Enter the number of popcorn boxes you want to purchase (1 box: 300 TK): ");
        scanf("%d", &corn);

        int found = 0;
        for (int i = 0; i < 6; i++) {
            if (strcmp(name, movies[i]) == 0) {
                // Check cumulative tickets
                if (totalTicketsSold + numticket > 5) {
                    printf("Sold Out!\n");
                    return 0;  // Exit program immediately
                }

                // Check if movie is viral
                int isViral = 0;
                char viral[3][50] = {"Ava", "Batman", "Barbie"};
                for (int v = 0; v < 3; v++) {
                    if (strcmp(name, viral[v]) == 0) {
                        isViral = 1;
                        break;
                    }
                }

                int total;
                if (isViral) {
                    total = (ticketprice[i] + (ticketprice[i] * 10 / 100)) * numticket + (corn * 300);
                    printf("\nTotal Payment: %d (Viral Movie! 10 percent increase)\n", total);
                } else {
                    total = (ticketprice[i] * numticket) + (corn * 300);
                    printf("\nTotal Payment: %d\n", total);
                }

                totalTicketsSold += numticket;  // Update global ticket count
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

