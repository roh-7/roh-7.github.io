#include <ncurses.h>
#include <stdio.h>

int LRU(int time[],int n)
{
	int i,minimum=time[0],pos=0;
	for(i=1;i<n;i++)
	{
		if(time[i] < minimum)
		{
			minimum=time[i];
			pos=i;
		}
	}
	return pos;
}

void main()
{
	int size,n,op[10],pages[30],count=0,time[10],a,b,i,j,pos,faults=0;
	printf("Enter number of frames: ");
	scanf("%d", &size);
	printf("Enter number of pages: ");
	scanf("%d", &n);
	printf("Enter elements: ");
	for(i=0;i<n;i++)
		scanf("%d", &pages[i]);
	for(i=0;i<size;i++)
		op[i] = -1;
	for(i=0;i<n;i++)
	{
		a=b=0;
		for(j=0;j<size;j++)
		{
			if(op[j] == pages[i])
			{
				count++;
				time[j] = count;
				a=b=1;
				break;
			}
		}
		if(a==0)
		{
			for(j=0;j<size;j++)
			{
				if(op[j]==-1)
				{
					count++;
					faults++;
					op[j]=pages[i];
					time[j]=count;
					b=1;
					break;
				}
			}
		}
		if(b==0)
		{
			pos=LRU(time,size);
			count++;
			faults++;
			op[pos] = pages[i];
			time[pos] = count;
		}

		for(j=0;j<size;j++)
			printf("%d ", op[j]);

		printf("\n");
	}
	printf("\nTotal Hits = %d",n-faults);
	printf("\nTotal Page Faults = %d", faults);
	getch();
}

/*OUTPUT:
Enter number of frames: 3 
Enter number of pages: 10
Enter elements: 7 0 1 2 0 3 0 4 2 3
7 -1 -1 
7 0 -1 
7 0 1 
2 0 1 
2 0 1 
2 0 3 
2 0 3 
4 0 3 
4 0 2 
4 3 2 

Total Hits = 2
Total Page Faults = 8
*/
