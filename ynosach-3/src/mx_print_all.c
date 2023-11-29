#include "../inc/uls.h"

void mx_print_all(t_li *print, t_sz *size, st_fl *fl) {
    time_t *chapter_time = &print->info.st_ctime;
    time_t *aou_time = &print->info.st_atime;
    time_t *t = &print->info.st_mtime;

    mx_print_perma(print);
    mx_print_link(print, size);
    if ((fl->l == 1 && fl->g == 0) || (fl->o == 1 && fl->g == 0))
        mx_get_user_name(print, size->usr);
    if ((fl->l == 1 && fl->o == 0) || (fl->g == 1 && fl->o == 0))
        mx_get_group_name(print, size->group);
    mx_print_size(print, size);
    if (fl->u == 1)
        t = aou_time;
    if (fl->c == 1)
        t = chapter_time;
    mx_show_time(print, ctime(t), fl);
    mx_print_color(print, fl);
    mx_printchar('\n');
}


