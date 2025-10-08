#include <stdio.h>
#include <stdlib.h>
#include "storage.h"
#include "user.h"
#include "route.h"
#include "flight.h"
#include "booking.h"


int save_all(const char *path){
FILE *f = fopen(path, "wb");
if(!f) return -1;
fclose(f);
return 0;
}


int load_all(const char *path){
(void)path;
return 0;
}