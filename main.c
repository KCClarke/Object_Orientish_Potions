#include <stdint.h>
#include <stdio.h>

#define NAME_LEN 16

typedef struct potion_s
{
    char name[NAME_LEN];
    void (*print_name)(struct potion_s *);

    uint8_t ounces;
    void (*print_ounces)(struct potion_s *);

} potion_t;

void print_name(potion_t * potion)
{
    printf("%s\n", potion->name);
}

void print_ounces(potion_t * potion)
{
    printf("%d ounces\n", potion->ounces);
}

/*
 * src means source
 * dst means destination
 */
void copy_name(const char src[], char dst[])
{
    for(uint8_t index = 0; index < NAME_LEN; ++index)
    {
        dst[index] = src[index];
        if ('\0' == src[index])
        {
            break;
        }
    }
    
    dst[NAME_LEN - 1] = '\0';
}

potion_t create_potion(const char *name, const int ounces)
{
    potion_t potion;

    copy_name(name, potion.name);

    /*
     * Connect the function pointer to the function definition.
     */
    potion.print_name = print_name;
    
    potion.ounces = ounces;
    potion.print_ounces = print_ounces;

    return (potion);
}

// C doing OOP
#define invoke(obj, method) ((obj).method(&(obj)))

int main(void)
{
    potion_t matcha = create_potion("matcha", 12);
    invoke(matcha, print_name);
    invoke(matcha, print_ounces);

    potion_t water = create_potion("water", 12);
    water.print_name(&matcha);
    water.print_ounces(&water);

}