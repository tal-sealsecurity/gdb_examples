#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    int sum = 0;

    for (int i = 0; i <= 5; i++) {
        sum += i;
    }

    printf("sum: %d\n", sum);

    return 0;
}