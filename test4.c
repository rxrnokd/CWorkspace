#include <stdio.h>
#include <string.h>

int idt[5];
char rm1[9];
char rm2[5];

int main(void)
{
    int i, j, k, l;

    char rm_code[10][4] = {"S", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    scanf("%d %d %d %d %d", &idt[0], &idt[1], &idt[2], &idt[3], &idt[4]);

    for(i = 0; i < 5; i++)
    {
        memset(rm1, '\0', sizeof(rm1));
        memset(rm2, '\0', sizeof(rm2));

        j = idt[i] / 10;
        k = idt[i] % 10;

        for(l = 0; l < j; l++)
        {
            rm1[l] = 'X';
        }

        strcpy(rm2, rm_code[k]);

        printf("%d ====> %s%s\n", idt[i], rm1, rm2);
    }

}