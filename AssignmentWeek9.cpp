// AssignmentWeek9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>


int countVowels(char string[]);
int isVowel(char c);
int getLength(char string[]);
char upperLetter(char c);
void upperString(char string[]);

void main()
{

	char array1[500];
	int arrayLength, vowels;

	puts("Enter String:\n");
	gets_s(array1);

	
	arrayLength = getLength(array1);
	printf("\nLength of String = %d\n", arrayLength);

	vowels = countVowels(array1);
	printf("\nNumber of vowels = %d\n", vowels);


	upperString(array1);
	printf("\nIn CAPITALS : %s\n\n", array1 );



}





int countVowels(char string[])
{
	int len = getLength(string);
	int vowel = 0;

	for (int i = 0; i < len; i++)
	{
		isVowel(string[i]);
		if (isVowel(string[i]) == 1)
		{
			vowel++;
		}
		
	
	}
	return vowel;
}



int isVowel(char c)
{

	int v = 0;

	if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'I' || c == 'i' || c == 'O' || c == 'o' || c == 'U' || c == 'u')
	{
		v = v + 1;
		return v;
	}
	else
	{
		return 0;
	}
}



void upperString(char string[])
{
	int len = getLength(string);

	for (int i = 0; i < len; i++)
	{
		string[i]=upperLetter(string[i]);
	}

}


int getLength(char string[])
{
	int length = 0;

	for (int i = 0; string[i] != '\0'; i++)
	{
		length++;
	}
	return length;
}


char upperLetter(char c)
{

	if ((c >= 97) && (c <= 122))
	{
		c = c - 32;
	}
	return c;
}





