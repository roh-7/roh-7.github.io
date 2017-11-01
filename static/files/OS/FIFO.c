#include<stdio.h>
#include<ncurses.h>

void main()
{int n[50],pf[10],i,j,p=0,hit=0,find,a,b;
 printf("\nEnter total no. of elements: ");
 scanf("%d",&a);
 printf("Enter Page Frame size: ");
 scanf("%d",&b);
 printf("\nEnter all elements: ");
 for(i=0;i<a;i++)
  scanf("%d",&n[i]);

 for(i=0;i<b;i++)
  pf[i]=-1;

 for(i=0;i<a;i++)
 {find=0;
  for(j=0;j<b;j++)
  {if(n[i]==pf[j])
   {printf("Hit at:\n");
    hit++;
    break;
   }
   else
    find++;
  }
  if(find==b)
  {pf[p]=n[i];
   p++;
   p=p%b;
  }
  for(j=0;j<b;j++)
   printf("%d\t",pf[j]);

  printf("\n");
 }
 printf("\nHits: %d",hit);
 getch();
}
/*OUTPUT
Enter total no. of elements: 10
Enter Page Frame size: 3

Enter all elements: 7 0 1 2 0 3 0 4 2 3
7	-1	-1	
7	0	-1	
7	0	1	
2	0	1	
Hit at:
2	0	1	
2	3	1	
2	3	0	
4	3	0	
4	2	0	
4	2	3	

Hits: 1
*/
