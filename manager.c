#include "main.h"

void addEvent(Event *events, int *count_ptr) {
    int count = *count_ptr;
    if (count >= 100) {
        printf("Event list full, remove event to add more!\n");
        return;
    }
    int max_id = 0;
    for (int i = 0; i < count; i++) {
        if (events[i].id > max_id) max_id = events[i].id;
    }
    events[count].id = max_id + 1;

    printf("Enter title: ");
    getStr(events[count].title, 100);

    printf("Enter category: ");
    getStr(events[count].category, 50);

    printf("Enter date:\n");
    getDate(events, count);

    printf("Enter time:\n");
    getTime(events, count);

    events[count].rsvp = 0;
    printf("Event %s added as ID %d.\n", events[count].title, events[count].id);
    *count_ptr = count + 1;
}

void editEvent(Event *events, int count) {
    if (checkEmpty(count)) return;
    int id;
    printf("Enter ID to edit: ");
    while(scanf("%d", &id) != 1 || id < 1){
        printf("Invalid ID! Please enter a valid ID: ");
        while (getchar() != '\n');
    }
    getchar();
    for (int i = 0; i < count; i++) {
        if (events[i].id == id) {
            int choice;
            printf("What would you like to edit?\n");
            printf("1. Title\n");
            printf("2. Category\n");
            printf("3. Date\n");
            printf("4. Time\n");
            printf("Enter choice: ");
            while(scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
                printf("Invalid choice! Please enter 1-4: ");
                while (getchar() != '\n');
            }
            getchar();
            printf("\n");
            switch (choice) {
                case 1:
                    printf("Enter new title: ");
                    getStr(events[i].title, 100);
                    break;
                case 2:
                    printf("Enter new category: ");
                    getStr(events[i].category, 50);
                    break;
                case 3:
                    printf("Enter new date:\n");
                    getDate(events, i);
                    break;
                case 4:
                    printf("Enter new time:\n");
                    getTime(events, i);
                    break;
            }
            return;
        }
    }
    printf("Event not found.\n");
}

void deleteEvent(Event *events, int *count_ptr) {
    int count = *count_ptr;
    if (checkEmpty(count)) return;
    int id;
    printf("Enter ID to delete: ");
    while(scanf("%d", &id) != 1 || id < 1){
        printf("Invalid ID! Please enter a valid ID: ");
        while (getchar() != '\n');
    }
    getchar();
    for (int i = 0; i < count; i++) {
        if (events[i].id == id) {
            printf("Event %s deleted.\n", events[i].title);
            for (int j = i; j < count - 1; j++) events[j] = events[j + 1];
            *count_ptr = count - 1;
            return;
        }
    }
    printf("Event not found.\n");
}

void rsvpEvent(Event *events, int count) {
    if (checkEmpty(count)) return;
    int id;
    printf("Enter ID to RSVP: ");
    while(scanf("%d", &id) != 1 || id < 1){
        printf("Invalid ID! Please enter a valid ID: ");
        while (getchar() != '\n');
    }
    getchar();
    for (int i = 0; i < count; i++) {
        if (events[i].id == id) {
            events[i].rsvp++;
            printf("Event %s RSVP successful! Total RSVP: %d\n", events[i].title, events[i].rsvp);
            return;
        }
    }
    printf("Event not found.\n");
}
