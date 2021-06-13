#include <stdio.h>
#include <string.h>
#include "rlutil.h"

void input()
{
	int ascii_bkspace,ascii_enter,ascii_space;
	#ifdef _WIN32
		ascii_bkspace=8;
		ascii_enter=13;
		ascii_space=32;
	#else
		ascii_bkspace=127;
		ascii_enter=10;
		ascii_space=32;
	#endif
	char s[1000]="This is a test sentence",e[1000];
	char c=217;
	int length=strlen(s),i,error=0,flag=0;
	s[length]=c;
	length++;
	printf("%s",s);
	s[length-1]=ascii_enter;
	for(int i=0;i<=length-1;i++)
		printf("\b");
	for(i=0;i<length;i++)
	{
		flag=0;
		e[i]=getch();
		if(s[i+1]=='\0' && e[i]!=s[i])
		{
			i--;
			continue;
		}
		if((int)(e[i])==ascii_bkspace)
		{
			setColor(WHITE);
			printf("\b%c\b",s[i-1]);
			i-=2;
			continue;
		}
		if(e[i]==s[i])
			setColor(GREEN);
		else
		{
			setColor(RED);
			if(s[i]==ascii_space)
				{	printf("%c",219);
					flag++;
				}
		error++;
	}
	if(!flag)
		printf("%c",s[i]);
	setColor(WHITE);
}
e[i]='\0';
printf("\nError: %d",error);
	//printf("\n\n%s\n",e);
}
int main()
{
	input();
	setColor(WHITE);
	return 0;
}
