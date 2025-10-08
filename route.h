#ifndef ROUTE_H
#define ROUTE_H
#include <stddef.h>

#define CODE_LEN 8
#define CITY_LEN 64


struct Route {
int id;
char source[CITY_LEN];
char dest[CITY_LEN];
char code[CODE_LEN];
};


void init_routes();
int add_route(const char *source, const char *dest, const char *code);
struct Route *find_route_by_id(int id);
void list_routes();
size_t get_route_count();


#endif