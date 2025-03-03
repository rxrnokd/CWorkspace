#include <stdio.h>

int main(void) 
{

	int i, j, k, n;
	int icd, iunit, nbot, ntop, mid;
	int tb[20][2];
	
	n=0;
	
	while(1)
    { 
	   scanf("%d %d", &icd, &iunit);
	   
	   if(icd == 0)
	      break;
	      
       tb[n][0]=icd;
	   tb[n][1]=iunit;
	   n++;
	}	
	
	for(i=0; i<n-1; i++)
	    for(j=i+1; j<n; j++)
	    {
	    	if(tb[i][0] <= tb[j][0])
	    	continue;
	    	k=tb[i][0];
	    	tb[i][0]=tb[j][0];
	    	tb[j][0]=k;
	    	
	    	k=tb[i][1];
	    	tb[i][1]=tb[j][1];
	    	tb[j][1] =k;
	    	
		}
	    
	while(1)
	{
		scanf("%d", &icd);
		
		if(icd==0)
		   break;
		nbot=0;
		ntop=n-1;
		
		while(1)
		{
			mid=(nbot+ntop)/2;
			if(icd==tb[mid][0])
			{
				printf("%3d  %5d\n", tb[mid][0], tb[mid][1]);
				break;
			}
			if(icd < tb[mid][0])
			    ntop = mid-1;
			else
			    nbot=mid+1;
			    
			if(nbot>ntop)
			{
				printf("%3d   NOT FOUND\n", icd);
				break;
			}
		}
	}
}
	    
