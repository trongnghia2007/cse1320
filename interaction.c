#include <stdio.h>

extern int eventCount;
extern struct Event {
    char title[100];
    char category[50];
    int year, month, day;
    int rsvp_count;
    int id;
} events[];
extern void addEvent();
extern void deleteEvent();
extern void displayEvents();
extern void searchByTitle();
extern void searchByCategory();

void rsvpEvent() {
    if (eventCount == 0) {
        printf("No events available.\n");
        return;
    }
    int id;
    printf("Enter ID to RSVP: ");
    while(scanf("%d", &id) != 1 || id < 1){
        printf("Invalid ID! Please enter a valid ID: ");
        while (getchar() != '\n');
    }
    getchar();
    for (int i = 0; i < eventCount; i++) {
        if (events[i].id == id) {
            events[i].rsvp_count++;
            printf("Event %s RSVP successful! Total RSVP: %d\n", events[i].title, events[i].rsvp_count);
            return;
        }
    }
    printf("Event not found.\n");
}

void mainMenu() {
    int choice;
    do {
        printf("\n=== CommuniKnot ===\n");
        printf("1.Add Event\n");
        printf("2.Delete Event\n");
        printf("3.View Events\n");
        printf("4.Search by Title\n");
        printf("5.Search by Category\n");
        printf("6.RSVP Event\n");
        printf("7.Exit\n");
        printf("Enter choice: ");
        while(scanf("%d", &choice) != 1 || choice < 1 || choice > 7) {
            printf("Invalid choice! Please enter 1-7: ");
            while (getchar() != '\n');
        }
        getchar();
        printf("\n");
        switch (choice) {
            case 1:
                addEvent();
                break;
            case 2:
                deleteEvent();
                break;
            case 3:
                displayEvents();
                break;
            case 4:
                searchByTitle();
                break;
            case 5:
                searchByCategory();
                break;
            case 6:
                rsvpEvent();
                break;
            case 7:
                printf("Exiting... Goodbye!\n");
                break;
        }
    } while (choice != 7);
}
