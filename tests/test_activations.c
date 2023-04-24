#include "includes/test_activations.h"


void test_mse() {

    int rows = 1, cols = 1; 

    double y_true[1][1] = {
        {0}        
    }; 

    double y_pred[1][1] = {
        {0.06239678}
    }; 


    mat_t *x = init_matrix(rows, cols); 
    mat_t *y = init_matrix(rows, cols); 

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            x->arr[i][j] = y_true[i][j]; 
            y->arr[i][j] = y_pred[i][j];
        }
    }

    double result = mse(x, y); 


}