#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct report{
	int timetaken;
	int accuracy;
	struct report *next;
}report;

report *head = NULL;

void calculate(int ,int ,int);
void begin(); 
void nextwork();
void choices();
void store(report *);

void store(report *ptr)
{
	head = ptr;
	head = NULL;	
}

int homepage(void)
{
	printf("WELCOME TO THE TYPING TUTOR!!");
	sleep(2);
	printf("\n\nHere, we will work on your typing speed make you a better typist.");
	printf("\n\nLet's start our journey to rise as the best typist of all times.");
	printf("\n\nAre you ready to begin?\n");
	choices();
	
}

void freemem(){};

void choices()
{
	int c;
	
	printf("\n\nPress 1 to begin .\nPress 2 to erase all progress.\n\n");
	scanf("%d", &c);
	switch(c){
        	case 1: begin();
        	        break;
		case 2: freemem;
			break;
			
                
        	default:printf("Please enter a valid option");
			choices();
    	}
}

void begin()
{
	int correct=0, wrong=0, i, x, timetaken;
	clock_t start, end;
	char a[100], c ;
	char b[] = "HELLO TYPING TUTOR";
	
	printf("enter the following words as it is as fast as you can:\n");
	sleep(2);
	getchar();
	printf("%s\n", b);
	start= clock();
	scanf(" %[^\n]s", a);
	end= clock();
	x = strlen(b);
	for(i = 0 ; i < x ; i++){
	        if (a[i] == b[i])
	            correct++;
	        else
	            wrong++;
	}
	timetaken = (int)(end-start) / CLOCKS_PER_SEC;
	calculate(correct, wrong, timetaken);
	nextwork();
}

void calculate(int correct,int wrong,int timetaken)
{
	int per;
	report *ptr;
	
	ptr = (report*)malloc(sizeof(report*));
	ptr->timetaken = timetaken;
	printf("Right letters: %d\n", correct);
	printf("wrong letters: %d\n", wrong);
	printf("timetaken: %d\n", timetaken);
	ptr->accuracy = (100*correct)/(correct+wrong);
	printf("accuracy: %d", ptr->accuracy);
	printf("%%");
	printf("\n\n");
	store(ptr);
	if (ptr->accuracy==100)
		printf("*****\n you got 5 stars\n");
	else if (ptr->accuracy>80&&ptr->accuracy<100)
	    printf("****\n you got 4 stars\n");
	else if (ptr->accuracy>50&&ptr->accuracy<=80)
		printf("***\n you got 3 stars\n");
	else if (ptr->accuracy>30&&ptr->accuracy<=50)
		printf("**\n you got 2 stars\n");
	else if (ptr->accuracy>10&&ptr->accuracy<=30)
	    printf("*\n you got 1 stars\n");
	else
		printf("your performance is poor");
			
}



void nextwork()
{
	int c;
	
	printf("Do you want to continue?(1=Yes/0=No)");
	scanf("%d", &c);
	switch(c){
		case 1: begin();
			break;
		case 0: choices();
			break;
		default:printf("wrong input");
			nextwork();
	}
}



int main(void)
{
        homepage();
        return 0;
}
