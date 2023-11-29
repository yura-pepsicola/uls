#include "../inc/uls.h"

int main(int argc, char *argv[]) {
    int count = 1;
    st_fl *fl = mx_get_flags(argv, &count);
    t_li **args = mx_get_args(argc, argv, count);
    int ex = 0;

    if (args) {
        mx_dir_init(&args, fl);
    }
    if (fl->ex == 1) {
        ex = 1;
    }
    free(fl);
    fl = NULL;
    exit(ex);
}



