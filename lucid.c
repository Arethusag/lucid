#include "lucid.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int Lucid_Allocate_Memory(unsigned long size, void** out_pointer)
{
    size_t alloc_size;
    void*  alloc_result_pointer;
    if (out_pointer == NULL || size == 0UL) {
        return LUCID_FAILURE;
    }
    alloc_size = (size_t)size;
    if ((unsigned long)alloc_size != size) {
        *out_pointer = NULL;
        return LUCID_FAILURE;
    }

    alloc_result_pointer = malloc(alloc_size);
    if (alloc_result_pointer == NULL) {
        *out_pointer = NULL;
        return LUCID_FAILURE;
    }
    *out_pointer = alloc_result_pointer;
    return LUCID_SUCCESS;
}

int Lucid_Free_Memory(void* pointer)
{
    free(pointer);
    return LUCID_SUCCESS;
}

int Lucid_Reallocate_Memory(unsigned long new_size, void** in_out_pointer)
{
    size_t alloc_size;
    void*  realloc_result_pointer;
    if (in_out_pointer == NULL) {
        return LUCID_FAILURE;
    }
    alloc_size = (size_t)new_size;
    if ((unsigned long)alloc_size != new_size) {
        return LUCID_FAILURE;
    }
    if (*in_out_pointer == NULL) {
        return Lucid_Allocate_Memory(new_size, in_out_pointer);
    }
    realloc_result_pointer = realloc(*in_out_pointer, new_size);
    if (realloc_result_pointer == NULL) {
        return LUCID_FAILURE;
    }
    *in_out_pointer = realloc_result_pointer;
    return LUCID_SUCCESS;
}

int Lucid_Memory_Copy(void* destination, void* source, unsigned long byte_count)
{
    size_t        bytes_to_copy;
    unsigned long requested_byte_count;
    requested_byte_count = byte_count;
    if (requested_byte_count == 0UL) {
        return LUCID_SUCCESS;
    }
    if (destination == NULL || source == NULL) {
        return LUCID_FAILURE;
    }
    bytes_to_copy = (size_t)requested_byte_count;
    if ((unsigned long)bytes_to_copy != requested_byte_count) {
        return LUCID_FAILURE;
    }
    memcpy(destination, source, bytes_to_copy);
    return LUCID_SUCCESS;
}
