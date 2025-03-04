#include <stdio.h>
#include <stdlib.h>

void* my_realloc(void* ptr, size_t new_size) {
    // Using realloc to resize the memory block
    void* new_ptr = realloc(ptr, new_size);
    if (new_ptr == NULL) {
        printf("Memory reallocation failed.\n");
        return NULL;
    }
    return new_ptr;
}

int main() {
    size_t num_elements = 5;
    size_t element_size = sizeof(int);

    // Initially allocate memory for 5 integers
    int* arr = (int*)malloc(num_elements * element_size);
    if (arr == NULL) {
        printf("Initial memory allocation failed.\n");
        return 1;
    }

    // Initialize the array
    for (size_t i = 0; i < num_elements; i++) {
        arr[i] = i + 1;
    }

    // Simulate needing more memory, resize to 10 elements
    num_elements = 10;
    arr = my_realloc(arr, num_elements * element_size);

    // UNDEFINED BEHAVIOR: Modifying the original memory after realloc
    // This can result in undefined behavior, as realloc might move the memory.
    arr[5] = 99;  // Modifying after realloc call, if realloc moved the memory, it's unsafe!

    // Print the array
    for (size_t i = 0; i < num_elements; i++) {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    // Free the allocated memory
    free(arr);

    return 0;
}
