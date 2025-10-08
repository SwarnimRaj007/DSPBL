#ifndef USER_H
#define USER_H


#include <stddef.h>


#define MAX_USERS 100
#define NAME_LEN 64
#define EMAIL_LEN 64


struct User {
int id;
char name[NAME_LEN];
char email[EMAIL_LEN];
};


void init_users();
int add_user(const char *name, const char *email);
struct User *find_user_by_id(int id);
void list_users();
size_t get_user_count();


#endif