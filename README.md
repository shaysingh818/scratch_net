# Scratch Net
This is a neural network built from scratch using the C programming language. This repo contains all the needed utilties for building your own neural networks from scratch. The purpose of this project was to understand the inner workings of backpropagation and how certain activation functions affect the predicted outputs. 

# General Information 
* Network implementation solves the XOR problem
* Uses tanh activation function for each layer
* Calculates loss using mean squared error
* Trained on 1000 epochs with a learning rate of `0.1`


## Results
```bash
Epoch: 977/1000  Error=0.0050
Epoch: 978/1000  Error=0.0049
Epoch: 979/1000  Error=0.0049
Epoch: 980/1000  Error=0.0049
Epoch: 981/1000  Error=0.0049
Epoch: 982/1000  Error=0.0049
Epoch: 983/1000  Error=0.0049
Epoch: 984/1000  Error=0.0049
Epoch: 985/1000  Error=0.0049
Epoch: 986/1000  Error=0.0049
Epoch: 987/1000  Error=0.0049
Epoch: 988/1000  Error=0.0049
Epoch: 989/1000  Error=0.0049
Epoch: 990/1000  Error=0.0049
Epoch: 991/1000  Error=0.0049
Epoch: 992/1000  Error=0.0049
Epoch: 993/1000  Error=0.0048
Epoch: 994/1000  Error=0.0048
Epoch: 995/1000  Error=0.0048
Epoch: 996/1000  Error=0.0048
Epoch: 997/1000  Error=0.0048
Epoch: 998/1000  Error=0.0048
Epoch: 999/1000  Error=0.0048
Epoch: 1000/1000  Error=0.0048

Predicted result
0.000110  
0.904299  
0.904385  
0.029504  
```

## How to use
* Initalize a network with a learning rate and layer count
* Create instances of layers using the `nn_layer` method
* Layers take in an input and output size
* Layers also take in a boolean that represent if it's an activation layer or not

```c
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
```
