#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"


static struct User users[MAX_USERS];
static size_t user_count = 0;


void init_users(){
user_count = 0;
}


int add_user(const char *name, const char *email){
if(user_count >= MAX_USERS) return -1;
int id = (int)(user_count + 1);
users[user_count].id = id;
strncpy(users[user_count].name, name, NAME_LEN-1);
users[user_count].name[NAME_LEN-1] = '\0';
strncpy(users[user_count].email, email, EMAIL_LEN-1);
users[user_count].email[EMAIL_LEN-1] = '\0';
user_count++;
return id;
}


struct User *find_user_by_id(int id){
for(size_t i=0;i<user_count;i++) if(users[i].id==id) return &users[i];
return NULL;
}


void list_users(){
for(size_t i=0;i<user_count;i++){
printf("%d %s %s\n", users[i].id, users[i].name, users[i].email);
}
}


size_t get_user_count(){
return user_count;
}