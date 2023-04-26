#ifndef LAYER_H
#define LAYER_H

#include "activations.h"
#include "../../matrix/includes/matrix.h"

struct Layer {
	int input_size, output_size;
	bool activation; // bool if the layer is only activation 
	mat_t *inputs, *outputs; 
	mat_t *weights, *biases; 
	double(*activation_function)(double); 
}; 

typedef struct Layer layer_t; 


layer_t *nn_layer(int set_input_size, int set_output_size, bool activation); 
mat_t *forward(layer_t *layer, mat_t *inputs); 
mat_t *backward(layer_t *layer, mat_t *output_error, double learning_rate); 

#endif
