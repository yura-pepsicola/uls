#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*count)++;
        if (mx_strcmp(arr[mid], s) > 0) {
            right = mid - 1;
        }
        else if (mx_strcmp(arr[mid], s) < 0) {
            left = mid + 1;
        }
        else if (mx_strcmp(arr[mid], s) == 0) {
            return mid;
        }
    }
    *count = 0;
    return -1;
}



