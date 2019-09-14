// opal.c
// Yinghong Zhong

#include <stdio.h>

typedef struct {
    int day, mon, year;
} Date;

typedef struct {
    int hour, minute;
} Time;

typedef struct {
    int transaction_nb;
    char weekday[4]; //Mon, Tue...Sun
    Date date;
    Time time;
    char mode;  // 'B', 'T'
    char start_stop[32];
    char end_stop[32];
    int journey_nb;
    char fare_applied[10];
    float fare;
    float discount;
    float amount;
} Ride;

int main() {
    Ride myride;
    printf ("The Opal data structure requires %d byte.\n", sizeof(Ride));
    return 0;
}

/*
3. memory requirement for one element of type of type Ride:
4 + 4 + 12 + 8 + 1 + (3 padding)+ 32*2 + 4 + 10 + (2padding) + 4*3 = 124

4. 
a. use integers to encode the possible "fare_applied"
b. encode the start_stop and end_stop using unique stop IDs along with
   a lookup table that links the IDs to the stop name
c. avoid the redundant information, like weekday which can be 
   derived from date
 */