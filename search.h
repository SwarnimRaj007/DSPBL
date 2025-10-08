#ifndef SEARCH_H
#define SEARCH_H


struct FlightResult {
int flight_id;
};


int search_flights_by_route_and_date(const char *source, const char *dest, const char *date, int *out, int max);
int filter_flights_by_price(float max_price, int *inout, int in_count);


#endif