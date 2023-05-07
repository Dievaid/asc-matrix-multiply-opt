/*
 * Tema 2 ASC
 * 2023 Spring
 */
#include "utils.h"

#include <cblas.h>

/* 
 * Add your BLAS implementation here
 */
double* my_solver(int N, double *A, double *B) {
	size_t alloc_size = N * N;
    double *ab = calloc(alloc_size, sizeof(double));
    double *ab_at = calloc(alloc_size, sizeof(double));

	// A x B
    cblas_dcopy(alloc_size, B, 1, ab, 1);
    cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, N, N, 1, A, N, ab, N);

	// (A x B) x A'
    cblas_dcopy(alloc_size, ab, 1, ab_at, 1);
    cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasTrans, CblasNonUnit, N, N, 1, A, N, ab_at, N);

	// B'x B'
    cblas_dgemm(CblasRowMajor, CblasTrans, CblasTrans, N, N, N, 1, B, N, B, N, 1, ab_at, N);

    free(ab);

    return ab_at;
}
