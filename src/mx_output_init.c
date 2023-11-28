#include "../inc/uls.h"

void mx_output_init(t_li ***names, st_fl *fl, int flag) {
    if (**names != NULL) {
        mx_sorting(&(*names), fl);
        (fl->l) ? mx_out_long(*names, fl, flag) : (void) 0;
        if (fl->C == 1 && !fl->G) {
            mx_output_flag_c(*names);
        }
        if (fl->x == 1 && !fl->G) {
            mx_output_flag_x(*names);
        }
        if (fl->m == 1) {
            mx_output_flag_m(*names, fl);
        }     
        if (fl->force == 1) {
            mx_output_flag_1(*names, fl);
        }
        if (fl->G == 1 && fl->m != 1 && fl->l != 1 && fl->force != 1) {
            mx_output_flag_g(*names, fl);
        }
        if (fl->l != 1 && fl->C != 1 && fl->x != 1 && fl->m != 1 && fl->force != 1 && !fl->G && !fl->g && !fl->o && isatty(1)) {
            mx_output_flag_c(*names);
        }
        if (!isatty(1) && fl->C != 1 && fl->x != 1 && fl->m != 1 && fl->l != 1 && fl->g != 1 && fl->o != 1 && fl->force != 1) {
            mx_output_flag_1(*names, fl);
        } 
    }
}



