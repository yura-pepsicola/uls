#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub) {
        return -2;
    }
    int i = 0;
    int len = mx_strlen(sub);
    while (*str) {
        if (mx_strncmp(str, sub, len) == 0) {
            return i;
        }
        i++;
        str++;
    }
    return -1;
}



