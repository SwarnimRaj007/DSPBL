#include <stdio.h>
#include <string.h>
#include "booking.h"
#include "flight.h"


#define MAX_BOOKINGS 500


static struct Booking bookings[MAX_BOOKINGS];
static size_t booking_count = 0;


void init_bookings(){
booking_count = 0;
}


static void gen_pnr(char *out, int id){
snprintf(out, PNR_LEN, "PNR%05d", id);
}


int create_booking(int user_id, int flight_id, int seats){
if(booking_count >= MAX_BOOKINGS) return -1;
struct Flight *f = find_flight_by_id(flight_id);
if(!f) return -2;
if(f->seats_booked + seats > f->seats_total) return -3;
int id = (int)(booking_count + 1);
bookings[booking_count].id = id;
gen_pnr(bookings[booking_count].pnr, id);
bookings[booking_count].user_id = user_id;
bookings[booking_count].flight_id = flight_id;
bookings[booking_count].seats = seats;
f->seats_booked += seats;
booking_count++;
return id;
}


int cancel_booking(int booking_id){
for(size_t i=0;i<booking_count;i++){
if(bookings[i].id == booking_id){
struct Flight *f = find_flight_by_id(bookings[i].flight_id);
if(f) f->seats_booked -= bookings[i].seats;
for(size_t j=i;j+1<booking_count;j++) bookings[j] = bookings[j+1];
booking_count--;
return 0;
}
}
return -1;
}


void list_bookings(){
for(size_t i=0;i<booking_count;i++){
printf("%d %s user:%d flight:%d seats:%d\n", bookings[i].id, bookings[i].pnr, bookings[i].user_id, bookings[i].flight_id, bookings[i].seats);
}
}


size_t get_booking_count(){
return booking_count;
}