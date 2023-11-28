#include "../inc/uls.h"

t_li *mx_new_file_node(t_li *arg) {
    t_li *node = (t_li *)malloc(1 * sizeof (t_li));

    node->name = mx_strdup(arg->name);
    node->path = mx_strdup(arg->path);
    if (arg->err)
        node->err = mx_strdup(arg->err);
    else 
        node->err = NULL;
    lstat(node->path, &(node->info));
    if (arg->open != NULL)
        node->open = arg->open;
    else 
        node->open = NULL;
    return node;
}





