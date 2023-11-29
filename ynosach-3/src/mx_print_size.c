#include "../inc/uls.h"

void mx_print_size(t_li *print, t_sz *size) {
    char *resourse_now = mx_itoa(print->info.st_size);
    char *resource_size = mx_itoa(size->sz);
    int counter = 0;

    if (mx_strlen(resourse_now) == mx_strlen(resource_size))
        mx_cases(print, size);
    else if (mx_strlen(resourse_now) < mx_strlen(resource_size)) {
        counter = mx_strlen(resourse_now);
        for (; counter != mx_strlen(resource_size); counter++) {
            mx_printchar(' ');
        }
        mx_cases(print, size);
    }
    mx_printchar(' ');
    free(resourse_now);
    free(resource_size);
}


