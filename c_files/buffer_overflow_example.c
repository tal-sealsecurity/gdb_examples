#include <stdio.h>
#include <string.h>

int main() {
    // Allocate a small buffer on the stack
    char buffer[4];
    
    printf("Buffer allocated on stack with size 4\n");
    printf("About to overflow the buffer...\n");
    
    // This will overflow the buffer and cause a segfault/coredump
    // Writing more than 4 bytes will overwrite stack memory
    strcpy(buffer, "This is a very long string that will definitely overflow the 4-byte buffer and cause a segmentation fault!");
    
    printf("This line will likely never be reached.\n");
    return 0;
}

