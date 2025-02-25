#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocate memory for 10 characters
    char *buffer = (char *)malloc(10 * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Attempt to copy a string longer than the allocated size
    strcpy(buffer, "This is a string longer than 10 characters");

    // Print the buffer (may cause undefined behavior)
    printf("Buffer: %s\n", buffer);

    // Free the allocated memory
    free(buffer);
    return 0;
}
