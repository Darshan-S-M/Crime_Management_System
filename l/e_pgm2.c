#include <stdio.h>
#include <omp.h>

int main()
{
    int n;

    printf("Enter number of threads: ");
    scanf("%d", &n);

    omp_set_num_threads(n);

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();

        printf("Hello from thread %d out of %d threads\n",
               thread_id, total_threads);
    }

    return 0;
}

