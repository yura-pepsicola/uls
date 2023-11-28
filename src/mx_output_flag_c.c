#include "../inc/uls.h"

void mx_output_flag_c(t_li **names) {
    int maxlen;
    struct winsize win;

    if (!names) {
        return;
    }
    maxlen = mx_get_len_names(names);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    if (isatty(1)) {
        mx_output_names_c(names, maxlen, win.ws_col);
    }
    else {
        mx_output_names_c(names, maxlen, 80);
    }
}




