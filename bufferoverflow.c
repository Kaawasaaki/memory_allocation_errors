#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Allocate memory for a fixed size
    char *buffer = (char *)malloc(10 * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Attempt to copy a user-provided string without checking its length
    char input[50];
    printf("Enter a string (up to 50 characters): ");
    scanf("%49s", input); // Accept input up to 49 characters (+ null terminator)

    // Copy input to the buffer (may overflow if input is too large)
    strcpy(buffer, input);

    // Print the buffer
    printf("Buffer: %s\n", buffer);

    // Free allocated memory
    free(buffer);
    return 0;
}
