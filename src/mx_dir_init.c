#include "../inc/uls.h"

void mx_dir_init(t_li ***args, st_fl *fl) {
    t_li **files = mx_files_init(&(*args), fl);

	if (files) {
	 	mx_output_init(&files, fl, 0);
	 	if (*args) {
             mx_printchar('\n');
         }
	 	fl->files = 1;
        mx_del_arr_of_arr_ptrs(&files);
    }
    if (*args) {
        mx_open_directory(&(*args), fl);
    }    
}



