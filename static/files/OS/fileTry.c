
#include <stdio.h>

int main()
{
	FILE *fptr1, *fptr2;
	char c;
	char filename[20];

	fptr1 = fopen("hello.in", "r");
	if (fptr1 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		return 0;
	}
	fptr2 = fopen("hello.out", "w");
	if (fptr2 == NULL)
	{
		printf("Cannot open file %s \n", filename);
		return 0;
	}
	c = fgetc(fptr1);
	while (c != EOF)
	{
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}
	printf("\nContents copied\n");
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}