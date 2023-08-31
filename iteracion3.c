#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define THRESHOLD 10

long long fib_recursive(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib_recursive(n - 1) + fib_recursive(n - 2);
    }
}

long long fib_recursive_omp(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n <= THRESHOLD) {
        return fib_recursive(n);
    } else {
        long long fib1, fib2;
        #pragma omp task shared(fib1)
        fib1 = fib_recursive_omp(n - 1);
        
        #pragma omp task shared(fib2)
        fib2 = fib_recursive_omp(n - 2);
        
        #pragma omp taskwait
        return fib1 + fib2;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <n>\n", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    
    // Establecer el número de threads
    omp_set_num_threads(4);

    double start_time = omp_get_wtime();
    long long result = fib_recursive_omp(n);
    double end_time = omp_get_wtime();

    printf("El %d-ésimo término de Fibonacci es: %lld\n", n, result);
    printf("Tiempo de ejecución: %lf segundos\n", end_time - start_time);

    return 0;
}
