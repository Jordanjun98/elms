#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"

// Function to Upload Public and University Holiday
void UpLoad_Public_University_Holiday()
{
	FILE *fp1, *fp2;
	char a[80];

	system("cls");

	fp1 = fopen("F:\\junmingelms\\Holiday.txt", "r");
	if (fp1 == NULL)
	{
		puts("Cannot Open Holiday.txt File!!");
		system("pause");
		exit(1);
	}

	fp2 = fopen("F:\\junmingelms\\Public_University_Holiday.txt", "w");
	if (fp2 == NULL)
	{
		puts("Not able to Create Public_University_Holiday.txt File!!");
		system("pause");
		fclose(fp1);
		exit(1);
	}

	int i = 1;
	printf("LOADING OF UNIVERSITY & PUBLIC HOLIDAY\n\n");

	do {
		fgets(a, 80, fp1);
		fputs(a, fp2);
		printf("Loading Record Line %d\n", i++);
	} while (!feof(fp1));

	fclose(fp1);
	fclose(fp2);

	printf("Completed Loading Unversity & Public Holiday!!  ");
	system("pause");
}