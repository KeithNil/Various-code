#include "stdafx.h"
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

#define NUM 55
#define NULL 0
#define LINE 81


struct MedIncome
{
	char state[40];
	int income[3];
};



void printLowestAllYears(struct MedIncome ListX);
void printHighestAllYears(struct MedIncome ListX);
void printLowestYear(struct MedIncome ListX);
void printHighestYear(struct MedIncome ListX);



void main()
{
	FILE *fptr;
	char string[LINE];
	char temp[LINE];
	int i, j, len, k;

	struct MedIncome List[NUM];

	fptr = fopen("C:\MedianIncome.txt", "r");
	fgets(string, LINE, fptr);

	while (!feof(fptr))
	{
		i = 0, j = 0, k = 0;
		len = strlen(string);

		if (k >= 2)
		{

			while ((string[i] != '\t') && (string[i] != '\n'))
			{
				temp[j] = string[i];
				j++;
				i++;
			}
			temp[j] = '\0';
			strcpy(List[k].state, temp);
			j = 0;
			i++;


			while ((string[i] != '\t') && (string[i] != '\n'))
			{
				temp[j] = string[i];
				j++;
				i++;
			}
			temp[j] = '\0';
			List[k].income[0] = atoi(temp);
			j = 0;
			i++;


			while ((string[i] != '\t') && (string[i] != '\n'))
			{
				temp[j] = string[i];
				j++;
				i++;
			}
			temp[j] = '\0';
			List[k].income[1] = atoi(temp);
			j = 0;
			i++;


			while ((string[i] != '\t') && (string[i] != '\n'))
			{
				temp[j] = string[i];
				j++;
				i++;
			}
			temp[j] = '\0';
			List[k].income[2] = atoi(temp);
			j = 0;
			i++;
			k++;
			fgets(string, LINE, fptr);
		}
		else
		{
			k++;
			fgets(string, LINE, fptr);
		}
		fclose(fptr);
	}


}

void printLowestAllYears(struct MedIncome ListX)
{
	int year, min, i, j;
	char lowestState[40];
	int lowestIncome = 0;

	for (i = 0; i < NUM; i++)
	{
		for (j = 0; ListX.income[j] < 3; j++)
		{
		    min = ListX.income[j];
			if (ListX.income[j] < min) min = ListX.income[j];
			if (ListX.income[j] = ListX.income[0]) year = 2003;
			if (ListX.income[j] = ListX.income[1]) year = 2004;
			if (ListX.income[j] = ListX.income[2]) year = 2005;

        }
		lowestState[i] = ListX.state[i];

		printf("Lowest Median Income was %d in %s in %d", lowestIncome, lowestState, year);
		
		return;
		
    }
}
void printHighestAllYears(struct MedIncome ListX)
{
	int year, max, i, j;
	char highestState[40];
	int highestIncome = 0;

	for (i = 0; i < NUM; i++)
	{
		for (j = 0; ListX.income[j] < 3; j++)
		{
			max = ListX.income[j];
			if (ListX.income[j] > max) max = ListX.income[j];
			if (ListX.income[j] = ListX.income[0]) year = 2003;
			if (ListX.income[j] = ListX.income[1]) year = 2004;
			if (ListX.income[j] = ListX.income[2]) year = 2005;
		}
		highestState[i] = ListX.state[i];

		printf("Highest Median Income was %d in %s in %d", highestIncome, highestState, year);

		return;



	}

}
void printLowestYear(struct MedIncome ListX)
{
	int  min, i, j;
	char lowestState[40];
	int lowestIncome = 0;

	for (i = 0; i < NUM; i++)
	{
		min = ListX.income[1];
		if (ListX.income[1] < min) min = ListX.income[1];
		lowestState[i] = ListX.state[i];


		printf("Lowest Median Income in 2004 was %d in %s", lowestIncome, ListX.state[i]);

		return;
    }
}
void printHighestYear(struct MedIncome ListX)
{
	int  max, i, j;
	char highestState[40];
	int highestIncome = 0;

	for (i = 0; i < NUM; i++)
	{
		max = ListX.income[1];
		if (ListX.income[1] > max) max = ListX.income[1];
		highestState[i] = ListX.state[i];

		
		
		printf("Lowest Median Income in 2004 was %d in %s", highestIncome, ListX.state[i]);

		return;
    }

}


