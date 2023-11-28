#include "../inc/uls.h"

t_li **mx_files_init(t_li ***args, st_fl *fl) {
    t_li **files = NULL;
    t_li **dirs = NULL;
    t_li **errors = NULL;
    s_type *num = malloc(sizeof (s_type));
    num->n_d = 0;
    num->n_e = 0;
    num->n_f = 0;
    num->i = 0;
    int j = 0;
    int dir_count = 0;
    int err_count = 0;
    int k = 0;
    while ((*args)[k] != NULL) {
        if ((*args)[k]->err == NULL) {
            if (!IS_DIR((*args)[k]->info.st_mode)) {
                j++;
            } else {
                dir_count++;
            }
        } else {
            err_count++;
        }
        k++;
    }
    if (j > 0)
        *files = malloc((j + 1) * sizeof(t_li *));
    if (dir_count > 0)
        *dirs = malloc((dir_count + 1) * sizeof(t_li *));
    if (err_count > 0)
        *errors = malloc((err_count + 1) * sizeof(t_li *));
    while ((*args)[num->i] != NULL) {
        if ((*args)[num->i]->err == NULL) {
            if (!IS_DIR((*args)->info.st_mode)) {
                (*files)[num->n_f++] = mx_new_file_node((*args));
                (*files)[num->n_f] = NULL;
            } else {
                (*dirs)[num->n_d++] = mx_new_file_node((*args));
                (*dirs)[num->n_d] = NULL;
            }
        } else {
            errors[num->n_e++] = mx_new_file_node((*args)[num->i]);
            errors[num->n_e] = NULL;
        }
        num->i++;
    }
    if (num->n_d > 1) {
        fl->files = 1;
    }
    mx_delete_liarray(args, dirs);
    mx_error_out(&errors, fl);
    free(num);
    return files;
}





