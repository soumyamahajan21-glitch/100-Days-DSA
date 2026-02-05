#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // Read n
    
    int arr[n];       // VLA for dynamic size
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);  // Read array
    }
    
    // Two-pointer reversal: left from start, right from end
    int left = 0;
    int right = n - 1;
    while(left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
    
    // Print reversed array
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}