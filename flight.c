#include <stdio.h>
#include <string.h>
#include "flight.h"


#define MAX_FLIGHTS 200


static struct Flight flights[MAX_FLIGHTS];
static size_t flight_count = 0;


void init_flights(){
flight_count = 0;
}


int add_flight(const char *flight_no, int route_id, const char *date, float fare, int seats){
if(flight_count >= MAX_FLIGHTS) return -1;
int id = (int)(flight_count + 1);
flights[flight_count].id = id;
strncpy(flights[flight_count].flight_no, flight_no, FLIGHT_ID_LEN-1);
flights[flight_count].flight_no[FLIGHT_ID_LEN-1] = '\0';
flights[flight_count].route_id = route_id;
strncpy(flights[flight_count].date, date, DATE_LEN-1);
flights[flight_count].date[DATE_LEN-1] = '\0';
flights[flight_count].fare = fare;
flights[flight_count].seats_total = seats;
flights[flight_count].seats_booked = 0;
flight_count++;
return id;
}


struct Flight *find_flight_by_id(int id){
for(size_t i=0;i<flight_count;i++) if(flights[i].id==id) return &flights[i];
return NULL;
}


void list_flights(){
for(size_t i=0;i<flight_count;i++){
printf("%d %s route:%d date:%s fare:%.2f seats:%d/%d\n", flights[i].id, flights[i].flight_no, flights[i].route_id, flights[i].date, flights[i].fare, flights[i].seats_booked, flights[i].seats_total);
}
}


size_t get_flight_count(){
return flight_count;
}