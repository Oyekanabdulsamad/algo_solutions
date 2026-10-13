/*
 * Problem 1 - Sum of distinct elements of two sets
 * -------------------------------------------------
 * Given two sets, find the sum of all elements that appear in ONLY ONE
 * of the two sets (i.e. the symmetric difference).
 *
 * Example:
 *   Set 1 : [3, 1, 7, 9]
 *   Set 2 : [2, 4, 1, 9, 3]
 *   Distinct (present in only one set): 7, 2, 4
 *   Output: 7 + 2 + 4 = 13
 *
 * Approach (as required):
 *   - Initialize sum = 0.
 *   - Scan each element of set 1; if it is NOT present in set 2, add it to sum.
 *   - Then scan each element of set 2; if it is NOT present in set 1, add it to sum.
 */

#include <stdio.h>

/* Returns 1 if value 'x' exists in array 'set' of length 'n', otherwise 0. */
int is_present(int set[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (set[i] == x) {
            return 1;
        }
    }
    return 0;
}

/* Computes the sum of elements that belong to exactly one of the two sets. */
int sum_distinct(int set1[], int n1, int set2[], int n2) {
    int sum = 0;

    /* Elements of set1 that are not in set2 */
    for (int i = 0; i < n1; i++) {
        if (!is_present(set2, n2, set1[i])) {
            sum += set1[i];
        }
    }

    /* Elements of set2 that are not in set1 */
    for (int j = 0; j < n2; j++) {
        if (!is_present(set1, n1, set2[j])) {
            sum += set2[j];
        }
    }

    return sum;
}

int main(void) {
    int set1[] = {3, 1, 7, 9};
    int set2[] = {2, 4, 1, 9, 3};
    int n1 = sizeof(set1) / sizeof(set1[0]);
    int n2 = sizeof(set2) / sizeof(set2[0]);

    int result = sum_distinct(set1, n1, set2, n2);
    printf("Sum of distinct elements = %d\n", result);  /* Expected: 13 */

    return 0;
}
