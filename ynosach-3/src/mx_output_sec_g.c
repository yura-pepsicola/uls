#include "../inc/uls.h"

int mx_output_sec_g(t_li *args) {
    if (IS_BLK(args->info.st_mode)) {
        mx_printstr("\033[34;46m");
        mx_name_output(args);
        return 1;
    }
    else if (IS_CHR(args->info.st_mode)) {
        mx_printstr("\033[34;43m");
        mx_name_output(args);
        return 1;
    }
    else if (IS_SOCK(args->info.st_mode)) {
        mx_printstr("\033[32m");
        mx_name_output(args);
        return 1;
    }
    return 0;
}




