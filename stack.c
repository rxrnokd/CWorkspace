#include <stdio.h>
#include <string.h>

int push(int size, int *psw);
int pop(int *psw);

char stack[5][3], data[3];
int head;

int main(void) 
{

	int code, size, sw;
	sw=0;
	head=0;
	size=5;
	

	while(1)
    { 
	   scanf("%d %s", &code, data);    
	   
	   if(code==0)
	      break;
	    
	//   if (code==1)
	//    pop(&sw);
	//    else
	//      push(size, &sw);
	   (code==1)?pop(&sw):push(size, &sw);
	      
       if(sw==1)
	      break;
//	   printf("   code   data\n");
//	   printf("  %d   %4s\n", code,data);
	}
       printf("   code   data\n");
	   printf("  %d   %4s\n", code,data);
}
	
int pop(int *psw)
{
	if(head==0)
	{
		printf("underflow\n");
		*psw=1;
	}
	else
	{
		memcpy(data, stack[head-1],4);
		head--;
	}
//	return;
}

int push(int size, int *psw)
//int size;
//int *psw;
{
	head++;
	
	if(head>size)
	{
		printf("overflow\n");
		*psw=1;
	}
	else
	    memcpy(stack[head-1],data,4);
	//return;
}	
	
	
	
	
	
