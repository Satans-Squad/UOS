#include <stdio.h>
#include <omp.h>

int main() {
    int total_threads;

    #pragma omp parallel
    {
        // Get the total number of threads
        #pragma omp master
        {
            total_threads = omp_get_num_threads();
            printf("Total number of threads: %d\n", total_threads);
        }

        // Print thread numbers
        int thread_num = omp_get_thread_num();
        printf("Thread %d\n", thread_num);
    }

    return 0;
}
// gcc -fopenmp prime_no_parallel.c -o prime_no_parallel -lm
