#include "../inc/uls.h"

char mx_check_iteration(t_li *print) {
    if (IS_DIR(print->info.st_mode))
        return 'd';
    if (IS_LNK(print->info.st_mode))
        return 'l';
    if (IS_BLK(print->info.st_mode))
        return 'b';
    if (IS_CHR(print->info.st_mode))
        return 'c';
    if (IS_FIFO(print->info.st_mode))
        return 'p';
    if (IS_SOCK(print->info.st_mode))
        return 's';
    if (IS_WHT(print->info.st_mode))
        return 'w';
    return '-';
}


