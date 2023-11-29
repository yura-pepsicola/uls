#include "../inc/uls.h"

void mx_output_names_c(t_li **names, int maxlen, int wcl) {
    int rows;
    int colums = (wcl / maxlen) != 0 ? wcl / maxlen : 1;
    int num = 0;

    while (names[num]) {
        num++;
    }

    if (maxlen * colums > wcl && colums != 1) {
        colums--;
    }

    if (num * maxlen > wcl) {
        rows = num / colums;
        if (rows == 0 || num % colums != 0) {
            rows += 1;
        }
        mx_out_c_printcol(names, rows, num, maxlen);
    } 
    else {
        int i = 0;
        while (names[i]) {
            mx_printstr(names[i]->name);
            if (names[i + 1])
                mx_out_printtab(mx_strlen(names[i]->name), maxlen);
            i++;
        }
        mx_printchar('\n');
    }
}


