#include <stdio.h>
#include <string.h>

extern int eventCount;
extern struct Event {
    char title[100];
    char category[50];
    int year, month, day;
    int rsvp_count;
    int id;
} events[];

void getDate() {
    int year, month, day, max_day;

    printf("Enter year (0-9999): ");
    while(scanf("%d", &year) != 1 || year < 0 || year > 9999){
        printf("Invalid year! Please enter 0-9999: ");
        while (getchar() != '\n');
    }
    getchar();
    events[eventCount].year = year;

    printf("Enter month (1-12): ");
    while(scanf("%d", &month) != 1 || month < 1 || month > 12){
        printf("Invalid month! Please enter 1-12: ");
        while (getchar() != '\n');
    }
    getchar();
    events[eventCount].month = month;

    max_day = (month == 2)
    ? ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28)
    : ((month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31);

    printf("Enter day (1-%d): ", max_day);
    while(scanf("%d", &day) != 1 || day < 1 || day > max_day){
        printf("Invalid day! Please enter 1-%d: ", max_day);
        while (getchar() != '\n');
    }
    getchar();
    events[eventCount].day = day;
}

void addEvent() {
    if (eventCount >= 100) {
        printf("Event list full, remove event to add more!\n");
        return;
    }
    events[eventCount].id = eventCount + 1;

    printf("Enter title: ");
    fgets(events[eventCount].title, 100, stdin);
    events[eventCount].title[strcspn(events[eventCount].title, "\n")] = 0;

    printf("Enter category: ");
    fgets(events[eventCount].category, 50, stdin);
    events[eventCount].category[strcspn(events[eventCount].category, "\n")] = 0;

    printf("Enter date:\n");
    getDate();

    events[eventCount].rsvp_count = 0;
    printf("Event %s added as ID %d.\n", events[eventCount].title, events[eventCount].id);
    eventCount++;
}

void deleteEvent() {
    if (eventCount == 0) {
        printf("No events available.\n");
        return;
    }
    int id;
    printf("Enter ID to delete: ");
    while(scanf("%d", &id) != 1 || id < 1){
        printf("Invalid ID! Please enter a valid ID: ");
        while (getchar() != '\n');
    }
    getchar();
    for (int i = 0; i < eventCount; i++) {
        if (events[i].id == id) {
            for (int j = i; j < eventCount - 1; j++) events[j] = events[j + 1];
            eventCount--;
            printf("Event %s deleted.\n", events[i].title);
            return;
        }
    }
    printf("Event with ID %d not found.\n", id);
}
