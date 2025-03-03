#include <stdio.h>
#include <string.h>

int store(int tk, int tpoint);
int sort();
int markr(int mk, int mmark);

char *title[7]={"ELECTRON", "HWANGONG", "TOMOK","\0"};
int data[50][5], three[3][50][2], count[3];
int inwon[3]={5,3,4};


int main(void) 
{
	FILE *ifp,*ofp;
	char name[50][12];
	int i,j,k;
	int point, mark;
	
	ifp=fopen("inpass.txt","r");
	ofp=fopen("outpass.txt","w");
		
	k=0;
	
	memset(count, 0 , sizeof(count));
	
	while(fscanf(ifp,"%d %s %d %d %d", &data[k][0], name[k], &data[k][1], &data[k][2], &data[k][3]) != EOF)
	{
		data[k][4]=0;
		k++;
	}
	point=2;
	
	store(k, point);
	sort();
	
	mark=1;
	markr(k, mark);
	
	for(i=0;i<3;i++)
	{
		inwon[i]=inwon[i]-count[i];
	    if(inwon[i]<0)
	       inwon[i]=0;
    }
    memset(count, 0, sizeof(count));
    
    point=3;
    
    store(k,point);
    sort();
    
    mark=2;
    markr(k,mark);
    
    for(i=0;i<3;i++)
    {
    	fprintf(ofp, "\n\n\n    *** %s ***\n\n", title[i]);
    	for(j=0;j<k;j++)
    	{
    		if(data[j][4]==0)
    			continue;
    		if((data[j][4]==1 && data[j][2]==i+1) || (data[j][4]==2 && data[j][3]==i+1))
    		    fprintf(ofp, " %d  %s\n",data[j][0],name[j]);
		}
		fprintf(ofp, "\f");  //page skip
	}
	fclose(ifp);
	fclose(ofp);
}

int store(int tk, int tpoint)
{
	int i, j, kwa, num, score;
	
	for(i=0; i<tk; i++)
	{
		if(data[j][4]!=0)
		   continue;
		kwa=data[i][tpoint];
		num=data[i][0];
		score=data[i][1];
		j=count[kwa-1];
		
		three[kwa-1][j][0]=num;
		three[kwa-1][j][1]=score;
	}
	//return;
}

int sort()
{
	int i,j,L,n,m;
	int isave;
	
	for(i=0; i<3; i++)
	{
		j=count[i];
		if(j<=1)
			continue;
		for(L=0; L<j-1; L++)
		   for(m=L+1; m<j; m++)
		   {
			   if(three[i][L][1]>=three[i][m][1])
			    	continue;
			   for(n=0; n<2; n++)
			   {
				   isave=three[i][L][n];
				   three[i][L][n]=three[i][m][n];
				   three[i][m][n]=isave;	
			   }	
		   }	
				
	}
	//return;	
}

int markr(int mk, int mmark)
{
	int i,j,L,m;
	int key;
	
	for(i=0;i<3;i++)
	{
		if(count[i]<=0)
			continue;
			
		if(count[i]<=inwon[i])
			j=count[i];
		else
			j=inwon[i];
			
		for(L=0;L<j;L++)
		{
			key=three[i][L][0];
			
			for(m=0; m<mk; m++)
				if(data[m][0] == key)
					break;
			data[m][4]=mmark;
		}
	}
	//return;
}



















