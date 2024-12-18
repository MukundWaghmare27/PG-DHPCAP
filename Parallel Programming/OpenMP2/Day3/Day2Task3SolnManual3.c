//Sum of N natural numbers 

#include <stdio.h>
#include <omp.h>

#define N 1000000000
#define T 10

int main() {
    long long sum = 0;
    long partial_sum[T] = {0}; 

    #pragma omp parallel for num_threads(T)
    for (long long i = 1; i <= N; i++) {
        partial_sum[omp_get_thread_num()] += i; 
    }

    for (int i = 0; i < T; i++) {
        sum += partial_sum[i];
    }

    printf("Sum = %lld\n", sum);

    return 0;
}
