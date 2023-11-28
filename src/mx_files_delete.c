#include "../inc/uls.h"

void mx_files_delete(t_li ***args, st_fl *fl) {
    t_li **dirs = NULL;
    int dir_count = 0;
    for (int i = 0; (*args)[i] != NULL; i++)
        if ((*args)[i]->err == NULL)
            if (IS_DIR((*args)[i]->info.st_mode) && 
                mx_strcmp((*args)[i]->name, ".") != 0 &&
                mx_strcmp((*args)[i]->name, "..") != 0)
                dir_count++;
    if (dir_count > 0)
        *dirs = malloc((dir_count + 1) * sizeof(t_li *));
    for (int i = 0; (*args)[i] != NULL; i++) {
        if ((*args)[i]->err == NULL) {
            if (IS_DIR((*args)[i]->info.st_mode) && 
                mx_strcmp((*args)[i]->name, ".") != 0 && 
                mx_strcmp((*args)[i]->name, "..") != 0) {
                dirs[dir_count++] = mx_new_file_node((*args)[i]);
                dirs[dir_count] = NULL;
            }
        }
    }
    fl->files = 1;
    mx_delete_liarray(args, dirs);
}





