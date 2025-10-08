#ifndef BOOKING_H
#define BOOKING_H
#include <stddef.h>


#define PNR_LEN 16


struct Booking {
int id;
char pnr[PNR_LEN];
int user_id;
int flight_id;
int seats;
};


void init_bookings();
int create_booking(int user_id, int flight_id, int seats);
int cancel_booking(int booking_id);
void list_bookings();
size_t get_booking_count();


#endif