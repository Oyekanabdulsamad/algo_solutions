/*
 * Problem 2 - Dot (scalar) product & orthogonality
 * ------------------------------------------------
 * Vectors of IR (real numbers) are represented using arrays.
 *
 * (1) dot_product as a PROCEDURE: the result 'ps' is returned through an
 *     output parameter (pass by reference, using a pointer in C).
 * (2) Determine, for n pairs of vectors, whether each pair is orthogonal
 *     (two vectors are orthogonal when their dot product equals zero).
 * (3) Same algorithm, but using a dot_product FUNCTION (returns the value).
 *
 * This file demonstrates DIFFERENT WAYS OF PASSING PARAMETERS:
 *   - arrays passed by reference (default for C arrays)
 *   - the size 'n' passed by value
 *   - the result 'ps' passed by reference (procedure version) OR
 *     returned as a value (function version)
 */

#include <stdio.h>

#define MAX_DIM 100

/* ---------- Question 1: dot_product as a PROCEDURE ----------
 * v1, v2 : input vectors (passed by reference)
 * n      : dimension (passed by value)
 * ps     : output result (passed by reference via a pointer)
 */
void dot_product_proc(double v1[], double v2[], int n, double *ps) {
    *ps = 0.0;
    for (int i = 0; i < n; i++) {
        *ps += v1[i] * v2[i];
    }
}

/* ---------- Question 3: dot_product as a FUNCTION ----------
 * Returns the dot product as its value instead of an output parameter.
 */
double dot_product_func(double v1[], double v2[], int n) {
    double ps = 0.0;
    for (int i = 0; i < n; i++) {
        ps += v1[i] * v2[i];
    }
    return ps;
}

int main(void) {
    int n;        /* dimension of the vectors */
    int pairs;    /* number of pairs to test  */

    printf("Enter the dimension of the vectors: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_DIM) {
        printf("Invalid dimension.\n");
        return 1;
    }

    printf("Enter the number of vector pairs: ");
    if (scanf("%d", &pairs) != 1 || pairs <= 0) {
        printf("Invalid number of pairs.\n");
        return 1;
    }

    for (int k = 0; k < pairs; k++) {
        double v1[MAX_DIM], v2[MAX_DIM];

        printf("\nPair %d:\n", k + 1);
        printf("  Enter %d components of vector 1: ", n);
        for (int i = 0; i < n; i++) scanf("%lf", &v1[i]);

        printf("  Enter %d components of vector 2: ", n);
        for (int i = 0; i < n; i++) scanf("%lf", &v2[i]);

        /* --- Question 2: using the PROCEDURE --- */
        double ps;
        dot_product_proc(v1, v2, n, &ps);

        /* --- Question 3: using the FUNCTION (for comparison) --- */
        double ps_func = dot_product_func(v1, v2, n);

        printf("  Dot product (procedure) = %g\n", ps);
        printf("  Dot product (function)  = %g\n", ps_func);

        if (ps == 0.0) {
            printf("  => The two vectors are ORTHOGONAL.\n");
        } else {
            printf("  => The two vectors are NOT orthogonal.\n");
        }
    }

    return 0;
}
