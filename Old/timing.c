#include <stdio.h>
#include<time.h>
#include <windows.h>
void timer()
{
	int ch,t,a1,a2;
	printf("Choose the test timings\n1. 1 Minute\n2. 3 Minutes\n3. 5 Minutes\n\n");
	scanf("%d",&ch);
	a1=time(NULL);
	ch=2*ch-1;
	t=ch*60;
	do
	{
		//Call Universal_color.c function here

		a2=time(NULL);
		ch=a2-a1-t;
		printf("Hi %d\n",ch);
	}while(ch<0);
}

int main()
{
	timer();
}
