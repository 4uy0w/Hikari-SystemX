#ifndef CONFIG_READER_H
#define CONFIG_READER_H 

struct __property{
    char *key,*value,*owner;
    struct __property *next;
};

typedef struct __property property_t;

struct __object{
    char *name;
    property_t *property;
};

typedef struct __object object_t;

property_t *create_property(char property_key[],char property_value[],char property_owner[]);
void change_property(property_t *property_ptr,char property_key[],char property_value[]);
void destroy_property(property_t *property_ptr);

object_t *create_object(char object_name[]);
void add_property(object_t *object_ptr,property_t *property_ptr);
void pop_property(object_t *object_ptr);
void destroy_object(object_t *object_ptr);

#endif // CONFIG_READER_H 