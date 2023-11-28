#include "../inc/uls.h"

void mx_swap_joints(t_li **jointOne, t_li **jointTwo) {
    t_li *temp = *jointOne;
    *jointOne = *jointTwo;
    *jointTwo = temp;
}



