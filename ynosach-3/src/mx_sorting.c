#include "../inc/uls.h"

void mx_sorting(t_li ***names, st_fl *fl) {
    t_li **joint = *names;
    int size = mx_get_arr_size(joint);

    int i = 0;
    while (i < size) {
        int k = i + 1;
        while (k < size) {
            if (joint[i]->err != NULL) {
                if (mx_strcmp(joint[i]->name, joint[k]->name) == 1) {
                    mx_swap_joints(&(joint[i]), &(joint[k]));
                }
            } 
            else if (mx_sorting_cmp(joint[i], joint[k], fl) == fl->r) {
                mx_swap_joints(&(joint[i]), &(joint[k]));
            }
           k++;
        }
        i++;
    }
}



