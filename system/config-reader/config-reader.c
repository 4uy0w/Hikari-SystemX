#include <stdio.h>
#include <stdlib.h>
#include "config-reader.h"

extern property_t *create_property(char property_key[],char property_value[],char property_owner[]);
extern void change_property(property_t *property_ptr,char property_key[],char property_value[]);
extern void destroy_property(property_t *property_ptr);

extern object_t *create_object(char object_name[]);
extern void add_property(object_t *object_ptr,property_t *property_ptr);
extern void pop_property(object_t *object_ptr);
extern void destroy_object(object_t *object_ptr);

property_t *create_property(char property_key[],char property_value[],char property_owner[])
{
    property_t *new_property = (property_t *) malloc(sizeof(property_t *));

    new_property->owner = property_owner;
    new_property->key = property_key;
    new_property->value = property_value;
    new_property->next = NULL;

    return (new_property != NULL ? new_property : NULL);
}
void change_property(property_t *property_ptr,char property_key[],char property_value[])
{
    if(property_ptr == NULL){
        return;
    }

    property_ptr->key = property_key;
    property_ptr->value = property_value;
}
void destroy_property(property_t *property_ptr)
{
    free(property_ptr);
}

object_t *create_object(char object_name[])
{
    object_t *new_object = (object_t *) malloc(sizeof(object_t ));

    new_object->name = object_name;
    new_object->property = NULL;

    return (new_object != NULL ? new_object : NULL);
}
void add_property(object_t *object_ptr,property_t *property_ptr)
{
    if(object_ptr == NULL || property_ptr == NULL){
        return;
    }

    if(object_ptr->property == NULL){
        object_ptr->property = property_ptr;
    }else{
        property_ptr->next = object_ptr->property;
        object_ptr->property = property_ptr;
    }
}
void pop_property(object_t *object_ptr)
{
    if(object_ptr == NULL){
        return;
    }

    object_ptr->property = object_ptr->property->next;

    property_t *prop_tmp = object_ptr->property;
    prop_tmp = prop_tmp->next;

    if(prop_tmp == NULL){
        return;
    }

    object_ptr->property = prop_tmp;
}
void destroy_object(object_t *object_ptr)
{
    free(object_ptr);
}