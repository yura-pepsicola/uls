#include "../inc/uls.h"

int mx_get_len_names(t_li **names) {
    int max = 0;
    int temp = 0;
    int i = 0;

    while (names[i]) {
        temp = mx_strlen(names[i]->name);
        if (temp > max) {
            max = temp;
        }
        i++;
    }

    if (max % 8 == 0) {
        max += 8;
    }
    else {
        max = 8 - (max % 8) + max;
    }

    return max;
}




