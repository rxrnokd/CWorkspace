#include <stdio.h>

struct exam_record
{
    int number;
    char name[12];
    char chejum[20];
    char oxchar[20];
    int okcnt, jumsu, rank;
} students[10];

char daban[20] ={'1','3','2','1','4','3','2','1','2','3','4','4','2','1','3','2','1','4','2','1'};

int main(void)
{
    int i, j, k, it, L, n;
    FILE *ifp, *ofp;

    ifp = fopen("input.txt", "r");
    ofp = fopen("output.txt", "w");

    it = 0;

    for(i = 0; i<10; i++)
        fscanf(ifp, "%d %s %s", &students[i].number, students[i].name, students[i].chejum);

    for(i = 0; i < 10; i++)
    {   
        n = 0;
        for(j = 0; j < 20; j++)
        {   
            if(daban[j] == students[i].chejum[j])
            {   
                students[i].oxchar[j] = 'o';
                n = n + 1;
            }    
            else if(daban[j] != students[i].chejum[j])
                students[i].oxchar[j] = 'x';    
        }
        students[i].jumsu = n*5;
    }
    for(i = 0; i < 10; i++)
    {
        printf("%5d  %s  %3d  %20s\n", students[i].number, students[i].name, students[i].jumsu, students[i].oxchar);
    }
}