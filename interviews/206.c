/* 
 * [ Twitter ]
 * A permutation can be specified by an array P, where P[i] represents the location of the element at i in the permutation.
 * For example, [2, 1, 0] represents the permutation where elements at the index 0 and 2 are swapped.
 * Given an array and a permutation, apply the permutation to the array. For example, given the array ["a", "b", "c"]
 * and the permutation [2, 1, 0], return ["c", "b", "a"].
 */

 // Inputs
 // Permutation (P): [ 2, 1, 0]
 // Array of elements: [ "a", "b", "c" ]
 // Return: [ "c", "b", "a" ]

 #include <malloc>
 #include <stdio>

 char** getPerumations(int size, char **S, int *P) {
    if (size < 1 || S == NULL || p == NULL) {
         return -1;
    }

    char **R = malloc(size * sizeof (char *));
    for (int i = 0; i < size; i++) {
        R[i] = S[p[i]];
    }
    return R;
 }

 int main() {
    int size = 4;
    char **s = {"a", "b", "c", "d"};
    int *p = {1, 2, 3, 0};
    char **r;

    r = getPermutations(size, s, p);
    if (r == NULL) {
        fprintf(stderr, "Failed to get permutations");
        return -1;
    }
    fprintf(stdout, "Result: ");
    for (int i = 0; i < size; i++) {
        fprintf(stdout, r[i]);
    }
 }
