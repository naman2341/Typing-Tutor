#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "typingtutorial.h"
void createcontent(){
	FILE *filePointer ;
	char str[1000];
	filePointer = fopen("typetutorial.data", "w") ;
	int i=0;
	while(gets(str)!=NULL){
		fputs(str, filePointer) ;
		fputs("\n", filePointer) ;			 
	}
	fclose(filePointer);
}
void inittyping(){
	int i;
	FILE *filePointer ;
	char str[100];
	filePointer = fopen("typetutorial.data", "r") ;
	if ( filePointer == NULL )
	{
		printf( "typetutorial.data file failed to open." ) ;
	}
	 while( fgets ( str, 100, filePointer ) != NULL )
    {
		if(strcmp(str,"\n") != 0){
			//printf("%s",str);
			createbuffer(str);
		}
		else{
			printf("EMPTY LINE");
		}
    }
	fclose(filePointer);
}
void readfile(){
	int i;
	FILE *filePointer ;
	char str[100];
	filePointer = fopen("typetutorial.data", "r") ;
	if ( filePointer == NULL )
	{
		printf( "typetutorial.data file failed to open." ) ;
	}
	 while( fgets ( str, 100, filePointer ) != NULL )
    {
		if(strcmp(str,"\n") != 0){
			printf("%s",str);
		}
    }
	fclose(filePointer);
}	