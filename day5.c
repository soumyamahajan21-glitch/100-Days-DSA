#include <stdio.h>

int main() {
    int p;
    scanf("%d", &p);
    int log1[p];
    for(int i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }
    
    int q;
    scanf("%d", &q);
    int log2[q];
    for(int i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }
    
    // Allocate merged array
    int merged[p + q];
    int i = 0, j = 0, k = 0;
    
    // Two-pointer merge
    while(i < p && j < q) {
        if(log1[i] <= log2[j]) {
            merged[k++] = log1[i++];
        } else {
            merged[k++] = log2[j++];
        }
    }
    
    // Append remaining from log1
    while(i < p) {
        merged[k++] = log1[i++];
    }
    
    // Append remaining from log2
    while(j < q) {
        merged[k++] = log2[j++];
    }
    
    // Print merged log
    for(int idx = 0; idx < k; idx++) {
        printf("%d ", merged[idx]);
    }
    printf("\n");
    
    return 0;
}