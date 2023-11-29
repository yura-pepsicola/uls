#include "../inc/uls.h"

char mx_check_chapter_mode1(char chapter_mod) {
    if (chapter_mod == '-')
        return chapter_mod = 'S';
    else
        return chapter_mod = 's';
}

char mx_check_chapter_mode2(char *chmod) {
    if (chmod[9] == '-')
        return chmod[9] = 'T';
    else
        return chmod[9] = 't';
}




