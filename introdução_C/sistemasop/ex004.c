#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Estrutura para passar os parâmetros da thread
typedef struct {
    int **A;
    int **B;
    int **C;
    int m, n, p;
    int start_row;
    int end_row;
} ThreadData;

void *multiply(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    for (int i = data->start_row; i < data->end_row; ++i) {
        for (int j = 0; j < data->p; ++j) {
            data->C[i][j] = 0;
            for (int k = 0; k < data->n; ++k) {
                data->C[i][j] += data->A[i][k] * data->B[k][j];
            }
        }
    }
    return NULL;
}

int **allocate_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        matrix[i] = (int *)malloc(cols * sizeof(int));
    return matrix;
}

void fill_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = rand() % 10;
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%4d ", matrix[i][j]);
        printf("\n");
    }
}
int main() {
    int m, n, p, num_threads;
    srand(time(NULL));

    printf("Digite as dimensões das matrizes A (MxN) e B (NxP):\n");
    printf("M: "); scanf("%d", &m);
    printf("N: "); scanf("%d", &n);
    printf("P: "); scanf("%d", &p);
    printf("Digite o número de threads: ");
    scanf("%d", &num_threads);

    int **A = allocate_matrix(m, n);
    int **B = allocate_matrix(n, p);
    int **C = allocate_matrix(m, p);

    fill_matrix(A, m, n);
    fill_matrix(B, n, p);

    printf("\nMatriz A:\n");
    print_matrix(A, m, n);

    printf("\nMatriz B:\n");
    print_matrix(B, n, p);

    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];

    int rows_per_thread = m / num_threads;
    int remaining_rows = m % num_threads;

    int current_row = 0;
    for (int i = 0; i < num_threads; i++) {
        int rows = rows_per_thread + (i < remaining_rows ? 1 : 0);

        thread_data[i].A = A;
        thread_data[i].B = B;
        thread_data[i].C = C;
        thread_data[i].m = m;
        thread_data[i].n = n;
        thread_data[i].p = p;
        thread_data[i].start_row = current_row;
        thread_data[i].end_row = current_row + rows;

        pthread_create(&threads[i], NULL, multiply, &thread_data[i]);
        current_row += rows;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nMatriz Resultado (A x B):\n");
    print_matrix(C, m, p);

    // Liberação de memória
    for (int i = 0; i < m; i++) free(A[i]);
    for (int i = 0; i < n; i++) free(B[i]);
    for (int i = 0; i < m; i++) free(C[i]);
    free(A); free(B); free(C);

    return 0;
}