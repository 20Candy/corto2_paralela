// Corto 1, Computacion Paralela y Distribuida
// Carol Arevalo, 20461
// 30/08/2023


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función recursiva para calcular el término de Fibonacci
long long fib_recursive(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib_recursive(n - 1) + fib_recursive(n - 2);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Uso: %s <n>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);

    // Medir el tiempo de ejecución
    clock_t start_time = clock();
    unsigned long long result = fib_recursive(n);
    clock_t end_time = clock();

    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("El %d-ésimo término de Fibonacci es: %llu\n", n, result);
    printf("Tiempo de ejecución: %.6f segundos\n", execution_time);

    return 0;
}
