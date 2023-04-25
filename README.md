# Scratch Net
This is a neural network built from scratch using the C programming language. This repo contains all the needed utilties for building your own neural networks from scratch. The purpose of this project was to understand the inner workings of backpropagation and how certain activation functions affect the predicted outputs. 

# General Information 
* Network implementation solves the XOR problem
* Uses tanh activation function for each layer
* Calculates loss using mean squared error
* Trained on 1000 epochs with a learning rate of `0.1`


## Results
* Refer to results.txt to see full loss curve
* Expected outputs are `[0,1,1,0]`

```bash
Epoch: 985/1000  Error=0.0011
Epoch: 986/1000  Error=0.0011
Epoch: 987/1000  Error=0.0011
Epoch: 988/1000  Error=0.0011
Epoch: 989/1000  Error=0.0011
Epoch: 990/1000  Error=0.0011
Epoch: 991/1000  Error=0.0011
Epoch: 992/1000  Error=0.0011
Epoch: 993/1000  Error=0.0011
Epoch: 994/1000  Error=0.0011
Epoch: 995/1000  Error=0.0011
Epoch: 996/1000  Error=0.0011
Epoch: 997/1000  Error=0.0011
Epoch: 998/1000  Error=0.0011
Epoch: 999/1000  Error=0.0011
Epoch: 1000/1000  Error=0.0011


Preficted result
0.000047  
0.953812  
0.953221  
0.004715  
```

## Using the Network Library
* Initalize a network with a learning rate and layer count
* Create instances of layers using the `add_layer` method
* Layers take in an input and output size
* Layers also take in a boolean that represent if it's an activation layer or not

```c
/* create instance of network */
net_t *nn = init_network(learning_rate, num_layers);
add_layer(nn, 2, 3, false); 
add_layer(nn, 2, 3, true); // activation layer
add_layer(nn, 3, 1, false); 
add_layer(nn, 3, 1, true); // output activation layer


/* fit and train */
train(nn, x, y, epochs);

/* predict */
printf("\n\n"); 
printf("Predicted result\n"); 
mat_t *result = predict(nn, x, y);
print_matrix(result);  
```

## Feeding Data Inputs
* Data can be represented using the matrix library
* Inputs can be fed in batches or all at once
* To feed in batches, make use of the `to_rows()` method
* Arrays can be converted to matrices in the following example
```c
/* inputs to network  */ 
int inputs[4][2] = {
    {0,0},
    {0,1},
    {1,0},
    {1,1}
};

/* expected outputs */ 
int outputs[4][1] = {
    {0},
    {1},
    {1},
    {0}
};


/* store input/output data in matrice structs */ 
mat_t *x = init_matrix(4, 2); 
mat_t *y = init_matrix(4, 1);
    
/* convert 2d arrays to matrice representation */ 
for(int i = 0; i < 4; i++){
    for(int j = 0; j < 2; j++){
        x->arr[i][j] = inputs[i][j]; 
    }

    for(int n = 0; n < 1; n++){
        y->arr[i][n] = outputs[i][n];
    }
}
```

