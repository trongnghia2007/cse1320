#include <stdio.h>
#include <string.h>

extern int eventCount;
extern struct Event {
    char title[100];
    char category[50];
    char date[12];
    int rsvp_count;
    int id;
} events[];

void displayEvents() {
    if (eventCount == 0) {
        printf("No events.\n");
        return;
    }
    printf("\nID  Title                    Category            Date        RSVP\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < eventCount; i++)
        printf("%-3d %-25s %-18s %-12s %-5d\n", events[i].id, events[i].title, events[i].category, events[i].date, events[i].rsvp_count);
}

void searchByCategory() {
    char category[50];
    printf("Enter category: ");
    fgets(category, 50, stdin);
    category[strcspn(category, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < eventCount; i++) {
        if (strcmp(events[i].category, category) == 0) {
            printf("%d | %s | %s | %s\n", events[i].id, events[i].title, events[i].category, events[i].date);
            found = 1;
        }
    }
    if (!found) printf("No events in this category.\n");
}
