#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H 

#define HEAP_SIZE (1024 * 1024) * 10

unsigned char heap[HEAP_SIZE];
unsigned long int heap_index = 0;

void * __sbrk(unsigned long int size);
void * __malloc(unsigned long int size);
void * __free(void * ptr);
void * __memset(void * ptr,unsigned long int size,char c);

#endif /* MEMORY_MANAGEMENT_H */
