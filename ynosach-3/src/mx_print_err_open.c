#include "../inc/uls.h"

void mx_print_err_open(t_li **args, st_fl *fl) {
    if ((*args)->open != NULL) {
        mx_output_init(&(*args)->open, fl, 1);
        if (fl->R == 1) {
            fl->files = 1;
            mx_files_delete(&(*args)->open, fl);
            if ((*args)->open) {
                mx_printchar('\n');
                mx_open_directory(&(*args)->open, fl);
            }
        }
    }
    else if ((*args)->err != NULL) {
        mx_printstr("uls: ");
        mx_printstr((*args)->path);
        mx_printstr(": ");
        mx_printstr((*args)->err);
        mx_printstr("\n");
    }
}




