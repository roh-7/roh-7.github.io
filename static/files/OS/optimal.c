#include<stdio.h>
int main(){
	int a,b,c,n,p[20],f[3]={0},i,j,hit=0,flag=0,pointa=0,pointb=0,pointc=0,ck=0;
	freopen("opt.in","r",stdin);	
	printf("Enter the number of pages \n");
	scanf("%d",&n);	
	printf("Enter the pages \n");
	for(i=0;i<n;i++){
		scanf("%d",&p[i]);	
	}
	f[0]=p[0];
	printf("%d \t",f[0]);
	printf("%d \t",f[1]);
	printf("%d \t \n",f[2]);
	f[1]=p[1];
	printf("%d \t",f[0]);
	printf("%d \t",f[1]);
	printf("%d \t \n",f[2]);
	f[2]=p[2];
	printf("%d \t",f[0]);
	printf("%d \t",f[1]);
	printf("%d \t \n",f[2]);
	for(i=3;i<n;i++){
		ck=0;
		if(p[i]==f[0] || p[i]==f[1] || p[i]==f[2]){
			hit++;
		}	
		else{
			a=f[0];
			b=f[1];
			c=f[2];
			pointa=9999;
			pointb=9999;
			pointc=9999;
			for(j=i;j<n;j++){
				if(a==p[j] && pointa==9999){
					pointa=j;					
				}	
				if(b==p[j] && pointb==9999){
					pointb=j;					
				}	
				if(c==p[j] && pointc==9999){
					pointc=j;					
				}
			}	
			if(pointa>pointb && pointa>pointc && ck==0){
				f[0]=p[i];		
				ck++;		
			}
			if(pointb>pointa && pointb>pointc && ck==0){
				f[1]=p[i];
				ck++;		
			}
			if(pointc>pointa && pointc>pointb && ck==0){
				f[2]=p[i];
				ck++;			
			}
		}
		
		printf("%d \t",f[0]);
		printf("%d \t",f[1]);
		printf("%d \t \n",f[2]);

	}	
	for(i=0;i<3;i++){
		printf("%d \t",f[i]);
	}	
	printf("\nHits is %d \n",hit);
	printf("Faults is %d \n",n-hit);
	return 0;
}
