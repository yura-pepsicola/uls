#include "../inc/uls.h"

void mx_print_names_g(t_li **names, int maxlen, int wincol, st_fl *fl) {
    int rows;
    int cols = (wincol / maxlen) != 0 ? wincol / maxlen : 1;
    int num = 0;

    for(;names[num]; num++) {
    }
    if (maxlen * cols > wincol && cols != 1)
        cols--;
    if (num * maxlen > wincol) {
        rows = num / cols;
        if (rows == 0 || num % cols != 0)
            rows += 1;
        if (fl->x == 0)
            mx_output_columns_c(names, rows, num, maxlen);
        else
            mx_output_columns_x(names, rows, cols, maxlen);
    } else {
        for (int i = 0; names[i]; i++) {
            mx_printstr_g(names[i]);
            if (names[i + 1]){
                mx_output_spaces_g(mx_strlen(names[i]->name), maxlen);
            }
        }
    }
    mx_printchar('\n');
}


