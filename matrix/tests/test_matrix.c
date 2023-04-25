#include "includes/test_matrix.h"


void test_init_matrix(){

    int rows = 6; 
    int cols = 6;
    bool equality_status = true;  
    mat_t *m = init_matrix(rows, cols); 

    double values[6][6] = {
        {1, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
    };

    /* copy identity to init matrix */
    mat_t *m2 = init_matrix(rows, cols); 
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            m2->arr[i][j] = values[i][j]; 
        }
    }

    m  = copy_matrix(m2); 

    for(int i = 0; i < rows; i++){
        double rounded_value = round(m->arr[i][i]*100)/100; 
        if(m2->arr[i][i] != rounded_value){
            equality_status = false; 
		}
	}

    if(!equality_status) {
        printf("%s::%s... FAILED\n", __FILE__, __FUNCTION__);
    } else {
        printf("%s::%s... \e[0;32mPASSED\e[0m\n", __FILE__, __FUNCTION__);
    } 
}


void test_dot_product() {

    int rows = 6; 
    int cols = 6;
    bool equality_status = true;  
    mat_t *m = init_matrix(rows, cols); 
    mat_t *m2 = init_matrix(rows, cols); 

    double m_values[6][6] = {
        {2, 0, 0, 0, 0, 0}, 
        {0, 2, 0, 0, 0, 0},
        {0, 0, 2, 0, 0, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 2},
    };

    double m2_values[6][6] = {
        {3, 0, 0, 0, 0, 0}, 
        {0, 3, 0, 0, 0, 0},
        {0, 0, 3, 0, 0, 0},
        {0, 0, 0, 3, 0, 0},
        {0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 3},
    };

    double expected_values[6][6] = {
        {6, 0, 0, 0, 0, 0}, 
        {0, 6, 0, 0, 0, 0},
        {0, 0, 6, 0, 0, 0},
        {0, 0, 0, 6, 0, 0},
        {0, 0, 0, 0, 6, 0},
        {0, 0, 0, 0, 0, 6},
    };

    /* copy values to matrice */
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            m->arr[i][j] = m_values[i][j];
            m2->arr[i][j] = m2_values[i][j]; 
        }
    }

    mat_t *result = dot(m, m2); 

    for(int i = 0; i < rows; i++){
        double rounded_value = round(result->arr[i][i]*100)/100; 
        if(expected_values[i][i] != rounded_value){
            equality_status = false; 
		}
	}

    if(!equality_status) {
        printf("%s::%s... FAILED\n", __FILE__, __FUNCTION__);
    } else {
        printf("%s::%s... \e[0;32mPASSED\e[0m\n", __FILE__, __FUNCTION__);
    } 
}


void test_backprop_dot_product(){


    bool equality_status = false;  
    mat_t *m1 = init_matrix(4, 1); 
    mat_t *m2 = init_matrix(1, 3); 

    /* specific case where matrix returns 0's*/
    double m2_values[4][1] = {
        {0.07}, 
        {0.07}, 
        {0.07}, 
        {0.07}, 
    };

    double m3_values[1][3] = {
        {-0.23, 0.31, -0.42} 
    };


    /* copy values to matrice */
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 1; j++){
            m1->arr[i][j] = m2_values[i][j]; 
        }
    }


    for(int i = 0; i < 1; i++){
        for(int j = 0; j < 3; j++){
            m2->arr[i][j] = m3_values[i][j]; 
        }
    }

    mat_t *result = dot(m1, m2); 
    if(result->rows == 4 && result->cols == 3){
        equality_status = true;             
    }

    if(!equality_status) {
        printf("%s::%s... FAILED\n", __FILE__, __FUNCTION__);
    } else {
        printf("%s::%s... \e[0;32mPASSED\e[0m\n", __FILE__, __FUNCTION__);
    } 

}


void test_dot_unequal_dimensions(){

    bool equality_status = true;  
    mat_t *m = init_matrix(2, 2); 
    mat_t *m2 = init_matrix(2, 1); 

    double m_values[6][6] = {
        {3, 0}, 
        {0, 3},
    };

    double m2_values[2][1] = {
        {1},
        {1}
    };

    double results[2][1] = {
        {3.00},
        {3.00}
    };

    /* copy values to matrice */
    for(int i = 0; i < m->rows; i++){
        for(int j = 0; j < m->cols; j++){
            m->arr[i][j] = m_values[i][j];
        }
    }


    for(int i = 0; i < m2->rows; i++){
        for(int j = 0; j < m2->cols; j++){
            m2->arr[i][j] = m2_values[i][j];
        }
    }

    mat_t *result = dot(m, m2);

    for(int i = 0; i < result->rows; i++){
        for(int j = 0; j < result->cols; j++){
            double rounded_value = round(result->arr[i][j]*100)/100; 
            if(results[i][j] != rounded_value){
                equality_status = false; 
		    }
        }
	}

    if(!equality_status) {
        printf("%s::%s... FAILED\n", __FILE__, __FUNCTION__);
    } else {
        printf("%s::%s... \e[0;32mPASSED\e[0m\n", __FILE__, __FUNCTION__);
    } 

}


