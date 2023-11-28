#include "../inc/libmx.h"

t_list* mx_create_node(void *data) {
    t_list *new_node = malloc(sizeof(t_list));

    if (new_node) {
        new_node->data = data;
        new_node->next = NULL;
    }

    return new_node;
}

