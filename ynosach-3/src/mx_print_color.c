#include "../inc/uls.h"

void mx_print_color(t_li *print, st_fl *fl) {
    if (fl->G == 1)
        mx_printstr_g(print);
    else if (IS_LNK(print->info.st_mode)) {
        mx_printstr(print->name);
        mx_print_rgblink(print);
    }
    else
        mx_printstr(print->name);
}

void mx_print_rgblink(t_li *print) {
    char *buf = NULL;
    ssize_t nbytes = 0;
    ssize_t buf_size = 0;

    buf_size = print->info.st_size == 0 ? 100 : print->info.st_size + 1;
    buf = mx_strnew(buf_size);
    nbytes = readlink(print->path, buf, buf_size);
    mx_printstr(" -> ");
    if (nbytes >= 0)
        mx_printstr(buf);
    mx_strdel(&buf);
}




