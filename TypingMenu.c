#include<stdio.h>
#include<stdlib.h>
#include "typingtutorial.h"
#include<string.h>

extern int matchedcount;
extern int unmatchedcount;
extern char *buffer[1000];
extern int wordcount;
extern double time_taken;
extern double wordperminute;
int main(){
	int i,k=0;
	int choice;
	char sg[100][1000];
	char str[10];
	strcpy(sg[0],"A");
	/*strcpy(sg[1],"SentenceB");
	strcpy(sg[2],"SentenceC");*/
	do {
		system("cls");
		printf("******************************************************************************\n");
		printf("\t\t\t\tMenu\n");
		printf("1. Create content to write to the file \n");
		printf("2. Start typing tutor \n");
		printf("3. Show statistics \n");
		printf("4. Exit \n");
		printf("******************************************************************************\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		if (choice==1){
			printf("Enter the content for tutorial");
			createcontent();
		}
		else if (choice==2)
		{
			system("cls");
			printf("******************************************************************************\n");
			/*do
			{
				strcpy(sg[k++],readfile());
			}while(strcmp(sg[k-1],"GGGGGGGGGG")); //GGG.. when NULL*/
			//printf("\n******************************************************************************\n");
			printf("Type the following sentences:\n");
			//processstatistics();
			k=readfile(sg);
			input(sg,k);
			printf("Press Any digit+Enter to continue...");
			scanf("%d", &i);
		}
		else if (choice==3)
		{   
			printf("******************************************************************************\n");
			printf("Matched word: %d\n", matchedcount);
			printf("Unmatched word: %d\n", unmatchedcount);
			printf("Typing taken in typing(in seconds): %f\n",time_taken);
			printf("Typing speed - Word pers minute: %f\n",wordperminute);
			printf("Press Any digit+Enter to continue...");
			scanf("%d", &i);
			printf("******************************************************************************\n");
		}
		else 
			printf("Wrong input");
	}while (choice!=4);
	return 0;
}