#include <stdio.h>
#include <string.h>

int idt[5];
char rm[7];

int main(void) 
{

	int i,j,k,L,m,n;
	
	while(1)
    { 
	    scanf("%d %d %d %d %d", &idt[0], &idt[1],&idt[2],&idt[3],&idt[4]);
	    if (idt[0]==0)
	   	  break;   
	   
        for(i=0;i<5;i++)
        {
    	    memset(rm, ' ', sizeof(rm));
    	    n=idt[i];  //숫자 대입 
    	    k=n/10;  //몫 
    	    m=n%10;  //나머지 
    	
    	    j=0;
    	    if(k!=0)
		    {
			    do
			    {
				    rm[j]='X';
				    j++;
			    }while(j<k);
		    }
    	    if(m==9)
    	    {
    		    rm[j]='I';
    		    rm[j+1]='X';
		    }
		    else
		    {
			    if(m-5==0)
			       rm[j]='V';
			    else if (m-5<0)
			    {
				    if(m==4)
				    {
					   rm[j]='I';
					   rm[j+1]='V';
				    }
				    else
			        {
			    	   for(L=0;L<m;L++)
			    	   {
			    		   rm[j]='I';
			    		   j++;
					   }
				    }
			    }
			    else
			    {
				    rm[j]='V';
				    for(L=0;L<m-5;L++)
				    {
					   j++;
					   rm[j]='I';
				    }
			    }   
		    }
		printf("%2d ======> %7s\n", n,rm);
	    }
	
    }
	

}	
	
	
	
	
	
