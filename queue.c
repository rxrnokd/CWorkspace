#include <stdio.h>
#include <string.h>

int main(void) 
{
    char queue[5][3], data[3];
    int head, tail;
	int code, n;
	
	head=tail=0;

	while(1)
    { 
	   scanf("%d %s", &code, data);    
	   
	   if(code==0)
	      break;
	    
        if(code==2)
        {
       	    if(head==0)
       	  	{
       	  		printf("underflow");
       	  		break;
			}
		    printf(" delete   %4s\n", queue[head-1]);
		    
		    if(head==tail)
		    	head = tail =0;
		    else
		    	{
		    		head++;
		    		if(head>5)
		    			head=1;
				}
				continue;		
       	  	
	    }
	    n=tail-head+1;
	    if(n==0)
	    {
	   		printf("overflow\n");
	   		break;
		}
		if(n==5)
		{
			printf("overflow\n");
			break;
		}
		if(head==0)
			head=1;
		else
			{
				if(tail>=5)
					tail=0;
			}
			tail++;
			
			memcpy(queue[tail-1], data, 4);
			printf("insert   %4s\n",queue[tail-1]);
    }
}	
	
	
	
	
	
