#include <stdio.h>
#include <string.h>
#include "rlutil.h"
#include <ctype.h>
#include "typingtutorial.h"
#include <time.h>

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


void input(char sg[][1000],int lines)
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
	char e[1000],s[1000];
	char c=217;
	int miss[30],miss2[30],x[3],y=0;
	char ele;
	int numb;
	int z=0;
	int length,i,error=0,flag=0;
	for (i=0;i<26;i++)
	{
		miss[i]=0;
		miss2[i]=0;
	}
	int time1=time(NULL);
	for(int h=0;h<lines;h++){
	system("cls");
	printf("******************************************************************************\n");
	printf("Type the following sentences:\n");
	strcpy(s,sg[h]);
	length=strlen(s);
	flag=0;
	s[length-1]=c;
	//length++;
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
			ele=tolower(s[i]);
			numb=(int)(ele)-97;
			//printf("%d",numb);
			if(numb<0||numb>=26)
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
			//printf("Er%d\n",error );
		}
		if(!flag)
			printf("%c",s[i]);
		setColor(WHITE);
	}
	e[i]='\0';
	}
	system("cls");
	int time2=time(NULL)-time1;
	printf("\nError: %d\n",error);
	for(i=0;i<26;i++)
	{
		//printf("%d\n",miss[i] );
		miss2[i]=miss[i];
	}
	Sort(miss,26);
	printf("\nThe top 3 mistake keys are \n");
	int none=0;
	for(z=0;z<3;z++)
	{
	for(i=0;i<26;i++)
	{
		//printf("%d\n",miss[i] );
		if(miss[0]==0&&none==0)
		{
			printf("NON");
			none=1;
			break;
		}
		if(miss[z]==miss2[i] && miss[z]!=0 && x[0]!=(char)(i+97) && x[1]!=(char)(i+97))
		{
			printf("%d. %c \n",z+1,(char)(i+97));
			x[y++]=(char)(i+97);
			i=26;
		}
	}
	setColor(WHITE);
	}
	//printf("\n\n%s\n",e);
}
