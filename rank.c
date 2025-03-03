#include <stdio.h>
int swap(int chi, int index, int a[100][3]);

int main(void) {
	int a[100][3];
	int i, j, index;
	int nbunho, njumsu, Ljumsu;
	float averg;
	
	index=0;
	Ljumsu=0;
	
	while(1)
    { 
	   scanf("%d %d", &nbunho, &njumsu);
	   
	   if(nbunho == 0)
	      break;
	      
       Ljumsu = Ljumsu + njumsu;
	   
	   a[index][0]=nbunho;
	   a[index][1]=njumsu;
	   index++;
	}	
	
	for(i=0; i<index; i++)
	    swap(i, index, a);
	    
	for(i=0;i<index;i++)
	    a[i][2]=i+1;
	    
	for(i=0;i<index;i++)
	    if(a[i][1] == a[i+1][1])
           a[i+1][2] = a[i][2];
		   
	printf("\n\n HAKSAENG");
	printf("\n   Bunho    Tjumsu     Rank\n");

    for(i=0;i<index;i++)
       printf("%10d %10d %10d\n", a[i][0],a[i][1], a[i][2]);
       
    averg = (float)Ljumsu/(float)index;
	printf("\n     Hryunggun   ====> %6.1f\n", averg);

}


int swap(int chi, int index, int a[100][3])
{
    //int chi, index;
    //int a[][3];

	int j, k, L;
	int max, jmax;
	
	jmax = chi;
	max = a[chi][1];
	
	for(j=chi+1;j<index;j++)
	   if(max-a[j][1] < 0)
	   {
	   	  jmax=j;
	   	  max = a[j][1];
	   }
	   
	k=a[chi][0];
	L = a[chi][1];

    a[chi][0] = a[jmax][0];
    a[chi][1] = a[jmax][1];
    a[jmax][0] = k;
    a[jmax][1] = L;
    
    return 0;	
}
