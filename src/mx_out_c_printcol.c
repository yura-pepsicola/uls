#include "../inc/uls.h"

void mx_out_c_printcol(t_li **names, int rows, int num, int maxlen) {
    int i = 0;

    while (i < rows) {
        int j = 0;
        while (i + j < num) {
            mx_printstr(names[i + j]->name);
            if (names[i + j + 1] && (i + j + rows < num)) {
                mx_out_printtab(mx_strlen(names[i + j]->name), maxlen);
            }
            j += rows;
        }
        if (i != rows - 1) {
            mx_printchar('\n');           
        }
        i++;
    }
}




