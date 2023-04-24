#ifndef NETWORK_H
#define NETWORK_H

#include "matrix.h"
#include "activations.h"
#include "layer.h"

struct Network {
    int num_layers, layer_count;
    int front_index, rear_index;  
    double learning_rate, loss;   
    layer_t **layers; 
    layer_t *front, rear; 
}; 

typedef struct Network net_t; 

net_t *init_network(double learning_rate, int num_layers);
void add_layer(net_t *nn, int input_size, int output_size, bool activation);  
void train(net_t *nn, mat_t *x, mat_t *y, int epochs); 
void debug(net_t *n);

/* test predictions */
mat_t *predict(net_t *nn, mat_t *x, mat_t *y); 


#endif