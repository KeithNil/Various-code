#include "stdafx.h"
#include <stdio.h>
#include "stdlib.h"
#include "string.h"

#define MAX 50
#define lineLen 300


struct contacts
{
	char userName[MAX];
	char firstName[MAX];
	char lastName[MAX];
	char dispName[MAX];
	char jobTitle[MAX];
	char dept[MAX];
	long offNumber;
	char offPhone[MAX];
	char mobPhone[MAX];
	char fax[MAX];
	char address[MAX];
	char city[MAX];
	char state[MAX];
	long zip;
	char country[MAX];
};
int readfile(char *filename);
void printcontacts(contacts *ptr);
contacts*ptr2[lineLen];
int main()
{
	char filename[] = "C:\\Users\\keith\\Documents\\Programming\\AssignmentWeek19\\contacts.txt";
	int i = 0;
	if (!readfile(filename))
	{
		printf("Error opening file\n");
		return 0;
	}

	while (ptr2[i] != NULL)
	{
		printcontacts(ptr2[i]);
		i++;
	}
	return 0;



}
int readfile(char *filename)
{

	FILE *fptr;
	fptr = fopen(filename, "r");
	char line[lineLen];
	char *tok;
	char delim[] = ",";
	fgets(line, lineLen, fptr);
	int i = 0;

	while (!feof(fptr))
	{
		ptr2[i] = (contacts*)malloc(sizeof(contacts));
		fgets(line, lineLen, fptr);
		if ((tok = strtok(line, delim)) != NULL) strcpy(ptr2[i]->userName, tok);
		if ((tok = strtok(NULL, delim)) != NULL) strcpy(ptr2[i]->firstName, tok);
		if ((tok = strtok(NULL, delim)) != NULL) strcpy(ptr2[i]->lastName, tok);
		if ((tok = strtok(NULL, delim)) != NULL) strcpy(ptr2[i]->dispName, tok);
		if ((tok = strtok(NULL, delim)) != NULL) strcpy(ptr2[i]->jobTitle, tok);
		if ((tok = strtok(NULL, delim)) != NULL) strcpy(ptr2[i]->dept, tok);
		if ((tok = strtok(NULL, delim)) != NULL) ptr2[i]->offNumber = atof(tok);
		if ((tok = strtok(NULL, delim)) != NULL) strcpy(ptr2[i]->offPhone, tok);
		if ((tok = strtok(NULL, delim)) != NULL) strcpy(ptr2[i]->mobPhone, tok);
		if ((tok = strtok(NULL, delim)) != NULL) strcpy(ptr2[i]->fax, tok);
		if ((tok = strtok(NULL, delim)) != NULL) strcpy(ptr2[i]->address, tok);
		if ((tok = strtok(NULL, delim)) != NULL) strcpy(ptr2[i]->city, tok);
		if ((tok = strtok(NULL, delim)) != NULL) strcpy(ptr2[i]->state, tok);
		if ((tok = strtok(NULL, delim)) != NULL) ptr2[i]->zip = atof(tok);
		if ((tok = strtok(NULL, delim)) != NULL) strcpy(ptr2[i]->country, tok);
		i++;

	}
	fclose(fptr);
	return 1;

}
void printcontacts(contacts *ptr)
{
	printf("User Name:%s\nFirst Name:%s\nLast Name:%s\nDisplay Name:%s\nJob Title:%s\nDepartment:%s\nOffice Number:%d\nOffice Phone%s\nMobile Phone:%s\nFax:%s\nAddress:%s\nCity:%s\nState:%s\nZIP:%d\nCountry or Region:%s\n", ptr->userName, ptr->firstName, ptr->lastName, ptr->dispName, ptr->jobTitle, ptr->dept, ptr->offNumber, ptr->offPhone, ptr->mobPhone, ptr->fax, ptr->address, ptr->city, ptr->state, ptr->zip, ptr->country);
}


