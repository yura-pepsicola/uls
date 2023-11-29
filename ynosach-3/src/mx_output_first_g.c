#include "../inc/uls.h"
int mx_output_first_g(t_li *args) {
    if (IS_DIR(args->info.st_mode)) {
        mx_printstr("\033[34m");
        mx_name_output(args);
        return 1;
    }
    else if (IS_LNK(args->info.st_mode)) {
        mx_printstr("\033[35m");
        mx_name_output(args);
        return 1;
    }
    else if (args->info.st_mode & S_IXOTH) {
        mx_printstr(LS_COLOR_RED);
        mx_name_output(args);
        return 1;
    }
    return 0;
}




