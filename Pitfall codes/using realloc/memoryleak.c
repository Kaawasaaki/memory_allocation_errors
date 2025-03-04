#include <stdio.h>
#include <stdlib.h>

void* my_realloc(void* ptr, size_t new_size) {
    // Use realloc to resize the memory block
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

    // Simulate the need for more memory, resize to 10 elements
    num_elements = 10;
    arr = my_realloc(arr, num_elements * element_size);

    // MEMORY LEAK PROBLEM:
    // If realloc fails, the old memory is not freed, but the pointer is overwritten.
    // As a result, the program loses access to the previously allocated memory.
    
    if (arr != NULL) {
        // Initialize the new part of the array
        for (size_t i = 5; i < num_elements; i++) {
            arr[i] = i + 1;
        }

        // Print the array
        for (size_t i = 0; i < num_elements; i++) {
            printf("arr[%zu] = %d\n", i, arr[i]);
        }

        // No free() call here, causing a memory leak.
    } else {
        printf("Memory reallocation failed.\n");
    }

    return 0;
}
