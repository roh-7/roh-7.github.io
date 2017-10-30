#include<stdio.h>
void main() {
	char data[4],received[7];
	int i,numdata[7],numdata1[7],s[3];
	printf("\nEnter the 4-bit data: ");
	gets(data);
	for(i=0;i<4;i++) {
		numdata[i]=data[i]-48;
	}
	numdata[6]=(numdata[1]+numdata[2]+numdata[3])%2;
	numdata[5]=(numdata[0]+numdata[1]+numdata[2])%2;
	numdata[4]=(numdata[0]+numdata[2]+numdata[3])%2;
	printf("\nData Sent with parity bits: ");	
	for(i=0;i<7;i++)
		printf("%d",numdata[i]);
	printf("\nEnter the received data: ");
	gets(received);
	for(i=0;i<7;i++) {
		numdata1[i]=received[i]-48;
	}
	s[0]=(numdata1[1]+numdata1[2]+numdata1[3]+numdata1[6])%2;
	s[1]=(numdata1[0]+numdata1[1]+numdata1[2]+numdata1[5])%2;
	s[2]=(numdata1[0]+numdata1[2]+numdata1[3]+numdata1[4])%2;
	if(s[2]==0) {
		if(s[1]==0 && s[0]==0)
			printf("\nNo Error..\n");
		else if(s[1]==0 && s[0]==1)
			printf("\nError in q0..\n");
		else if(s[1]==1 && s[0]==0)
			printf("\nError in q1..\n");
		else
			printf("\nError in b2..\n");
	}
	else {
		if(s[1]==0 && s[0]==0)
			printf("\nError in q2..\n");
		else if(s[1]==0 && s[0]==1)
			printf("\nError in b0..\n");
		else if(s[1]==1 && s[0]==0)
			printf("\nError in b3..\n");
		else
			printf("\nError in b1..\n");
	}
}