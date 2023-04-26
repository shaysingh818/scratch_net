#ifndef MATRIX_H
#define MATRIX_H

#define TRUE 1
#define FALSE 0

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 

struct Matrix {
	int rows; 
	int cols; 
	double **arr; 
};

typedef struct Matrix mat_t; 


/* utilities */
mat_t *init_matrix(int rows, int cols); 
mat_t *apply(double(*activation_function)(double), mat_t *m);  
mat_t *copy_matrix(mat_t *m);
mat_t **to_rows(mat_t *m); 
mat_t **to_cols(mat_t *m);
double uniform_distribution(double low, double high);
bool compare_matrix(mat_t *n, mat_t *m); 
void matrix_fill(mat_t *m, int n); 
void matrix_free(mat_t *m);  
void randomize(mat_t *mat, int n); 
void print_matrix(mat_t *mat); 


/* operations */
mat_t *dot(mat_t *n, mat_t *m);
mat_t *multiply(mat_t *v1, mat_t *v2);
mat_t *elementwise_multiply(mat_t *v1, mat_t *v2); 
mat_t *add(mat_t *n, mat_t *m);
mat_t *sum(mat_t *m, int axis); 
mat_t *scale(mat_t *n, double value); 
mat_t *scale_add(mat_t *n, mat_t *m); 
mat_t *transpose(mat_t *n);
mat_t *difference(mat_t *x, mat_t *y); 



#endif
