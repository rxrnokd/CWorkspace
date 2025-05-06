#include <stdio.h>

char *strcpy(char *dest, const char *src);

int main()
{
    char src[10] = "Hello";
    char dest[10] = "World";
    char *a = strcpy(dest, src);
    printf("Source: %s\n", dest);
    printf("Destination: %s\n", a);
    return 0;    
}

char *strcpy(char *dest, const char *src)
{
    char *start = dest;
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return start;
}