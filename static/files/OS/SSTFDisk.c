#include <stdio.h>

int main()
{
	int req[20],final[20],d,n,i,j,temp,s,k=1,x=0,total=0;
	float avg;
	system("clear");
	printf("Enter head pointer position: ");
	scanf("%d",&req[0]);
	printf("\nEnter number of processes: ");
	scanf("%d",&n);
	printf("\nEnter processes in request order: ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&req[i]);
	}
	final[0]=req[0];
	for(i=0;i<n;i++)
	{
		s=1000;
		for(j=i+1;j<=n;j++)
		{
			if(req[i]>req[j])
				d=req[i]-req[j];
			else
				d=req[j]-req[i];
			if(d<s)
			{
				s=d;
				x=j;
			}
		}
		total+=s;
		temp=req[i+1];
		req[i+1]=req[x];
		req[x]=temp;
		final[k++]=req[i+1];
	}
	printf("\nProcessing order: ");
	for(i=0;i<=n;i++)
		printf("%d ",final[i]);
	printf("\nTotal Head Movement: %d",total);

	avg=total/n;
	printf("\nAverage Head Movement: %f\n",avg);
	return 0;
}

/*OUTPUT
Enter head pointer position: 53

Enter number of processes: 8

Enter processes in request order: 98 183 37 122 14 124 65 67

Processing order: 53 65 67 37 14 98 122 124 183 
Total Head Movement: 236
Average Head Movement: 29.000000
*/
