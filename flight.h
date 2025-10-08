#ifndef FLIGHT_H
#define FLIGHT_H
#include <stddef.h>

#define FLIGHT_ID_LEN 16
#define DATE_LEN 16


struct Flight {
int id;
char flight_no[FLIGHT_ID_LEN];
int route_id;
char date[DATE_LEN];
float fare;
int seats_total;
int seats_booked;
};


void init_flights();
int add_flight(const char *flight_no, int route_id, const char *date, float fare, int seats);
struct Flight *find_flight_by_id(int id);
void list_flights();
size_t get_flight_count();


#endif