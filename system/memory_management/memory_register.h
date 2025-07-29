#ifndef MEMORY_REGISTER_H
#define MEMORY_REGISTER_H 

#define MEMORY_REGISTER_SIZE (1024 * 1024) * 5

struct __memory_register{
    void *ptr;
    unsigned long int size;
};

typedef struct __memory_register memory_register_t;

memory_register_t memory_register[MEMORY_REGISTER_SIZE];
unsigned long int register_index = 0;

int create_memory_register(void *reg_ptr,unsigned long int reg_size);
int destroy_memory_register(void *reg_ptr);

#endif /* MEMORY_REGISTER_H */
