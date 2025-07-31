#include "../../system/memory_management/memory_management.h" 

#include <stdio.h>

struct __position{
    float x,y,z;
};

struct __human{
    char *name;
    int age,power,money;
    float height,weight,speed;
    struct __position * position;
};

typedef struct __human human_t;

human_t * create_human(char *human_name,int human_age,int human_power,int human_money,float human_height,float human_weight,float human_speed);
void destroy_human(human_t * human_ptr);

int main(int argc,char *argv[])
{
    human_t * Aldebaran = create_human("Aldebaran",15,100,10000,180.5,50.1,10.5);
    human_t * Sabian = create_human("Sabian",16,100,10000,180.5,60.5,100.4);
    
    if(Aldebaran != (human_t *) NULL){
        printf("Success to create human with name Aldebaran! \n");
    }
    if(Sabian != (human_t *) NULL){
        printf("Success to create human with name Sabian! \n");
    }

    printf("Nama manusia 1: %s \n",Aldebaran->name);
    printf("Nama manusia 2: %s \n",Sabian->name);

    destroy_human(Aldebaran);
    destroy_human(Sabian);

    return 0;
}

human_t * create_human(char *human_name,int human_age,int human_power,int human_money,float human_height,float human_weight,float human_speed)
{
    human_t *new_human = (human_t *) __malloc(sizeof(human_t));

    new_human->name = human_name;
    new_human->age = human_age;
    new_human->power = human_power;
    new_human->money = human_money;
    new_human->height = human_height;
    new_human->weight = human_weight;
    new_human->speed = human_speed;
    new_human->position = (struct __position *) NULL;

    return (new_human != (human_t *) -1 ? new_human : (human_t *) NULL);
}
void destroy_human(human_t * human_ptr)
{
    if(__free(human_ptr) == (void *) -1){
        printf("failed to dealocated human! \n");
    }
}