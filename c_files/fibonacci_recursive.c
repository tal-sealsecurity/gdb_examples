#include <stdio.h>
#include <stdlib.h>

// Recursive Fibonacci function
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char *argv[]) {
    int n;
    
    if (argc < 2) {
        printf("Usage: %s <number>\n", argv[0]);
        printf("Example: %s 10\n", argv[0]);
        return 1;
    }
    
    n = atoi(argv[1]);
    
    if (n < 0) {
        printf("Error: Please provide a non-negative number\n");
        return 1;
    }
    
    printf("Calculating Fibonacci(%d)...\n", n);
    int result = fibonacci(n);
    printf("Result: %d\n", result);
    
    // Print sequence
    printf("Fibonacci sequence up to %d: ", n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    
    return 0;
}

