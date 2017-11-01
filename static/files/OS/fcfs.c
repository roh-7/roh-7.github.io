#include <stdio.h>
void main(){
	freopen("ab.in","r",stdin);
	int a[100],n,avg,mov,i,off=0;
	printf("Enter the number of request in queue :\n");
	scanf("%d",&n);
	printf("Enter the queue :\n");
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);	
	}
	printf("Enter the head position :\n");
	scanf("%d",&a[0]);
	for(i=0;i<n;i++){
		if(a[i+1]>a[i]){
			off+=a[i+1]-a[i];
		}
		else{
		       off+=a[i]-a[i+1];		
		}
	}
	printf("Offset is %d\n",off);
	printf("Avg is %f\n",(float)off/n);
}
