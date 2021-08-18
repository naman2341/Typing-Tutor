#include <stdio.h>
#include <string.h>
#include <time.h>
#include "typingtutorial.h"
char *buffer[1000];
int matchedcount=0;
int unmatchedcount=0;
int wordcount=0;
int typedwordcount = 0;
double wordperminute=0;
double time_taken;
int i=0;
void createbuffer(char * inptr){
	int c;
	int j=0;
	//remove '\n' received from fgets
	inptr[strlen(inptr) - 1] = '\0';
	// Returns first token
	char *token = strtok(inptr, " ");
	buffer[i++]=strdup(token);
	// Keep printing tokens while one of the
	// delimiters present in inptr.
	while (token != NULL) {
		token = strtok(NULL, " ");
		if(token != NULL){
			if(!istokeninbuffer(token,i))
				buffer[i++]=strdup(token);
		}
	}
	wordcount=i;
	//for(int k = 0; k < wordcount;k++)
		//printf("BUFFER: [%d], VALUE: %s\n",k,buffer[k]);
}
void processstatistics(){
	int c;
	char str[150];
	matchedcount=0;
	unmatchedcount=0;
	clock_t t;
	t = clock();
	while(gets(str)!=NULL){
		
		char *token = strtok(str, " ");
		typedwordcount++;
		matchwordinbuffer(token);
		while (token != NULL) {
			token = strtok(NULL, " ");
			if(token != NULL)
				typedwordcount++;
			matchwordinbuffer(token);
		}
	}
	t = clock() - t;
	time_taken = (((double)t)/CLOCKS_PER_SEC); // in seconds
	wordperminute = (typedwordcount/time_taken)*60;
}
void matchwordinbuffer(char * token){
	int ismatched=0;
	if(token != NULL){
		for(int i=0;i<wordcount;i++){
			if(strcmp(token,buffer[i])==0){
				++matchedcount;
				ismatched=1;	
			}
		}
		if (ismatched==0){
			++unmatchedcount;
		}
	}
	
}
int istokeninbuffer(char *inptr,int bufferlength){
	for(int k = 0; k < bufferlength;k++){
		if(strcmp(inptr,buffer[k])==0)
			return 1;
	}
	return 0;
}
	
