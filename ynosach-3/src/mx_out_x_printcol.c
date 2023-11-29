#include "../inc/uls.h"

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



