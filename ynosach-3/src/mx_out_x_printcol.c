#include "../inc/uls.h"

void mx_print_tab(int len, int maxlen) {
    int count = 0;
    int p;

    p = maxlen - len;
    if (p % 8 != 0)
        count = (p / 8) + 1;
    else
        count = p / 8;
    for (int i = 0; i < count; i++)
        mx_printchar('\t');
}

void mx_out_x_printcol(t_li **names, int rows, int cols, int maxlen) {
    int j = 0;
    int tempcols = cols;

    int i = 0;
    while (i < rows) {
        for (; names[j] && j < cols; j++) {
            mx_printstr(names[j]->name);
            if (names[j + 1] && (j != cols - 1)) {
                mx_print_tab(mx_strlen(names[j]->name), maxlen);
            }
        }
        if (i != rows - 1) {
            mx_printchar('\n');
        }
        i++;
        cols += tempcols;
    }
}



