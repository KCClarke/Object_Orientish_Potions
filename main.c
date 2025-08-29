#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct potion_s
{
    char *name;
    void (*print_name)(struct potion_s *);

    int ounces;
    void (*print_ounces)(struct potion_s *);

} potion_t;

static void print_name(potion_t *p)
{
    printf("%s\n", p->name);
}

static void print_ounces(potion_t *p)
{
    printf("%d ounces\n", p->ounces);
}

char * copy_string(const char *src)
{
    size_t len = strlen(src) + 1;      // +1 for null terminator
    char * dst = malloc(len);
    if (dst != NULL)
    {
        memcpy(dst, src, len);
    }
    return dst;
}

potion_t create_potion(const char *name, const int ounces)
{
    potion_t potion;

    potion.name = copy_string(name);
    potion.print_name = print_name;
    
    potion.ounces = ounces;
    potion.print_ounces = print_ounces;

    return potion;
}

void destroy_potion(potion_t * potion)
{
    if (potion->name != NULL)
    {
        free(potion->name);
        potion->name = NULL;
    }
}

int main(void)
{
    // Create a potion
    potion_t matcha = create_potion("matcha", 12);

    // Call its "methods"
    matcha.print_name(&matcha);
    matcha.print_ounces(&matcha);

    // Clean up
    destroy_potion(&matcha);

    return 0;
}