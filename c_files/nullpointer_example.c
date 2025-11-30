#include <stdio.h>

int main() {
    int *ptr = NULL;
    
    printf("About to cause a segmentation fault...\n");
    
    // Dereferencing a null pointer will cause a segfault and coredump
    *ptr = 42;
    
    printf("This line will never be reached.\n");
    return 0;
}

