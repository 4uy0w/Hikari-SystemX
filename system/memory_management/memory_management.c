#include "memory_register.h"
#include "memory_management.h"

extern void * __sbrk(unsigned long int size);
extern void * __malloc(unsigned long int size);

extern int create_memory_register(void *reg_ptr,unsigned long int reg_size);
extern int destroy_memory_register(void *reg_ptr);

void * __sbrk(unsigned long int size)
{
    void *memory_address = (void *) &heap[heap_index];
    heap_index += size;

    return (void *) memory_address;
}
void * __malloc(unsigned long int size)
{
    void *memaddr = (void *) __sbrk(size + 1);

    if(!create_memory_register(memaddr,size)){
        return (void *) -1;
    }

    return (void *) memaddr;
}

int create_memory_register(void *ptr_reg,unsigned long int reg_size)
{
    memory_register_t *register_ptr_metadata = (memory_register_t *) &memory_register[register_index];

    register_ptr_metadata->ptr = (void *) ptr_reg;
    register_ptr_metadata->size = reg_size;

    register_index += 1;

    return (register_ptr_metadata != (memory_register_t *) -1 ? 1 : 0);
}
int destroy_memory_register(void *ptr)
{
    memory_register_t *register_ptr = (memory_register_t *) -1,*pointed_reg = (memory_register_t *) -1;

    for(unsigned long int index = 0; index <= register_index; index++){
        register_ptr = (memory_register_t *) &memory_register[index];
        if(register_ptr->ptr == (void *) ptr){
            pointed_reg = (memory_register_t *) &memory_register[index];
            break;
        }
    }

    if(pointed_reg == (memory_register_t *) -1){
        return 0;
    }

    pointed_reg->ptr = (void *) -1;
    pointed_reg->size = 0;

    register_index -= 1;

    return 1;
}

