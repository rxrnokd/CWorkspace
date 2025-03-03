#include <stdio.h>

int main(void) 
{

	int tb[8], r, c;
	int i, j, n, itot;
	int save, data, cd;
		
	while(1)
    { 
	   scanf("%d", &data);    
	   
	   if(data == 0)
	      break;
	      
       printf("\n\n INPUT DATA : %d\n", data);
	   save = data;
	   itot=0;
		
	
	for(i=0; i<8; i++)
	    {
	    	j=7-i;
	    	n=data%10;
	    	itot = itot + n;
	    	tb[j] = n;
	    	data = data / 10;
		}
		
	for(i=0; i<7; i++)
	    (i==0)?printf("\n DIGIT SUM : %d + ", tb[i]) : printf("%d + ", tb[i] );
	    
	printf("%d = %d\n", tb[7], itot);
		    
    r = itot % 10;
    printf("\n REMAINDER : %d\n", r);
    
    c = 10 - r;
    cd = save * 10 + c;
    
    printf("\n CHECK DIGIT : %d\n\n CODE : %d\n", c, cd);
    }
}
	    
