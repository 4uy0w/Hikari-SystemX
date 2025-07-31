#include "../../system/memory_management/memory_management.h" 

#include <stdio.h>

int main(int argc,char *argv[])
{
    char *test_alloc = (char *) __malloc(1000);
    char *str_test = "Hello world!";
    int index = 0;

    while(*str_test != '\0'){
        test_alloc[index++] = *str_test++;
    }
    test_alloc[index] = '\0';

    printf("%s \n",test_alloc);

    __free(test_alloc);

    return 0;
}
