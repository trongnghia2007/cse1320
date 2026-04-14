#include <stdio.h>
#include <stdlib.h>

#define MAX_EVENTS 100

// Global variable for keeping event count
int eventCount = 0;

// Struct for managing event
typedef struct {
    char title[100];
    char category[50];
    int year, month, day;
    int rsvp_count;
    int id;
} Event;
Event events[MAX_EVENTS];

// load data from file
void loadFromFile() {
    FILE *f = fopen("events.txt", "a+");
    if (!f) {
        printf("Error opening file!");
        return;
    }
    while (eventCount < MAX_EVENTS && fscanf(f,
        "%d|%[^|]|%[^|]|%d/%d/%d|%d\n",
        &events[eventCount].id,
        events[eventCount].title,
        events[eventCount].category,
        &events[eventCount].year,
        &events[eventCount].month,
        &events[eventCount].day,
        &events[eventCount].rsvp_count)
        != EOF
    ) eventCount++;
    fclose(f);
}

// Save data to file
void saveToFile() {
    FILE *f = fopen("events.txt", "w+");
    if (!f) {
        printf("Error opening file!");
        return;
    }
    for (int i = 0; i < eventCount; i++) {
        fprintf(f,
            "%d|%s|%s|%d/%d/%d|%d\n",
            events[i].id,
            events[i].title,
            events[i].category,
            events[i].year,
            events[i].month,
            events[i].day,
            events[i].rsvp_count
        );
    }
    fclose(f);
}

extern void mainMenu();

int main() {
    loadFromFile();
    mainMenu();
    saveToFile();
    return 0;
}
