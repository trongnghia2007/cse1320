#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>

// Struct for managing date
typedef struct {
    int year, month, day;
} Date;

// Struct for managing time
typedef struct {
    int hour, minute;
} Time;

// Struct for managing event
typedef struct {
    int id;
    char title[100];
    char category[50];
    Date date;
    Time time;
    int rsvp;
} Event;

// Function prototypes
int checkEmpty(int count);
void getStr(char *str, int size);
void getDate(Event *events, int count);
void getTime(Event *events, int count);
void addEvent(Event *events, int *count);
void editEvent(Event *events, int count);
void deleteEvent(Event *events, int *count);
void rsvpEvent(Event *events, int count);
void searchEvent(Event events[], int count);
void viewEvents(Event events[], int count);

#endif
