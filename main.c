#include <stdio.h>
#include <string.h>
#include "user.h"
#include "route.h"
#include "flight.h"
#include "booking.h"
#include "search.h"


int main(){
init_users();
init_routes();
init_flights();
init_bookings();
int uid = add_user("Alice","alice@example.com");
int r1 = add_route("Delhi","Mumbai","DLH-MUM");
int r2 = add_route("Mumbai","Bengaluru","MUM-BLR");
int f1 = add_flight("AI101", r1, "2025-10-10", 4500.0f, 150);
int f2 = add_flight("AI102", r2, "2025-10-11", 5200.0f, 120);
int b1 = create_booking(uid, f1, 2);
list_users();
list_routes();
list_flights();
list_bookings();
int results[50];
int found = search_flights_by_route_and_date("Delhi","Mumbai","2025-10-10", results, 50);
for(int i=0;i<found && i<50;i++) printf("found flight id %d\n", results[i]);
return 0;
}