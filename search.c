#include <string.h>
#include <stdio.h>
#include "search.h"
#include "flight.h"
#include "route.h"


int search_flights_by_route_and_date(const char *source, const char *dest, const char *date, int *out, int max){
int found = 0;
for(size_t i=0;i<get_flight_count();i++){
struct Flight *f = find_flight_by_id((int)i+1);
if(!f) continue;
struct Route *r = find_route_by_id(f->route_id);
if(!r) continue;
if((source==NULL || strcmp(r->source, source)==0) && (dest==NULL || strcmp(r->dest, dest)==0) && (date==NULL || strcmp(f->date, date)==0)){
if(found < max) out[found] = f->id;
found++;
}
}
return found;
}


int filter_flights_by_price(float max_price, int *inout, int in_count){
int out_count = 0;
for(int i=0;i<in_count;i++){
struct Flight *f = find_flight_by_id(inout[i]);
if(!f) continue;
if(f->fare <= max_price){
inout[out_count++] = inout[i];
}
}
return out_count;
}