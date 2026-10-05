#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10000

int main()
{
    int A[N];
    long long serial_sum = 0;
    long long parallel_sum = 0;
    
    srand(42);

    for (int i = 0; i < N; i++)
    {
        A[i] = rand() % 100;
    }

    double start_serial = omp_get_wtime();

    for (int i = 0; i < N; i++)
    {
        serial_sum += A[i];
    }

    double end_serial = omp_get_wtime();


    double start_parallel = omp_get_wtime();

    #pragma omp parallel for reduction(+:parallel_sum)
    for (int i = 0; i < N; i++)
    {
        parallel_sum += A[i];
    }

    double end_parallel = omp_get_wtime();


    printf("Number of elements: %d\n", N);
    printf("Serial Sum        : %lld\n", serial_sum);
    printf("Parallel Sum      : %lld\n", parallel_sum);

    printf("\nSerial Execution Time   : %.9f seconds\n",
           end_serial - start_serial);

    printf("Parallel Execution Time : %.9f seconds\n",
           end_parallel - start_parallel);

    printf("Speedup                : %.2fx\n",
           (end_serial - start_serial) /
           (end_parallel - start_parallel));

    return 0;
}

