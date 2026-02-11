#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];

    // Read input string
    scanf("%s", str);

    int len = strlen(str);

    // Reverse the string in-place
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }

    // Print reversed string
    printf("%s", str);

    return 0;
}
