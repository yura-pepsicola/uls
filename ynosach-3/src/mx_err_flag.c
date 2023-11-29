#include "../inc/uls.h"

void mx_err_flag(st_fl **fl, char flag) {
    write(2, "uls: illegal option --", mx_strlen("uls: illegal option --"));
    write(2,&flag,1);
    write(2, "\n", mx_strlen("\n"));
    write(2, "usage: uls [-ACGRSTcfglmortux1] [file ...]\n", mx_strlen("usage: uls [-ACGRSTcfglmortux1] [file ...]\n"));
    free(*fl);
    fl = NULL;
    exit(1);
}





