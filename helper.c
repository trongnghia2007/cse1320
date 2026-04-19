#include "main.h"

int checkEmpty(int count) {
    if (count == 0) {
        printf("No events available.\n");
        return 1;
    }
    return 0;
}

void getStr(char *str, int size) {
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void getDate(Event *events, int count) {
    int year, month, day, max_day;

    printf("Enter year (0-9999): ");
    while(scanf("%d", &year) != 1 || year < 0 || year > 9999){
        printf("Invalid year! Please enter 0-9999: ");
        while (getchar() != '\n');
    }
    getchar();
    events[count].date.year = year;

    printf("Enter month (1-12): ");
    while(scanf("%d", &month) != 1 || month < 1 || month > 12){
        printf("Invalid month! Please enter 1-12: ");
        while (getchar() != '\n');
    }
    getchar();
    events[count].date.month = month;

    max_day = (month == 2)
    ? ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28)
    : ((month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31);

    printf("Enter day (1-%d): ", max_day);
    while(scanf("%d", &day) != 1 || day < 1 || day > max_day){
        printf("Invalid day! Please enter 1-%d: ", max_day);
        while (getchar() != '\n');
    }
    getchar();
    events[count].date.day = day;
}

void getTime(Event *events, int count) {
    int hour, minute;

    printf("Enter hour (0-23): ");
    while(scanf("%d", &hour) != 1 || hour < 0 || hour > 23){
        printf("Invalid hour! Please enter 0-23: ");
        while (getchar() != '\n');
    }
    getchar();
    events[count].time.hour = hour;

    printf("Enter minute (0-59): ");
    while(scanf("%d", &minute) != 1 || minute < 0 || minute > 59){
        printf("Invalid minute! Please enter 0-59: ");
        while (getchar() != '\n');
    }
    getchar();
    events[count].time.minute = minute;
}
