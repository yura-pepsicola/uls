#ifndef ULS_HEADER_H
#define ULS_HEADER_H

#include "../libmx/inc/libmx.h"
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>

#define IS_BLK(mode) (((mode) & S_IFMT) == S_IFBLK)
#define IS_CHR(mode) (((mode) & S_IFMT) == S_IFCHR)
#define IS_DIR(mode) (((mode) & S_IFMT) == S_IFDIR)
#define IS_LNK(mode) (((mode) & S_IFMT) == S_IFLNK)
#define IS_SOCK(mode) (((mode) & S_IFMT) == S_IFSOCK)
#define IS_FIFO(mode) (((mode) & S_IFMT) == S_IFIFO)
#define IS_WHT(mode) (((mode) & S_IFMT) == S_IFWHT)
#define IS_REG(mode) (((mode) & S_IFMT) == S_IFREG)
#define IS_EXEC(mode) ((mode) & S_IXUSR)

#define LS_COLOR_RED        "\x1b[31m"
#define LS_COLOR_RESET      "\x1b[0m"

typedef struct fl {
    int l;
    int C;
    int x;
    int R;
    int r;
    int t;
    int u;
    int c;
    int S;
    int a;
    int A;
    int force;
    int m;
    int files;
    int G;
    int T;
    int g;
    int o;
    int ex;
}   st_fl;

typedef struct s_sz {
    int lnk;
    int sz;
    int group;
    int usr;
    bool is_dev;
}   t_sz;

typedef struct s_li {
    char *name;
    char *path;
    char *err;
    struct stat info;
    struct s_li **open;
}   t_li;

typedef struct n_type {
    int n_f;
    int n_d;
    int n_e;
    int i;
}   s_type;

//Main
st_fl *mx_get_flags(char *argv[], int *i);
void mx_add_flags(st_fl **fl, char flag);
void mx_add_flags_output(st_fl **fl, char flag);
void mx_nulloutput(st_fl **fl);
void mx_err_flag(st_fl **fl, char flag);
void mx_del_arr_of_arr_ptrs(t_li ***args);
void mx_join(char **res, char *s2);
t_li *mx_create_fn(t_li *arg);
void mx_create_desc(t_li ***files, t_li ***dirs, t_li ***errors, t_li ***args);
s_type *mx_create_int();

//Args
t_li **mx_get_args(int argc, char **argv, int i);

//Dir
void mx_dir_init(t_li ***args, st_fl *fl);
void mx_open_directory(t_li ***args, st_fl *fl);
int mx_check_directory(char *name, st_fl *fl);
void mx_create_dir(t_li **args, s_type *num, t_li ***files, t_li ***dirs);

//File
t_li *mx_new_file_node(t_li *arg);
void mx_delete_liarray(t_li ***args, t_li **dirs);
void mx_error_out(t_li ***error, st_fl *fl);
t_li **mx_files_init(t_li ***args, st_fl *fl);
int mx_count_read(t_li **arg, st_fl *fl);
t_li *mx_create_node_to(char *name, char *path);
void mx_files_delete(t_li ***args, st_fl *fl);

//Menu
void mx_output_init(t_li ***names, st_fl *fl, int flag);
void mx_output_flag_c(t_li **names);
int mx_get_len_names(t_li **names);
void mx_output_names_c(t_li **names, int maxlen, int wcl);
void mx_out_c_printcol(t_li **names, int rows, int num, int maxlen);
void mx_out_printtab(int len, int maxlen);
void mx_output_flag_x(t_li **names);
void mx_print_err_open(t_li **args, st_fl *fl);
void mx_output_names_x(t_li **names, int maxlen, int wincol);
void mx_out_x_printcol(t_li **names, int rows, int cols, int maxlen);
void mx_output_flag_m(t_li **names, st_fl *fl);
void mx_output_names_m(t_li **names, int wincol, st_fl *fl);
void mx_printn(int *len);
void mx_out_long(t_li **names, st_fl *fl, int flag);
void mx_struct_to_null(t_sz *size);
void mx_count_size(t_sz *size, t_li *total);
char *mx_check_pow(t_li *total);
char *mx_check_group(t_li *total);
bool mx_devices(t_li **names, t_sz *size);
void mx_output_spaces_g(int len, int maxlen);
void mx_output_columns_c(t_li **names, int rows, int num, int maxlen);
void mx_output_columns_x(t_li **names, int rows, int cols, int maxlen);
void mx_printstr_g(t_li *args);
int mx_output_first_g(t_li *args);
int mx_output_sec_g(t_li *args);
void mx_name_output(t_li *args);
void mx_print_names_g(t_li **names, int maxlen, int wincol, st_fl *fl);
void mx_output_flag_1(t_li **names, st_fl *fl);

//Print
void mx_print_all(t_li *print, t_sz *size, st_fl *fl);
void mx_print_perma(t_li *print);
char mx_check_iteration(t_li *print);
char mx_get_file_acl(t_li *print);
char mx_check_chapter_mode1(char chapter_mod);
char mx_check_chapter_mode2(char *chmod);
void mx_print_link(t_li *print, t_sz *size);
void mx_get_user_name(t_li *print, int usr);
void mx_get_group_name(t_li *print, int group);
void mx_show_time(t_li *print, char *t, st_fl *fl);
void mx_print_color(t_li *print, st_fl *fl);
void mx_print_rgblink(t_li *print);
void mx_print_size(t_li *print, t_sz *size);
void mx_cases(t_li *print, t_sz *size);
void mx_print_spaces(int size);
char *mx_get_high(t_li *print);
char *mx_low_to_hex(char *minor);
char *mx_get_low(t_li *print);
void mx_out_put_all(t_li ***args, st_fl *fl);
void mx_print_tab(int len, int maxlen);

//Sort
void mx_sorting(t_li ***names, st_fl *fl);
int mx_get_arr_size(t_li **names);
void mx_swap_joints(t_li **jointOne, t_li **jointTwo);
int mx_sorting_cmp(t_li *first, t_li *second, st_fl *fl);
int mx_sorting_cmp1(t_li *first, t_li *second, st_fl *fl);
int mx_sorting_cmp2(t_li *first, t_li *second, st_fl *fl);
char **mx_args_nam(int argc, char **argv, int i, int *iteration);
t_li **mx_args_new_list(char **name, int count);
t_li *mx_args_new_link(char *data);
#endif



