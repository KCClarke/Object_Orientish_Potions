#include <stdio.h>

typedef struct potion_s
{
    char* name;
    void (*print_name)(struct potion_s *);
    
    int ounces;
    void (*print_ounces)(struct potion_s *);

} potion_t;

void print_name(potion_t* potion)
{
    printf("%s\n", potion->name);
}

void print_ounces(potion_t* potion)
{
    printf("%d ounces\n", potion->ounces);
}

int main()
{
    potion_t potion;
    
    potion.name = "matcha";
    potion.print_name = print_name;
   
    potion.ounces = 12;
    potion.print_ounces = print_ounces;

    potion.print_name(&potion);
    potion.print_ounces(&potion);
    
}
