
#include <stdio.h>
#include <stdlib.h>

// Function to simulate calloc
void* my_calloc(size_t num_elements, size_t element_size) {
    // Allocate memory using malloc (similar to calloc)
    void* ptr = malloc(num_elements * element_size);
    
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Initialize the allocated memory to zero
    for (size_t i = 0; i < num_elements * element_size; i++) {
        *((char*)ptr + i) = 0;
    }

    return ptr;
}

int main() {
    size_t num_elements, element_size;
    
    printf("Enter the number of elements: ");
    scanf("%zu", &num_elements);
    
    printf("Enter the size of each element (in bytes): ");
    scanf("%zu", &element_size);

    // Allocate memory using the custom calloc
    void* memory = my_calloc(num_elements, element_size);

    if (memory == NULL) {
        printf("Memory allocation failed.\n");
    } else {
        printf("Memory allocated and initialized to zero.\n");

        // Simulate using the allocated memory (for example, an array of integers)
        if (element_size == sizeof(int)) {
            int* int_array = (int*)memory;
            for (size_t i = 0; i < num_elements; i++) {
                printf("int_array[%zu] = %d\n", i, int_array[i]);
            }
        }
        // MEMORY LEAK: We forgot to call free() here!
    }

    return 0;
}
