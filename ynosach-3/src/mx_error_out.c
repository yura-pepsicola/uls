#include "../inc/uls.h"

void mx_error_out(t_li ***error, st_fl *fl) {
    if (error && *error && **error) {
        mx_sorting(error, fl);
        fl->files = 1;
        fl->ex = 1;
        for (int i = 0; (*error)[i]; i++) {
            mx_printstr("uls: ");
            mx_printstr((*error)[i]->name);
            mx_printstr(": ");
            mx_printstr((*error)[i]->err);
            mx_printstr("\n");
            mx_strdel(&(*error)[i]->name);
            mx_strdel(&(*error)[i]->path);
            mx_strdel(&(*error)[i]->err);
            free((*error)[i]);
            (*error)[i] = NULL;
        }
        free(*error);
        *error = NULL;
    }
}





