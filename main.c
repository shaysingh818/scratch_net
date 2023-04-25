#include "layer/includes/activations.h"
#include "matrix/includes/matrix.h"
#include "network/includes/network.h"

int main(int argc, char **argv){


    int inputs[4][2] = {
        {0,0},
        {0,1},
        {1,0},
        {1,1}
    };

    int outputs[4][1] = {
        {0},
        {1},
        {1},
        {0}
    };

    srand(time(NULL));



    double learning_rate = 0.1; 
    int epochs = 1000, num_layers = 4; 
    mat_t *x = init_matrix(4, 2); 
    mat_t *y = init_matrix(4, 1);
     

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            x->arr[i][j] = inputs[i][j]; 
        }

        for(int n = 0; n < 1; n++){
            y->arr[i][n] = outputs[i][n];
        }
    }


    /* create instance of network */
    net_t *nn = init_network(learning_rate, num_layers);
    add_layer(nn, 2, 3, false); 
    add_layer(nn, 2, 3, true); 
    add_layer(nn, 3, 1, false); 
    add_layer(nn, 3, 1, true);


    /* fit and train */
    train(nn, x, y, epochs);

    /* predict */
    printf("\n\n"); 
    printf("Predicted result\n"); 
    mat_t *result = predict(nn, x, y);
    print_matrix(result);  

}