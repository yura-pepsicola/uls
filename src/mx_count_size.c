#include "../inc/uls.h"

void mx_count_size(t_sz *size, t_li *result) {
    char *name_group = mx_check_group(result);
    char *pow = mx_check_pow(result);

    if (size->lnk < result->info.st_nlink)
        size->lnk = result->info.st_nlink;
    if (size->sz < result->info.st_size)
        size->sz = result->info.st_size;
    if (size->group < mx_strlen(name_group))
        size->group = mx_strlen(name_group);
    if (size->usr < mx_strlen(pow))
        size->usr = mx_strlen(pow);
    free(name_group);
    free(pow);
}


