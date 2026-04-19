#include "main.h"

#define FILENAME "events.txt"
#define MAX_EVENTS 100

int main() {
    // Initialize variables
    Event events[MAX_EVENTS];
    int count = 0;

    // Load data from file
    FILE *input = fopen(FILENAME, "a+");
    if (!input) {
        printf("Error opening file!");
        return 1;
    }
    while (count < MAX_EVENTS && fscanf(input,
        "%d|%[^|]|%[^|]|%d/%d/%d|%d:%d|%d\n",
        &events[count].id,
        events[count].title,
        events[count].category,
        &events[count].date.year,
        &events[count].date.month,
        &events[count].date.day,
        &events[count].time.hour,
        &events[count].time.minute,
        &events[count].rsvp)
        != EOF
    ) count++;
    fclose(input);

    // Main menu
    int choice;
        do {
        printf("\n=== CommuniKnot ===\n");
        printf("1. Add Event\n");
        printf("2. Edit Event\n");
        printf("3. Delete Event\n");
        printf("4. View Events\n");
        printf("5. Search Event(s)\n");
        printf("6. RSVP Event\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        while(scanf("%d", &choice) != 1 || choice < 1 || choice > 7) {
            printf("Invalid choice! Please enter 1-7: ");
            while (getchar() != '\n');
        }
        getchar();
        printf("\n");
        switch (choice) {
            case 1:
                addEvent(events, &count);
                break;
            case 2:
                editEvent(events, count);
                break;
            case 3:
                deleteEvent(events, &count);
                break;
            case 4:
                viewEvents(events, count);
                break;
            case 5:
                searchEvent(events, count);
                break;
            case 6:
                rsvpEvent(events, count);
                break;
            case 7:
                printf("Exiting... Goodbye!\n");
                break;
        }
    } while (choice != 7);
    
    // Save data to file
    FILE *output = fopen(FILENAME, "w+");
    if (!output) {
        printf("Error opening file!");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        fprintf(output,
            "%d|%s|%s|%d/%d/%d|%02d:%02d|%d\n",
            events[i].id,
            events[i].title,
            events[i].category,
            events[i].date.year,
            events[i].date.month,
            events[i].date.day,
            events[i].time.hour,
            events[i].time.minute,
            events[i].rsvp
        );
    }
    fclose(output);
    return 0;
}
