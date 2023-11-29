#include "../inc/uls.h"

char mx_get_file_acl(t_li *print) {
    acl_t tmp;

    if (listxattr(print->path, NULL, 0, XATTR_NOFOLLOW) > 0)
        return ('@');
    if ((tmp = acl_get_file(print->path, ACL_TYPE_EXTENDED))) {
        acl_free(tmp);
        return ('+');
    }
    return (' ');
}


