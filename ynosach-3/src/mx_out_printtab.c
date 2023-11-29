#include "../inc/uls.h"

void mx_out_printtab(int len, int maxlen) {
    int count = 0;
    int p;

    p = maxlen - len;
    if (p % 8 != 0) {
        count = (p / 8) + 1;        
    }
    else {
        count = p / 8;
    }

    int i = 0;
    while (i < count) {
        mx_printchar('\t');
        i++;
    }
}