void test_add_mat() {

    int rows = 6; 
    int cols = 6;
    bool equality_status = true;  
    mat_t *m = init_matrix(rows, cols); 
    mat_t *m2 = init_matrix(rows, cols); 

    double m_values[6][6] = {
        {2, 0, 0, 0, 0, 0}, 
        {0, 2, 0, 0, 0, 0},
        {0, 0, 2, 0, 0, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 2},
    };

    double m2_values[6][6] = {
        {3, 0, 0, 0, 0, 0}, 
        {0, 3, 0, 0, 0, 0},
        {0, 0, 3, 0, 0, 0},
        {0, 0, 0, 3, 0, 0},
        {0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 3},
    };


    double expected_values[6][6] = {
        {5, 0, 0, 0, 0, 0}, 
        {0, 5, 0, 0, 0, 0},
        {0, 0, 5, 0, 0, 0},
        {0, 0, 0, 5, 0, 0},
        {0, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, 0, 5},
    };

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            m->arr[i][j] = m_values[i][j];
            m2->arr[i][j] = m2_values[i][j]; 
        }
    }

    mat_t *result = add(m, m2);

    for(int i = 0; i < rows; i++){
        double rounded_value = round(result->arr[i][i]*100)/100; 
        if(expected_values[i][i] != rounded_value){
            equality_status = false; 
		}
	}

    if(!equality_status) {
        printf("%s::%s... FAILED\n", __FILE__, __FUNCTION__);
    } else {
        printf("%s::%s... \e[0;32mPASSED\e[0m\n", __FILE__, __FUNCTION__);
    } 
        
}

void test_transpose_mat(){


    int rows = 6; 
    int cols = 6;
    bool equality_status = true;  
    mat_t *m = init_matrix(rows, cols); 

    double m_values[6][6] = {
        {1, 2, 3, 4, 5, 6}, 
        {1, 2, 3, 4, 5, 6},
        {0, 0, 2, 0, 0, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 2},
    };

    double expected_values[6][6] = {
        {1, 1, 0, 0, 0, 0}, 
        {2, 2, 0, 0, 0, 0},
        {3, 3, 2, 0, 0, 0},
        {4, 4, 0, 2, 0, 0},
        {5, 5, 0, 0, 2, 0},
        {6, 6, 0, 0, 0, 2},
    };

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            m->arr[i][j] = m_values[i][j];
        }
    }

    mat_t *result = transpose(m); 

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            double rounded_value = round(result->arr[i][j]*100)/100; 
            if(expected_values[i][j] != rounded_value){
                equality_status = false; 
		    }
        }
	}

    if(!equality_status) {
        printf("%s::%s... FAILED\n", __FILE__, __FUNCTION__);
    } else {
        printf("%s::%s... \e[0;32mPASSED\e[0m\n", __FILE__, __FUNCTION__);
    } 

}


void test_scale_add(){

    mat_t *dot_product = init_matrix(4, 3); 
    mat_t *biases = init_matrix(1, 3); 
    bool equality_status = true; 

    double m_values[4][3] = {
        {0, 0, 0}, 
        {2, 2, 2}, 
        {2, 2, 2}, 
        {4, 4, 4}, 
    };

    double biase_values[1][3] = {
        {1, 1, 1}, 
    };


    double expected_values[4][3] = {
        {1, 1, 1}, 
        {3, 3, 3}, 
        {3, 3, 3}, 
        {5, 5, 5}, 
    };


    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            dot_product->arr[i][j] = m_values[i][j];
            if(i == 0){
                biases->arr[i][j] = biase_values[i][j]; 
            }
        }
    }

    mat_t *result = scale_add(dot_product, biases); 

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            double rounded_value = round(result->arr[i][j]*100)/100; 
            if(expected_values[i][j] != rounded_value){
                equality_status = false; 
		    }
        }
	}

}


void test_to_rows() {


    mat_t *test_matrix = init_matrix(4, 3); 
    bool equality_status = true; 

    double m_values[4][3] = {
        {0, 0, 0}, 
        {2, 2, 2}, 
        {2, 2, 2}, 
        {4, 4, 4}, 
    };


    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            test_matrix->arr[i][j] = m_values[i][j];             
        }
	}

    mat_t **rows = to_rows(test_matrix);
    for(int i = 0; i < test_matrix->rows; i++){
        for(int j = 0; j < test_matrix->cols; j++){
            if(m_values[i][j] != rows[i]->arr[0][j]){
                equality_status = false; 
            }            
        } 
    } 

    if(!equality_status) {
        printf("%s::%s... FAILED\n", __FILE__, __FUNCTION__);
    } else {
        printf("%s::%s... \e[0;32mPASSED\e[0m\n", __FILE__, __FUNCTION__);
    } 


}