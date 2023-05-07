/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"
#include <string.h>
/*
 * Add your unoptimized implementation here
 */

/*
	C = A x B x A' + B' x B'
*/
double* my_solver(int N, double *A, double* B) {
	size_t alloc_size = N * N;

	double* ab = calloc(alloc_size, sizeof(double));
	double* ab_at = calloc(alloc_size, sizeof(double));
	double* bt_bt = calloc(alloc_size, sizeof(double));
	double* C = calloc(alloc_size, sizeof(double));

	// A x B
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = i; k < N; k++) {
				ab[i * N + j] += A[i * N + k] * B[k * N + j];
			}
		}
	}

	// (A x B) x A'
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = j; k < N; k++) {
				ab_at[i * N + j] += ab[i * N + k] * A[j * N + k];
			}
		}
	}

	// B'x B'
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				bt_bt[i * N + j] += B[k * N + i] * B[j * N + k];
			}
		}
	}

	// C = A x B x A' + B' x B'
	for (int i = 0; i < N * N; i++) {
			C[i] += ab_at[i] + bt_bt[i];
	}

	free(ab);
	free(ab_at);
	free(bt_bt);

	return C;
}
