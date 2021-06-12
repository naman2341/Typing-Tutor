#include <stdio.h>
#include <string.h>
#include "rlutil.h"

void input()
{
	char s[1000]="This is a test sentence",e[1000];
	int length=strlen(s),i;
	printf("%s",s);
	for(int i=0;i<=length-1;i++)
		printf("\b");
	for(i=0;i<length;i++)
	{
		e[i]=getch();
		if((int)(e[i])==8)
		{
			setColor(WHITE);
			printf("\b%c\b",s[i-1]);
			i-=2;
			continue;
		}
		if(e[i]==s[i])
			setColor(GREEN);
		else
			setColor(RED);
		printf("%c",s[i]);
		setColor(WHITE);
	}
	e[i]='\0';
	printf("\n\n%s\n",e);
}
int main()
{
	input();
	setColor(WHITE);
	return 0;
}