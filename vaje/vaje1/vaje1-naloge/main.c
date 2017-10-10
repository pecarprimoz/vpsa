#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

//Testi
void test_Random(double *p) {
    for (int i = 0; i < 10; i++) {
        printf("%f\n", *(p + i));
    }
    printf("\n");
}

void test_Matrix2D(double **p, int n, int r) {
    printf("2D: \n");
    for (int i = 0; i < (n % r == 0 ? r : r + 1); i++) {
        for (int j = 0; j < n / r; j++) {
            printf("%.2f ", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void test_Matrix1D(double **p, int n, int r) {
    printf("1D: \n");
    for (int i = 0; i < (n % r == 0 ? r : r + 1); i++) {
        for (int j = 0; j < n / r; j++) {
            printf("%.2f ", p[i][j]);
        }
    }
    printf("\n\n");
}
//Konec testov

//Naloga 1
double *Random(int n) {
    double *dp;
    dp = (double *) calloc(n, sizeof(double));
    for (int i = 0; i < n; i++) {
        dp[i] = (double) rand() / (double) RAND_MAX;
    }
    return dp;
}

//Naloga 2
double **Matrix(double *A, int n, int r) {
    double **dp;
    dp = (double **) calloc((n % r == 0 ? r : r + 1), sizeof(double *));
    for (int i = 0; i < n; i++) {
        dp[i] = (double *) calloc(n / r, sizeof(double));
    }
    int col_size, cur_row;
    col_size = cur_row = 0;
    for (int j = 0; j < n; j++) {
        if (col_size >= n / r) {
            col_size = 0;
            ++cur_row;
        }
        dp[cur_row][col_size] = A[j];
        col_size++;
    }
    test_Matrix1D(dp, n, r); //Deluje
    test_Matrix2D(dp, n, r); //Deluje
    return dp;
}

//Dobimo podatke od uporabinka
int *prompt_user() {
    int counter, current_number;
    counter = current_number = 0;
    int *pt;
    pt = (int *) calloc(2, sizeof(int));
    while (counter < 2) {
        switch (counter) {
            case 0:
                printf("Please input the number of elements that should be generated: ");
                break;
            case 1:
                printf("Please input the number of rows in the matrice: ");
                break;
            default:
                break;
        }
        scanf("%d", &current_number);
        if (current_number > INT_MAX && (counter == 1)) {
            printf("Please specify a number smaller than: %d\n", 100);
        } else if ((current_number > INT_MAX) && counter == 0) {
            printf("Please specify a number smaller than: %d\n", 100 * 100);
        } else {
            pt[counter] = current_number;
            current_number = 0;
            counter++;
        }
    }
    return pt;
}

//Naloga 3
double *Max(double *A, int n) {
    double *max_element;
    double max_value;
    max_value = 0;
    max_element = &max_value;
    for (int i = 0; i < n; i++) {
        if (A[i] > max_value) {
            max_value = A[i];
            max_element = &A[i];
        }
    }
    printf("Največje število je: %.2f; na naslovu:%x.\n", max_value, max_element);
    return max_element;
}

int main() {
    //Naloga 1
    clock_t start, stop;
    double time;
    int input_n, input_r;
    int *vals = prompt_user();
    input_n = vals[0]; //Določa št. elementov
    input_r = vals[1]; //Določa št. vrstic
    start = clock();
    double *p = Random(input_n);
    stop = clock();
    time = (double) (stop - start) / CLOCKS_PER_SEC;

    //Naloga 2
    Matrix(p, input_n, input_r);

    //Naloga 3
    Max(p, input_n);
    //printf("%p\n",max_element); //Deluje
    printf("Čas generiranja naključnih števil: %f\n", time);

    /* Debugganje
     * //test_Random(p); //Deluje
     * //printf("%d\n%d\n%d\n",input_random,input_row,input_col); //dobi pravilne vrednosti, omejeno z 100
     *  Made by primož
     * /
    return 0;
}