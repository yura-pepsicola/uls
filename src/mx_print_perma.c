#include "../inc/uls.h"

void mx_print_perma(t_li *print) {
    char chapter_mod[12];
    int i = 0;

    chapter_mod[0] = mx_check_iteration(print);
    chapter_mod[1] = (S_IRUSR & print->info.st_mode) ? 'r' : '-';
    chapter_mod[2] = (S_IWUSR & print->info.st_mode) ? 'w' : '-';
    chapter_mod[3] = (S_IXUSR & print->info.st_mode) ? 'x' : '-';
    chapter_mod[4] = (S_IRGRP & print->info.st_mode) ? 'r' : '-';
    chapter_mod[5] = (S_IWGRP & print->info.st_mode) ? 'w' : '-';
    chapter_mod[6] = (S_IXGRP & print->info.st_mode) ? 'x' : '-';
    chapter_mod[7] = (S_IROTH & print->info.st_mode) ? 'r' : '-';
    chapter_mod[8] = (S_IWOTH & print->info.st_mode) ? 'w' : '-';
    chapter_mod[9] = (S_IXOTH & print->info.st_mode) ? 'x' : '-';
    chapter_mod[10] = mx_get_file_acl(print);
    chapter_mod[11] = '\0';

    S_ISUID & print->info.st_mode ? chapter_mod[3] = mx_check_chapter_mode1(chapter_mod[3]) : 0;
    S_ISGID & print->info.st_mode ? chapter_mod[6] = mx_check_chapter_mode1(chapter_mod[6]) : 0;
    S_ISVTX & print->info.st_mode ? chapter_mod[9] = mx_check_chapter_mode2(chapter_mod) : 0;

    while (chapter_mod[i]) {
        mx_printchar(chapter_mod[i]);
        i++;
    }

    mx_printchar(' ');
}



