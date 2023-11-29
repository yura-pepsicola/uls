#include "../inc/uls.h"

void mx_output_names_x(t_li **names, int maxlen, int wincol) {
    int rows;
    int cols = (wincol / maxlen) != 0 ? wincol / maxlen : 1;
    int num = 0;

    while (names[num]) {
        num++;
    }

    if (maxlen * cols > wincol && cols != 1)
        cols--;

    if (num * maxlen > wincol) {
        rows = num / cols;
        if (rows == 0 || num % cols != 0)
            rows += 1;
        mx_out_x_printcol(names, rows, cols, maxlen);
    } 
    else {
        int i = 0;
        while (names[i]) {
            mx_printstr(names[i]->name);
            if (names[i + 1]) {
                mx_out_printtab(mx_strlen(names[i]->name), maxlen);
            }
            i++;
        }
        mx_printchar('\n');
    }
}



