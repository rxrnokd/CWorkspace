#include <stdio.h>

#define YES 'O'
#define NO  'X'

struct exam_record
{
	int no;
	char name[12];
	char chejum[20];
	char oxchar[20];
	int okcnt, jumsu, rank;
}students[10];
 
char daban[20] ={'1','3','2','1','4','3','2','1','2','3','4','4','2','1','3','2','1','4','2','1'}; 

int main(void) {
	FILE *ifp,*ofp;
	int i, j, L, n, ch, it;
	float aver;
	
	ifp=fopen("input.txt","r");
	ofp=fopen("output.txt","w");
		
	it=0;
	
	for(i=0;i<10;i++)
		fscanf(ifp, "%d %s %s", &students[i].no, students[i].name, students[i].chejum);
	
	
	for(i=0; i<10;i++)
	{
		n=0;
		for(j=0;j<20;j++)
		{
			if(daban[j]==students[i].chejum[j])
			{
				students[i].oxchar[j]=YES;
				n=n+1;
			}
			else
			    students[i].oxchar[j]=NO;
		}
		students[i].okcnt=n;
		students[i].jumsu = n*5;
		students[i].rank =n;
		it=it + students[i].jumsu;
	}
	aver=(float)it/(float)10;
	 
	for(i=0; i<10; i++)
	{
	 	L=1;
	 	for(j=0; j<10; j++)
	 	    if(students[i].jumsu < students[j].jumsu)
	 	       L=L+1;
	 	       students[i].rank =L;
	} 
	for(i=0; i<60; i++)
	    (i==0)?fprintf(ofp, "\n=") : fputc('=',ofp);
	
	fprintf(ofp, "\n : :    :");
	for(i=0; i<16; i++)
	     fputc('*', ofp);
	     
	fprintf(ofp, "NUMBER");
	for(i=0;i<17; i++)
		fputc('*', ofp);
	fprintf(ofp,":   :   :   :\n :NO:   NAME     :");
	for(i=0;i<39;i++)
		fputc('-',ofp);
	fprintf(ofp,":COUNT   :TOTAL   :RANK:\n             :          :1:2:3:4:5:6:7:8:9:0:1:2:3:4:5:6:7:8:9:0: \n");	
	
	for(i=0;i<60;i++)
		fputc('=', ofp);
		
	for(i=0;i<10;i++)
	{
		fprintf(ofp, "\n   %2.2d   %-15s", students[i].no, students[i].name);
		for(j=0;j<20;j++)
			fprintf(ofp, "%c", students[i].oxchar[j]);
		fprintf(ofp, "%5d   %3d  %2d\n", students[i].okcnt, students[i].jumsu, students[i].rank);	
	}
	
	fprintf(ofp, "\n  CLASS TOTAL   = %d\n", it);
	fprintf(ofp, "\n  CLASS AVERAGE  = %6.2f\n", aver);
	
	fclose(ifp);
	fclose(ofp);
}
