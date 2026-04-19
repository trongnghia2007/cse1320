#include "main.h"

static void displayEvent(Event event) {
    printf("ID: %d\n", event.id);
    printf("Title: %s\n", event.title);
    printf("Category: %s\n", event.category);
    printf("Date (DD/MM/YYYY): %02d/%02d/%04d\n", event.date.day, event.date.month, event.date.year);
    printf("Time: %02d:%02d\n", event.time.hour, event.time.minute);
    printf("RSVP: %d\n", event.rsvp);
}

static void searchById(Event events[], int count) {
    int id;
    printf("Enter ID: ");
    while(scanf("%d", &id) != 1 || id < 1){
        printf("Invalid ID! Please enter a valid ID: ");
        while (getchar() != '\n');
    }
    getchar();
    for (int i = 0; i < count; i++) {
        if (events[i].id == id) {
            displayEvent(events[i]);
            return;
        }
    }
    printf("Event not found.\n");
}

static void searchByTitle(Event events[], int count) {
    char title[100];
    printf("Enter title: ");
    getStr(title, 100);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(events[i].title, title) == 0) {
            if (!found) printf("Event(s) found:\n\n");
            displayEvent(events[i]);
            printf("\n");
            found = 1;
        }
    }
    if (!found) printf("Event not found.\n");
}

static void searchByCategory(Event events[], int count) {
    char category[50];
    printf("Enter category: ");
    getStr(category, 50);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(events[i].category, category) == 0) {
            if (!found) printf("Event(s) found:\n\n");
            displayEvent(events[i]);
            printf("\n");
            found = 1;
        }
    }
    if (!found) printf("Event not found.\n");
}

void searchEvent(Event events[], int count) {
    if (checkEmpty(count)) return;
    int choice;
    printf("What do you want to search by?\n");
    printf("1. ID\n");
    printf("2. Title\n");
    printf("3. Category\n");
    printf("Enter choice: ");
    while(scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("Invalid choice! Please enter 1-3: ");
        while (getchar() != '\n');
    }
    getchar();
    printf("\n");
    switch (choice) {
        case 1:
            searchById(events, count);
            break;
        case 2:
            searchByTitle(events, count);
            break;
        case 3:
            searchByCategory(events, count);
            break;
    }
}

void viewEvents(Event events[], int count) {
    if (checkEmpty(count)) return;
    printf("%-3s  %-30s  %-15s  %-17s  %-5s  %-4s\n", "ID", "Title", "Category", "Date (DD/MM/YYYY)", "Time", "RSVP");
    printf("------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        // Convert date and time to string
        char dateStr[11], timeStr[6];
        sprintf(dateStr, "%02d/%02d/%04d", events[i].date.day, events[i].date.month, events[i].date.year);
        sprintf(timeStr, "%02d:%02d", events[i].time.hour, events[i].time.minute);
        printf("%-3d  %-30.30s  %-15.15s  %-17s  %-5s  %-4d\n",
            events[i].id,
            events[i].title,
            events[i].category,
            dateStr,    
            timeStr,    
            events[i].rsvp
        );
    }
}
