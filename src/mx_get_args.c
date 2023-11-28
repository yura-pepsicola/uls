#include "../inc/uls.h"

t_li *mx_args_new_link(char *data) {
    t_li *link = (t_li *)malloc(1 * sizeof(t_li));

    link->name = mx_strdup(data);
    link->path = mx_strdup(data);
    link->err = NULL;
    if (lstat(data, &(link->info)) == -1) {
        link->err = mx_strdup(strerror(errno));	
    }
    link->open = NULL;
    return link;
}

t_li **mx_args_new_list(char **name, int count) {
    t_li **list = malloc(count * sizeof(t_li *));
    int j = 0;

    while (name[j]) {
        list[j] = mx_args_new_link(name[j]);
        j++;
    }
    
    list[j] = NULL;
    return list;
}


char **mx_args_nam(int argc, char **argv, int i, int *iteration) {
    int j = i;
    char **names = NULL;

    if (i == argc) {
        *iteration = 2;
        names = malloc(2 * sizeof(char *));
        names[0] = mx_strdup(".");
        names[1] = NULL;
    } else {
        while (argv[j]) {
            j++;
        }

        names = malloc((j - i + 1) * sizeof(char *));
        
        j = 0;
        while (argv[i]) {
            names[j] = mx_strdup(argv[i]);
            i++;
            j++;
        }

        names[j] = NULL;
        *iteration = j + 1;
    }

    return names;
}



t_li **mx_get_args(int argc, char **argv, int i) {
    int iteration = 0;
    char **name = mx_args_nam(argc, argv, i, &iteration);
    t_li **args = mx_args_new_list(name, iteration);

    mx_del_strarr(&name);
    return args;
}




