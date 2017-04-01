#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void fullArray(int nums[], int len);
int lowest(int nums[], int len);
int highest(int nums[], int len);
double average(int nums[], int len);
int numPassed(int nums[], int len);
int numFailed(int nums[], int len);

void main()
{
	int arr[10] = { 5, 25, 45, 66, 77, 34, 90, 22, 68, 84 };

	int low, high;
	double avg;
	int numFails, numPasses;
	
	

	printf("Here are the scores:\n");
	fullArray(arr, 10);
	printf("\n");
	
	low = lowest(arr, 10);
	printf("Lowest = %d\n", low);

	high = highest(arr, 10);
	printf("Highest = %d\n", high);

	avg = average(arr, 10);
	printf("Average = %.2lf\n", avg);

	numPasses = numPassed(arr, 10);
	numFails = numFailed(arr, 10);
	printf("There were %d Passes and %d Fails\n", numPasses, numFails);
	

    

}

void fullArray(int nums[], int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf("%-3d", nums[i]);
}

int lowest(int nums[], int len)
{
	int min = nums[0];
	for (int i = 0; i < len; i++)
	{
		if (nums[i] < min)
			min = nums[i];
	}
	return min;
}

int highest(int nums[], int len)
{
	int max = nums[0];
	 for (int i = 0; i < len; i++)
	{
		if (nums[i] > max)
			max = nums[i];
}
	return max;

}

double average(int nums[], int len)
{
	int i, total = 0;
	double avg;

	for (i = 0; i < len; i++)
	{
		total = total + nums[i];	
	}
	avg = (double)total / len;
	return avg;
}

int numPassed(int nums[], int len)
{
	int i, numPasses = 0;

	for (i = 0; i < len; i++)
	{
		if (nums[i] >= 40)
		{
			numPasses++;
		}
	}
	return numPasses;
}

int numFailed(int nums[], int len)
{
	int i, numFails = 0;

	for (i = 0; i < len; i++)
	{
		if (nums[i] < 40)
		{
			numFails++;
		}
	}
	return numFails;
}


