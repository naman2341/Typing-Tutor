#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "typingtutorial.h"
#include<process.h>

void createcontent(){
	FILE *filePointer ;
	char str[1000];
	
	int i=0;
	while(gets(str)!=NULL){
		fputs(str, filePointer) ;
		fputs("\n", filePointer) ;			 
	}
	fclose(filePointer);
}

int readfile(char sg[][1000]){
	FILE *filePointer ;
	char str[1000];
	int i=0;
	int random=rand()%3;
	if(random==0)
		filePointer = fopen("type1.txt", "r") ;
	else if(random==1)
		filePointer = fopen("type2.txt", "r") ;
	else
		filePointer = fopen("type3.txt", "r") ;
	while(fgets(str,1000,filePointer))
	{
		strcpy(sg[i++],str);
		i++;
	}
	fclose(filePointer);
	return i;
}	