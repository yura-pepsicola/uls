#include "../inc/uls.h"

void mx_cases(t_li *print, t_sz *size) {
    char *high = mx_get_high(print);
    char *low = mx_get_low(print);
    
    if (size->is_dev == true)
        if (IS_BLK(print->info.st_mode) || IS_CHR(print->info.st_mode)) {
            mx_print_spaces(2 - mx_strlen(high));
            mx_printstr(high);
            mx_printchar(',');
            mx_printchar(' ');
            mx_print_spaces(2 - mx_strlen(low));
            mx_printstr(low); 
        }
        else {
            mx_printstr("       ");
            mx_printint(print->info.st_size);
        }
    else
       mx_printint(print->info.st_size); 
    free(high);
    free(low);
}


