#pragma once
#include <stdlib.h>
#include <process.h>
#include "header.h"	

void Introduction();

// Function To Display FAQ
void FAQ()
{
	system("cls");

	FILE *fp1, *fp2;
	char a[200];


	fp1 = fopen("F:\\junmingelms\\FAQ.txt", "r");
	if (fp1 == NULL)
	{
		puts("cannot open this file");
		system("pause");
		exit(1);
	}

	printf("\n\n\nNow Uploading FAQ...\n");

	fp2 = fopen("F:\\junmingelms\\FAQ01.txt", "w");
	if (fp2 == NULL)
	{
		puts("Not able to open this file");
		system("pause");
		fclose(fp1);
		exit(1);
	}

	int i = 1;

	do {
		fgets(a, 200, fp1);
		fputs(a, fp2);

		printf("Loading Line %d - %s\n",i++,a);

	} while (!feof(fp1));

	fclose(fp1);
	fclose(fp2);

	printf("Finish Uploading FAQ!!\n");

	system("pause");

	Introduction();
}

// Function To Load and Display FAQ Routine
void DisplayFAQ()
{
	system("cls");

	FILE *fptr;
	char a[200];

	fptr = fopen("F:\\junmingelms\\FAQ01.txt", "r");
	if (fptr == NULL)
	{
		puts("Not able to open this file");
		system("pause");
		fclose(fptr);
		exit(1);
	}

	do {

		fgets(a, 200, fptr);
		printf("%s", a);

	} while (!feof(fptr));

	fclose(fptr);

	system("pause");
}

// Function to Load Introduction
void Introduction()
{
	FILE *fp1, *fp2;
	char a[80];

	system("cls");

	fp1 = fopen("F:\\junmingelms\\Introduction.txt", "r");
	if (fp1 == NULL)
	{
		puts("cannot open this file");
		system("pause");
		exit(1);
	}

	fp2 = fopen("F:\\junmingelms\\Introduction01.txt", "w");
	if (fp2 == NULL)
	{
		puts("Not able to open this file");
		system("pause");
		fclose(fp1);
		exit(1);
	}

	printf("\n\n\nNow Uploading Introduction...\n");

	int i = 1;

	do {
		fgets(a, 80, fp1);
		fputs(a, fp2);

		printf("Loading Line %d - %s\n", i++, a);

	} while (!feof(fp1));

	fclose(fp1);
	fclose(fp2);

	printf("Finish Uploading Introduction!!\n");

	system("pause");
}