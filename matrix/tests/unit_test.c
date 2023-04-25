#include "includes/test_matrix.h"

int main(int argc, char **argv){

    /* matrix library tests */
    test_init_matrix();
    test_dot_product();
    test_dot_unequal_dimensions();
    test_backprop_dot_product(); 
    test_add_mat();
    test_scale_add();  
    test_transpose_mat();
    test_to_rows(); 

}