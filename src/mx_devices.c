#include "../inc/uls.h"

bool mx_devices(t_li **names, t_sz *size) {
    int i = 0;

    while (names[i]) {
        if (IS_BLK(names[i]->info.st_mode) || IS_CHR(names[i]->info.st_mode)) {
            return size->is_dev = true;
        }
        i++;
    }

    return size->is_dev = false;
}




