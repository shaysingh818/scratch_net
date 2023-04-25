#include "includes/test_network.h"

int main(int argc, char **argv){

    test_init_network();
    test_add_layer(); 
    test_train();
    test_loss(); 
    test_network_train();  
}