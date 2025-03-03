#include <stdio.h>

int main(void) 
{

	int arr[50][50];
	int n;    
	
    scanf("%d",&n);
    
    int center = (n+1)/2;
    int count = 0;
    
    int i = 1;
    int j = center;
    
    for(int k = 0; k< n*n; k++)
	{
        arr[i][j] = ++count;
        
        if(count % n == 0) //row
		   i++;
        else
		{
            i--;  //row 
            j++;  // column
        }
        if(i < 1)
		   i = n;
		   
        if(j > n) 
		   j = 1;
        
    }
 
    for(int i = 1; i <= n; i++)
	{
        for(int j = 1; j <= n; j++)
		    printf("%3d ", arr[i][j]);
        printf("\n");
    }
 
    return 0;
}
	    
