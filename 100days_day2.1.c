#include <stdio.h>

int main() {
    int arr[50], size, pos, i;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    printf("Enter array elements-");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    for (i = pos - 1; i < size - 1; i++)
        arr[i] = arr[i + 1];
    size--;
    printf("Array after deletion-");
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    return 0;
}
