#include <stdio.h>

extern void displayEvents();
extern void searchByCategory();
extern void addEvent();
extern void deleteEvent();
extern int eventCount;
extern struct Event {
    char title[100];
    char category[50];
    char date[12];
    int rsvp_count;
    int id;
} events[];

void rsvpEvent() {
    int id;
    printf("Enter event ID to RSVP: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < eventCount; i++) {
        if (events[i].id == id) {
            events[i].rsvp_count++;
            printf("RSVP successful! Total: %d\n", events[i].rsvp_count);
            return;
        }
    }
    printf("Event not found.\n");
}

void mainMenu() {
    int choice;
    do {
        printf("\n=== CommuniKnot ===\n");
        printf("1.View Events\n");
        printf("2.Add Event\n");
        printf("3.Delete Event\n");
        printf("4.Search by Category\n");
        printf("5.RSVP Event\n");
        printf("6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
        case 1:
            displayEvents();
            break;
        case 2:
            addEvent();
            break;
        case 3:
            deleteEvent();
            break;
        case 4:
            searchByCategory();
            break;
        case 5:
            rsvpEvent();
            break;
        case 6:
            printf("Exiting... Goodbye!\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 6);
}
