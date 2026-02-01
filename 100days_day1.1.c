#include <stdio.h>

#define N 10

int main() {
    int array[N+1], i, j, k, element;

    printf("Enter %d elements:\n", N);
    for(i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter location where you want to enter new element");
    scanf("%d", &k);

    printf("Enter element to add: ");
    scanf("%d", &element);

    for(j = N; j > k; j--) {
        array[j] = array[j-1];
    }

    array[k] = element;

    printf("Modified array:\n");
    for(i = 0; i <= N; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}