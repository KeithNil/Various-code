#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdlib.h"

typedef struct
{
	char firstName[50];
	char lastName[50];
	long id;
	char english, french, maths, philosophy;
} result;


result *results[100];

int numResults = 0;
int readFile(char *fileName);
void initialiseResults();
void printResult(result *aResult);

int main()
{
	char fileName[] = "C:\\Users\\keith\\Documents\\Programming\\results1.txt";
	int i = 0;


	void initialiseResults();

	if (!readFile(fileName))
	{
		printf("File could not be opened !!\n");
		return 0;
	}
	printf("Surname\t\tFirst Name\t\tID\t\tMaths\t\tEnglish\t\tFrench\t\tPhilosophy\n");
	printf("=======\t\t==========\t\t==\t\t=====\t\t=======\t\t======\t\t\==========\n");

	while (results[i] != NULL)
	{
		printResult(results[i]);
		i++;
	}

	return 0;
}

void printResult(result *aResult)
{
	printf("%8s\t%10s\t%10d\t%10c\t%10c\t%10c\t%10c\n", aResult->lastName, aResult->firstName, aResult->id, aResult->maths, aResult->english, aResult->french, aResult->philosophy);
}

void initialiseResults()
{
	int i;

	for (i = 0; i < 100; i++) 
	{
		results[i] = NULL;
	}
}

int readFile(char *fileName)
{
	FILE *ptr = fopen(fileName, "r");
    int i;
	char line[100];

	fgets(line, 100, ptr);
    i = 0;

	while (!feof(ptr)) 
	{
		results[i] = (result*)malloc(line[i]*sizeof(result));
	//	results[i] = malloc(sizeof *results[i]);

		fscanf(ptr, "%d\t%s\t%s\t%c\t%c\t%c\t%c", &(*results + i)->id, &(*results + i)->firstName, &(*results + i)->lastName, &(*results + i)->english, &(*results + i)->maths, &(*results + i)->french, &(*results + i)->philosophy);
        numResults++;
		i++;
	}
   return 1;
}


