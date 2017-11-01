#include<stdio.h>
#include<curses.h>
static int n;
int buffer[50];
int front=0;
int rear=0;
int count=0;
int prodsleep=0;
int consleep=0;
void Producer()
{
	int item;
	if(count<n)
	{
		printf("\n Enter the item to be inserted: ");
		scanf("%d",&item);
		buffer[front]=item;
		front=(front+1)%n;
		count++;
		if(consleep==1 && count==1)
		{
			printf("\n Wake up Consumer!");
		}
	}
	else
	{
		printf("\n Buffer is full!");
		prodsleep=1;
	}
}
void Consumer()
{
	int item;
	if(count>0)
	{
		item=buffer[rear];
		buffer[rear]=0;
		printf("\n Consumed item= %d",item);
		rear=(rear+1)%n;
		count--;
		if(prodsleep==1 && count==(n-1))
		{
			printf("\n Producer Wake up!");
		}
	}
	else
	{
		printf("\n Buffer is Empty!");
		consleep=1;
	}

}
void View()
{
	int i;
	printf("\nBuffer Data:\n");
	for(i=0;i<n;i++)
	{
		printf("| %d",buffer[i]);
	}
}
void main()
{
	int choice;

	printf("\n Enter the size of the buffer: ");
	scanf("%d",&n);
	do
	{
		printf("\n 1. Insert item into the buffer");
		printf("\n 2. Remove item from the buffer");
		printf("\n 3. View the buffer");
		printf("\n 4. Exit");

		printf("\n Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: Producer();
			break;
			case 2: Consumer();
			break;
			case 3: View();
			break;
			case 4: break;
		}
	}while(choice!=4);
}

/* Output: 

Enter the size of the buffer: 3

 1. Insert item into the buffer
 2. Remove item from the buffer
 3. View the buffer
 4. Exit
 Enter your choice: 1

 Enter the item to be inserted: 1

 1. Insert item into the buffer
 2. Remove item from the buffer
 3. View the buffer
 4. Exit
 Enter your choice: 1

 Enter the item to be inserted: 2

 1. Insert item into the buffer
 2. Remove item from the buffer
 3. View the buffer
 4. Exit
 Enter your choice: 1

 Enter the item to be inserted: 3

 1. Insert item into the buffer
 2. Remove item from the buffer
 3. View the buffer
 4. Exit
 Enter your choice: 1

 Buffer is full!
 1. Insert item into the buffer
 2. Remove item from the buffer
 3. View the buffer
 4. Exit
 Enter your choice: 3

Buffer Data:
| 1| 2| 3
 1. Insert item into the buffer
 2. Remove item from the buffer
 3. View the buffer
 4. Exit
 Enter your choice: 2

 Consumed item= 1
 Producer Wake up!
 1. Insert item into the buffer
 2. Remove item from the buffer
 3. View the buffer
 4. Exit
 Enter your choice: 2

 Consumed item= 2
 1. Insert item into the buffer
 2. Remove item from the buffer
 3. View the buffer
 4. Exit
 Enter your choice: 2

 Consumed item= 3
 1. Insert item into the buffer
 2. Remove item from the buffer
 3. View the buffer
 4. Exit
 Enter your choice: 2

 Buffer is Empty!
 1. Insert item into the buffer
 2. Remove item from the buffer
 3. View the buffer
 4. Exit
 Enter your choice: 3

Buffer Data:
| 0| 0| 0
 1. Insert item into the buffer
 2. Remove item from the buffer
 3. View the buffer
 4. Exit
 Enter your choice: 4

*/
