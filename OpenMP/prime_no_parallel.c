#include <stdio.h>
#include <math.h>
#include <omp.h>

#define MAX_RANGE 1000000

int main() {
    int is_prime[MAX_RANGE + 1];
    int i, j, n, count = 0;
    int num_threads;
    double start_time, end_time;
    double sqrt_n;

    printf("Enter the range (1 to %d): ", MAX_RANGE);
    scanf("%d", &n);

    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    omp_set_num_threads(num_threads);

    start_time = omp_get_wtime();

    for (i = 2; i <= n; i++) {
        is_prime[i] = 1;
    }

    sqrt_n = sqrt(n);

    #pragma omp parallel for private(j) shared(is_prime) schedule(static, 1)
    for (i = 2; i <= (int)sqrt_n; i++) {
        if (is_prime[i]) {
            for (j = i * i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    printf("Prime numbers in the range 1 to %d:\n", n);
    for (i = 2; i <= n; i++) {
        if (is_prime[i]) {
            printf("%d ", i);
            count++;
            
        }
    }

    end_time = omp_get_wtime();

    printf("\nTotal prime numbers: %d\n", count);
    printf("Sequential time taken: %.6f seconds\n", end_time - start_time);

    count = 0;

    start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:count)
    for (i = 2; i <= n; i++) {
        if (is_prime[i]) {
            count++;
        }
    }

    end_time = omp_get_wtime();

    printf("Parallel time taken: %.6f seconds\n", end_time - start_time);

    return 0;
}

// gcc -fopenmp prime_no_parallel.c -o prime_no_parallel -lm
