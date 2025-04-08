#include <stdio.h>

int main()
{
	FILE* fp = fopen("output.txt", "w");

	int num = 0;

	while(num != -1)
	{
		printf("입력하세요: ");
		scanf("%d", &num);
		fprintf(fp, "%d ", num);
	}
	fclose(fp);
	return 0;
}
