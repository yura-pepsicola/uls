#include "../inc/uls.h"

void mx_name_output(t_li *args) {
    mx_printstr(args->name);
    mx_printstr(LS_COLOR_RESET);
}

void mx_printstr_g(t_li *args) {
    if (mx_output_first_g(args) == 1) {
    }
    else if (mx_output_sec_g(args) == 1) {
    }
    else if (IS_FIFO(args->info.st_mode)) {
        mx_printstr("\033[33m");
        mx_name_output(args);
    }
    else if (IS_WHT(args->info.st_mode)) {
        mx_printstr("\033[36m");
        mx_name_output(args);
    }
    else if (IS_EXEC(args->info.st_mode)) {
        mx_printstr("\033[31m");
        mx_name_output(args);
    }
    else
        mx_printstr(args->name);
}

void mx_output_flag_g(t_li **names, st_fl *fl) {
    int maxlen;
    struct winsize win;
    if (!names)
        return;
    maxlen = mx_get_len_names(names);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    mx_print_names_g(names, maxlen, win.ws_col, fl);
}

