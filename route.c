#include <stdio.h>
#include <string.h>
#include "route.h"


#define MAX_ROUTES 100


static struct Route routes[MAX_ROUTES];
static size_t route_count = 0;


void init_routes(){
route_count = 0;
}


int add_route(const char *source, const char *dest, const char *code){
if(route_count >= MAX_ROUTES) return -1;
int id = (int)(route_count + 1);
routes[route_count].id = id;
strncpy(routes[route_count].source, source, CITY_LEN-1);
routes[route_count].source[CITY_LEN-1] = '\0';
strncpy(routes[route_count].dest, dest, CITY_LEN-1);
routes[route_count].dest[CITY_LEN-1] = '\0';
strncpy(routes[route_count].code, code, CODE_LEN-1);
routes[route_count].code[CODE_LEN-1] = '\0';
route_count++;
return id;
}


struct Route *find_route_by_id(int id){
for(size_t i=0;i<route_count;i++) if(routes[i].id==id) return &routes[i];
return NULL;
}


void list_routes(){
for(size_t i=0;i<route_count;i++){
printf("%d %s -> %s (%s)\n", routes[i].id, routes[i].source, routes[i].dest, routes[i].code);
}
}


size_t get_route_count(){
return route_count;
}