#include "../inc/uls.h"

char *mx_get_high(t_li *print) {
    return mx_itoa((int)(((unsigned int)print->info.st_rdev >> 24) & 0xff));
}



