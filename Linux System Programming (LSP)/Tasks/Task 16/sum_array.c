#include <stdio.h>

int main() {
    int sum = 0;
    int i;

    // Intentional logical error: should be i <= 10
    for (i = 1; i <= 10; i++) {
    sum += i;
}
    printf("Sum of numbers from 1 to 10 is: %d\n", sum);
    return 0;
}
