#include "includes/matrix.h"


mat_t *init_matrix(int rows, int cols){

	mat_t *mat; 
	mat = (mat_t*)malloc(sizeof(mat_t)); 
	mat->rows = rows; 
	mat->cols = cols; 

	mat->arr = malloc(sizeof(double*)*mat->rows);
	for(int i = 0; i < mat->rows; i++){
		mat->arr[i] = malloc(sizeof(double)*mat->cols);
	}	

	return mat; 
}

mat_t *dot(mat_t *n, mat_t *m){	
    if(n->cols == m->rows) {
		mat_t *result_mat = init_matrix(n->rows, m->cols);
        for(int i = 0; i < n->rows; i++){
            for(int j = 0; j < m->cols; j++){
				double sum = 0; 
				for(int k = 0; k < m->rows; k++){
					sum += n->arr[i][k] * m->arr[k][j];
				}
				result_mat->arr[i][j] = sum; 
            }
        }
		return result_mat; 	
    } else {
		printf("Dimension mismatch for dot product\n");
		exit(1);  
	}

}

mat_t *add(mat_t *n, mat_t *m){

	mat_t *result_mat = init_matrix(n->rows, n->cols); 
	// confirm that cols of m are equal to n
	for(int i = 0; i < n->rows; i++){
		for(int j = 0; j < m->cols; j++){
			double value = n->arr[i][j] + m->arr[i][j];
			result_mat->arr[i][j] = value;  
		}
	}

	return result_mat; 
}

mat_t *sum(mat_t *m, int axis){
	mat_t *result = init_matrix(1, m->cols);
	for(int n = 0; n < m->cols; n++){
		double temp_sum = 0.0; 
		for(int i = 0; i < m->rows; i++){
			double sum_value = 0.0; 
			for(int j = 0; j < m->cols; j++){
				sum_value += m->arr[i][j]; 
			}
			temp_sum = sum_value; 
		}
		result->arr[0][n] = temp_sum; 
	}
	
	return result; 
}

mat_t *scale(mat_t *n, double value){

	mat_t *result_mat = init_matrix(n->rows, n->cols); 
	for(int i = 0; i < n->rows; i++){
		for(int j = 0; j < n->cols; j++){
			double temp = n->arr[i][j] *= value;  
			result_mat->arr[i][j] = temp;
		}
	}

	return result_mat; 
}

mat_t *scale_add(mat_t *n, mat_t *m){

	mat_t *result_mat = init_matrix(n->rows, n->cols); 
	for(int i = 0; i < n->rows; i++){
		for(int j = 0; j < n->cols; j++){
			double value = n->arr[i][j] +  m->arr[0][j];  
			result_mat->arr[i][j] = value;
		}
	}

	return result_mat; 
}


mat_t *multiply(mat_t *v1, mat_t *v2) {

	mat_t *result = init_matrix(v1->rows, v2->cols);

	for(int i = 0; i < v1->rows; i++){
		for(int j = 0; j < v2->cols; j++){
			result->arr[i][j] = 0; 	
			for(int n = 0; n < v1->cols; n++){
				double value = v1->arr[i][n] * v2->arr[n][j];
				result->arr[i][j] += value; 
			}  
		} 
	} 

	return result;
}

mat_t *elementwise_multiply(mat_t *v1, mat_t *v2) {

    if (v1->rows != v2->rows || v1->cols != v2->cols) {
        printf("Error: matrices must be of the same size for element-wise multiplication");
        exit(1);
    }

    mat_t *result = init_matrix(v1->rows, v1->cols);

    for (int i = 0; i < v1->rows; i++) {
        for (int j = 0; j < v1->cols; j++) {
            result->arr[i][j] = v1->arr[i][j] * v2->arr[i][j];
        }
    }

    return result;
}


mat_t *transpose(mat_t *n){

	mat_t *result_mat = init_matrix(n->cols, n->rows); 
	for(int i = 0; i < n->rows; i++){
		for(int j = 0; j < n->cols; j++){
			result_mat->arr[j][i] = n->arr[i][j];  
		}
	}		

	return result_mat; 
}


mat_t *difference(mat_t *x, mat_t *y){

	mat_t *result = init_matrix(x->rows, x->cols); 
	for(int i = 0; i < x->rows; i++){
		for(int j = 0; j < x->cols; j++){
			result->arr[i][j] = x->arr[i][j] - y->arr[i][j];  
		}
	}

	return result; 
}

mat_t *apply(double(*activation_function)(double), mat_t *m) {

	mat_t *result = init_matrix(m->rows, m->cols); 

	for(int i = 0; i < m->rows; i++){
		for(int j = 0; j < m->cols; j++){
			result->arr[i][j] = (*activation_function)(m->arr[i][j]);
		}
	}

	return result; 
}


mat_t *copy_matrix(mat_t *m){
	mat_t *new = init_matrix(m->rows, m->cols); 
	for(int i = 0; i < m->rows; i++){
		for(int j = 0; j < m->cols; j++){
            new->arr[i][j] = m->arr[i][j];
		}
	}
	return new; 
}


mat_t **to_rows(mat_t *m) {

    mat_t **rows = (mat_t**)malloc(sizeof(mat_t*));
	for(int i = 0; i < m->rows; i++){
		rows[i] = malloc(sizeof(mat_t)); 	
	}

	for(int i = 0; i < m->rows; i++){
		mat_t *temp = init_matrix(1, m->cols); 
		for(int j = 0; j < m->cols; j++){
            temp->arr[0][j] = m->arr[i][j];
		}
		rows[i] = copy_matrix(temp); 
	}
	return rows; 
} 


bool compare_matrix(mat_t *n, mat_t *m){
	bool result = true; 
	for(int i = 0; i < n->rows; i++){
		for(int j = 0; j < n->cols; j++){
			if(n->arr[i][j] != m->arr[i][j]){
				result = false; 
			}
		}
	}
	return result; 
}

double uniform_distribution(double low, double high) {
	double difference = high - low; // The difference between the two
	int scale = 10000;
	int scaled_difference = (int)(difference * scale);
	return low + (1.0 * (rand() % scaled_difference) / scale);
}

void matrix_fill(mat_t *m, int n) {
	for (int i = 0; i < m->rows; i++) {
		for (int j = 0; j < m->cols; j++) {
			m->arr[i][j] = n;
		}
	}
}

void matrix_free(mat_t *m) {
	for (int i = 0; i < m->rows; i++) {
		free(m->arr[i]);
	}
	free(m->arr);
	free(m);
	m = NULL;
}

void randomize(mat_t *mat, int n){
	srand((unsigned)time(NULL));
	double min = -1.0 / sqrt(n);
	double max = 1.0 / sqrt(n);
	for(int i = 0; i < mat->rows; i++){
		for(int j = 0; j < mat->cols; j++){
			mat->arr[i][j] = uniform_distribution(min, max); 	
		}
	}
}

void print_matrix(mat_t *mat){

	// display array
	for(int i = 0; i < mat->rows; i++){
		for(int j = 0; j < mat->cols; j++){
			printf("%1.6f  ", mat->arr[i][j]); 
		}
		printf("\n"); 
	}
	 
}