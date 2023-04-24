#include "includes/test_matrix.h" 
#include "includes/test_activations.h" 
#include "includes/test_network.h"
#include "includes/test_layer.h"

int main(int argc, char **argv){

   /* test matrix library */
   test_init_matrix();
   test_dot_product();
   test_dot_unequal_dimensions();
   test_backprop_dot_product();  
   test_add_mat(); 
   test_transpose_mat(); 
   test_scale_add(); 
   test_to_rows(); 


   /* activations */
   //test_mse();  

   /* test layer */
   //test_create_layer(); 
   //test_forward(); 
   //test_backward();  

   /* test networks */
   //test_init_network();
   //test_add_layer();
   //test_train(); 
   //test_loss(); 
   test_network_train(); 

}