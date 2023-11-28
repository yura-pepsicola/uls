#include "../inc/uls.h"

void mx_output_flag_m(t_li **names, st_fl *fl) {
    struct winsize win;

    if (!names) {
        return;
    }

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    if (isatty(1)) {
        mx_output_names_m(names, win.ws_col, fl);
    }
    else {
        mx_output_names_m(names, 80, fl);
    }
}


