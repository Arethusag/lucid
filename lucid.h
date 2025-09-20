#ifndef LUCID_H
#define LUCID_H
#define LUCID_SUCCESS 0
#define LUCID_FAILURE -1

int Lucid_Allocate_Memory(unsigned long size, void** out_pointer);
int Lucid_Free_Memory(void* pointer);
int Lucid_Reallocate_Memory(unsigned long new_size, void **in_out_pointer);
int Lucid_Memory_Copy(void* destination, void* source, unsigned long byte_count);

#endif
