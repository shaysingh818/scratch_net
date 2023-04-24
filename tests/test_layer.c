#include "includes/test_layer.h"


void test_create_layer() {


    int sizes[3] = {2,3,1}; 
    bool equality_status = true; 

    int weight_dimensions[4][2] = {
        {2,3},
        {2,3},
        {3,1},
        {3,1}
    };

    int biase_dimensions[4][2] = {
        {1,3}, 
        {1,3},  
        {1,1}, 
        {1,1}
    };     

    int inputs[4][2] = {
        {0,1},
        {1,0},
        {1,1},
        {0,0}
    };

    int outputs[4][1] = {
        {1},
        {1},
        {0},
        {0}
    };

    /* copy inputs to mat structure */
    mat_t *input = init_matrix(1, 2); 
    for(int i = 0; i < input->rows; i++){
        for(int j = 0; j < input->cols; j++){
            input->arr[i][j] = inputs[i][j]; 
        }
    }


    /* create collection of layers */
    int layer_count = 4;
    layer_t **layers = malloc(sizeof(layer_t*) * layer_count); 
    
    /* create network architecture */
    layers[0] = nn_layer(2, 3, false);
    layers[1] = nn_layer(2, 3, true); 

    layers[2] = nn_layer(3, 1, false); 
    layers[3] = nn_layer(3, 1, true);

    for(int i = 0; i < layer_count; i++){

        if(layers[i]->weights->rows != weight_dimensions[i][0]){
            equality_status = false; 
        }

        if(layers[i]->weights->cols != weight_dimensions[i][1]){
            equality_status = false; 
        }

        if(layers[i]->biases->rows != biase_dimensions[i][0]){
            equality_status = false; 
        }

        if(layers[i]->biases->cols != biase_dimensions[i][1]){
            equality_status = false; 
        }

    }

    if(!equality_status) {
        printf("%s::%s... FAILED\n", __FILE__, __FUNCTION__);
    } else {
        printf("%s::%s... \e[0;32mPASSED\e[0m\n", __FILE__, __FUNCTION__);
    } 
}


void test_forward() {


    bool equality_status = true; 

    int inputs[4][2] = {
        {0,1},
        {1,0},
        {1,1},
        {0,0}
    };

    int outputs[4][1] = {
        {1},
        {1},
        {0},
        {0}
    };


    int input_dimensions[5][2] = {
        {1,2}, 
        {1,3},
        {1,3},   
        {1,1}, 
        {1,1}
    };     

    /* copy inputs to mat structure */
    mat_t *input = init_matrix(1, 2); 
    for(int i = 0; i < input->rows; i++){
        for(int j = 0; j < input->cols; j++){
            input->arr[i][j] = inputs[i][j]; 
        }
    }


    /* create collection of layers */
    int layer_count = 4;
    layer_t **layers = malloc(sizeof(layer_t*) * layer_count); 
    
    /* create network architecture */
    layers[0] = nn_layer(2, 3, false);
    layers[1] = nn_layer(2, 3, true); 

    layers[2] = nn_layer(3, 1, false); 
    layers[3] = nn_layer(3, 1, true);


    /* get result from feedforward*/
    for(int i = 0; i < 4; i++){
        mat_t *forward_result = forward(layers[i], input);

        if(input->rows != input_dimensions[i][0]) {
            equality_status = false; 
        }

        if(input->cols != input_dimensions[i][1]) {
            equality_status = false; 
        }  

        input = copy_matrix(forward_result); 
    }

    if(!equality_status) {
        printf("%s::%s... FAILED\n", __FILE__, __FUNCTION__);
    } else {
        printf("%s::%s... \e[0;32mPASSED\e[0m\n", __FILE__, __FUNCTION__);
    } 

}


void test_backward() {

    /* equality status */
    bool equality_status = false; 

    int inputs[4][2] = {
        {0,1},
        {1,0},
        {1,1},
        {0,0}
    };

    int outputs[4][1] = {
        {1},
        {1},
        {0},
        {0}
    };

    /* copy inputs to mat structure */
    mat_t *input = init_matrix(1, 2); 
    for(int i = 0; i < input->rows; i++){
        for(int j = 0; j < input->cols; j++){
            input->arr[i][j] = inputs[i][j]; 
        }
    }

    /* copy outputs to mat structure */
    mat_t *output = init_matrix(1, 1); 
    for(int i = 0; i < output->rows; i++){
        for(int j = 0; j < output->cols; j++){
            output->arr[i][j] = outputs[i][j]; 
        }
    }

    /* create collection of layers */
    int layer_count = 4;
    layer_t **layers = malloc(sizeof(layer_t*) * layer_count); 
    
    /* create network architecture */
    layers[0] = nn_layer(2, 3, false);
    layers[1] = nn_layer(2, 3, true); 

    layers[2] = nn_layer(3, 1, false); 
    layers[3] = nn_layer(3, 1, true);


    for(int i = 0; i < layer_count; i++){
        mat_t *forward_result = forward(layers[i], input); 
        input = copy_matrix(forward_result); 
    }

    /* get loss */
    double learning_rate = 0.001; 
    mat_t *output_error = difference(output, input);

    /* backward */
    for(int i = layer_count-1; i >= 0; i--){

        mat_t *temp_weights = copy_matrix(layers[i]->weights);
        mat_t *temp_biases = copy_matrix(layers[i]->biases);

        mat_t *backward_result = backward(layers[i], output_error, learning_rate); 
        output_error = copy_matrix(backward_result);

        bool weights_compare = compare_matrix(temp_weights, layers[i]->weights); 
        bool baises_compare = compare_matrix(temp_biases, layers[i]->biases);

        /* check if weights are changing */
        if(weights_compare == false && baises_compare == false){
            equality_status = true;
            break;
        } 
    }

    if(!equality_status) {
        printf("%s::%s... FAILED\n", __FILE__, __FUNCTION__);
    } else {
        printf("%s::%s... \e[0;32mPASSED\e[0m\n", __FILE__, __FUNCTION__);
    } 

}