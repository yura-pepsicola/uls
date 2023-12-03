#include "../inc/uls.h"

t_li *mx_create_fn(t_li *arg) {
    t_li *fn = (t_li *)malloc(1 * sizeof (t_li));

    fn->name = mx_strdup(arg->name);
    fn->path = mx_strdup(arg->path);
    if (arg->err)
        fn->err = mx_strdup(arg->err);
    else 
        fn->err = NULL;
    lstat(fn->path, &(fn->info));
    if (arg->open != NULL)
        fn->open = arg->open;
    else 
        fn->open = NULL;
    return fn;
}

s_type *mx_create_int() {
    s_type *num = malloc(sizeof (s_type));
    num->n_d = 0;
    num->n_e = 0;
    num->n_f = 0;
    num->i = 0;
    return num;
}

void mx_create_desc(t_li ***files, t_li ***dirs, t_li ***errors, t_li ***args) {
    int k = 0;
    int nd = 0;
    int eror = 0;
    int i = 0;
    while ((*args)[i] != NULL) {
        if ((*args)[i]->err == NULL) {
            if (!IS_DIR((*args)[i]->info.st_mode)) {
                k++;
            } else {
                nd++;
            }
        } else {
            eror++;
        }
        i++;
    }

    if (k > 0)
        *files = malloc((k + 1) * sizeof(t_li *));
    if (nd > 0)
        *dirs = malloc((nd + 1) * sizeof(t_li *));
    if (eror > 0)
        *errors = malloc((eror + 1) * sizeof(t_li *));
}

void mx_create_dir(t_li **args, s_type *num, t_li ***files, t_li ***dirs) {
    if (!IS_DIR((*args)->info.st_mode)) {
        (*files)[num->n_f++] = mx_create_fn((*args));
        (*files)[num->n_f] = NULL;
    }
    else {
        (*dirs)[num->n_d++] = mx_create_fn((*args));
        (*dirs)[num->n_d] = NULL;
    }
}


t_li **mx_files_init(t_li ***args, st_fl *fl) {
    t_li **fls = NULL;
    t_li **libs = NULL;
    t_li **errors = NULL;
    s_type *num = mx_create_int();

    mx_create_desc(&fls, &libs, &errors, args);

    while ((*args)[num->i] != NULL) {
        if ((*args)[num->i]->err == NULL)
            mx_create_dir(&(*args)[num->i], num, &fls, &libs);
        else {
            errors[num->n_e++] = mx_create_fn((*args)[num->i]);
            errors[num->n_e] = NULL;
        }
        num->i++;
    }

    if (num->n_d > 1)
        fl->files = 1;

    mx_delete_liarray(args, libs);
    mx_error_out(&errors, fl);
    free(num);
    return fls;
}




