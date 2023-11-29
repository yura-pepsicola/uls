#include "../inc/uls.h"

void mx_del_liarr(t_li ***args, t_li **dirs) {
    t_li **del_arr = *args;

    for (int i = 0; del_arr[i]!= NULL; i++) {
        mx_strdel(&del_arr[i]->name);
        mx_strdel(&del_arr[i]->path);
        if (del_arr[i]->err)
            mx_strdel(&del_arr[i]->err);
        free(del_arr[i]);
        del_arr[i] = NULL;
    }
    free(*args);
    *args = dirs;
}

void mx_out_long(t_li **names, st_fl *fl, int flag) {
    t_sz *size = malloc(sizeof(t_sz));
    int bulk_size = 0;
    int i = 0;

    mx_struct_to_null(size);
    for (i = 0; names[i]; i++) {
        bulk_size += names[i]->info.st_blocks;
        mx_count_size(size, names[i]);
    }
    if (flag == 1) {
        mx_printstr("total ");
        mx_printint(bulk_size);
        mx_printchar('\n');
    }
    mx_devices(names, size);
    for (i = 0; names[i]; i++) {
        mx_print_all(names[i], size, fl);
    }
    free(size);
}



