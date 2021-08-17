#include <stdio.h>
#include <string.h>
#include "rlutil.h"
#include <ctype.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Sort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] < arr[j+1])
              swap(&arr[j], &arr[j+1]);
}


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
	int miss[27],miss2[27],x[3],y=0;
	char ele;
	int numb;
	int z=0;
	int length=strlen(s),i,error=0,flag=0;
	s[length]=c;
	length++;
	printf("%s",s);
	s[length-1]=ascii_enter;
	for (i=0;i<26;i++)
	{
		miss[i]=0;
		miss2[i]=0;
	}
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
			ele=tolower(s[i]);
			numb=(int)(ele)-97;
			if(numb==-65)
				numb=26;
			//printf("Position %d\n",numb);
			miss[numb]++;
			//printf("Value%d\n",miss[numb]);
			setColor(RED);
			if(s[i]==ascii_space)
			{	
				printf("%c",219);
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
	for(i=0;i<26;i++)
	{
		miss2[i]=miss[i];
	}
	Sort(miss,26);
	printf("\nThe top 3 mistake keys are ");
	for(z=0;z<3;z++)
	{
	for(i=0;i<26;i++)
	{
		//printf("%d\n",miss[i] );
		if(miss[z]==miss2[i] && miss[z]!=0 && x[0]!=(char)(i+97) && x[1]!=(char)(i+97))
		{
			printf("%c ",(char)(i+97));
			x[y++]=(char)(i+97);
			i=26;
		}
	}
	}
	//printf("\n\n%s\n",e);
}

int main()
{
	input();
	setColor(WHITE);
	return 0;
}
