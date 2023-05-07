/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"

double* my_solver(int N, double *A, double* B) {
	size_t alloc_size = N * N;

	double* ab = calloc(alloc_size, sizeof(double));
	double* ab_at = calloc(alloc_size, sizeof(double));

	register int i, j, k;

	// A x B
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			register double* p_a = A + i * (N + 1);
			register double* p_b = B + i * N + j;
			register double sum = 0.0;
			for (k = i; k < N; k++) {
				sum += *p_a * *p_b;
				p_a++;
				p_b += N;
			}
			ab[i * N + j] = sum;
		}
	}

	// (A x B) x A'
	for (i = 0; i < N; i++) {
		register double* p_ab = ab + i * N;
		for (j = 0; j < N; j++) {
			register double* p_a = A + j  * (N + 1); 
			register double sum = 0.0;
			for (k = j; k < N; k++) {
				sum += *(p_ab + k) * *(p_a + k - j);
			}
			ab_at[i * N + j] = sum;
		}
		
	}

	// B'x B'
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			register double* p_b1 = B + i;
			register double* p_b2 = B + j * N;
			register double sum = 0.0;
			for (k = 0; k < N; k++) {
				sum += *p_b1 * *p_b2;
				p_b1 += N;
				p_b2 += 1;
			}
			ab_at[i * N + j] += sum;
		}
	}

	free(ab);
	return ab_at;
}

