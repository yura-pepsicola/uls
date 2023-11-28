#include "../inc/uls.h"

int mx_sorting_cmp2(t_li *first, t_li *second, st_fl *fl) {
    if (fl->c == 1 && fl->t == 1 && fl->S != 1) {
        if (first->info.st_ctime == second->info.st_ctime) {
            if (first->info.st_ctimespec.tv_nsec == second->info.st_ctimespec.tv_nsec) {
                return mx_strcmp(first->name, second->name);
            }
            return (first->info.st_ctimespec.tv_nsec < second->info.st_ctimespec.tv_nsec) ? 1 : 0;
        }
        return (first->info.st_ctime < second->info.st_ctime) ? 1 : 0;
    }
    else if (fl->t != 1 && fl->S != 1) {
        if (mx_strcmp(first->name, second->name) > 0) {
            return 1;
        }
    }
    return 0;
}




