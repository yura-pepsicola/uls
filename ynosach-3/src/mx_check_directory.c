#include "../inc/uls.h"

int mx_check_directory(char *name, st_fl *fl) {
    if (fl->A != 1)
        return 0;
    if (mx_strcmp(name, ".") == 0)
        return 0;
    if (mx_strcmp(name, "..") == 0)
        return 0;
    return 1;
}




