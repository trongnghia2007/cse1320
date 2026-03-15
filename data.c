#include <stdio.h>
#include <stdlib.h>

#define MAX_EVENTS 100

typedef struct {
    char title[100];
    char category[50];
    char date[12];
    int rsvp_count;
    int id;
} Event;

Event events[MAX_EVENTS];
int eventCount = 0;

// load data from file
void loadFromFile() {
    FILE *f = fopen("events.txt", "a+");
    if (!f) return;
    while (eventCount < MAX_EVENTS && fscanf(f,
        "%d|%[^|]|%[^|]|%[^|]|%d\n",
        &events[eventCount].id,
        events[eventCount].title,
        events[eventCount].category,
        events[eventCount].date,
        &events[eventCount].rsvp_count)
        != EOF
    ) eventCount++;
    fclose(f);
}

// Save data to file
void saveToFile() {
    FILE *f = fopen("events.txt", "w+");
    if (!f) return;
    for (int i = 0; i < eventCount; i++) {
        fprintf(f,
            "%d|%s|%s|%s|%d\n",
            events[i].id,
            events[i].title,
            events[i].category,
            events[i].date,
            events[i].rsvp_count
        );
    }
    fclose(f);
}
