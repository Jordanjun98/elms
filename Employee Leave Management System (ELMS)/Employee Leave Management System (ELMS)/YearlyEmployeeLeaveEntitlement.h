#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"

FILE *fptr;
char FHRD[3];	// Human Resource 
char FALD[3];	// Academic Leader
char FLED[3];	// Lecturer
char FHR[3];	// Human Resource 
char FAL[3];	// Academic Leader
char FLE[3];	// Lecturer
char Input[51];  
char comma[2] = ",";

int UserInputValidation2(char &Option);
void GetYearlyEmployeeLeaveEntitlementRecord();
void EditHR();
void UpdateYearlyEmployeeLeaveEntitlement();
void InputEntry2(int row, int col, int maxdigit, char type, int validationtype);
void DisplayYearlyEmployeeLeaveEntitlementMenu();
int YearlyEmployeeLeaveEntitlement(char Option);

void OptionYearlyEmployeeLeaveEntitlementMenu()
{
	char Option = ' ';

	DisplayYearlyEmployeeLeaveEntitlementMenu();

	while (Option != 'R')
	{
		Option = YearlyEmployeeLeaveEntitlement(Option);
	}
}

void DisplayYearlyEmployeeLeaveEntitlementMenu()
{
	system("cls");					// Clear Screen

	GetYearlyEmployeeLeaveEntitlementRecord();

	printf("========================================================\n");
	printf("|      YEARLY EMPLOYEES LEAVE ENTITLEMENT              |\n");
	printf("========================================================\n");
	printf("========================================================\n");
	printf("|       Position          |            Days            |\n");
	printf("|                         |                            |\n");
	printf("========================================================\n");
	printf("|                         |                            |\n");
	printf("|     Human Resource      |        [  ]                |\n");
	printf("|                         |                            |\n");
	printf("--------------------------------------------------------\n");
	printf("|                         |                            |\n");
	printf("|     Academic Leaders    |        [  ]                |\n");
	printf("|                         |                            |\n");
	printf("--------------------------------------------------------\n");
	printf("|                         |                            |\n");
	printf("|       Lecturer          |        [  ]                |\n");
	printf("|                         |                            |\n");
	printf("--------------------------------------------------------\n");
	printf("|                                                      |\n");
	printf("|                                                      |\n");
	printf("| Select Option <E>dit , <S>ave , <R>eturn [ ]         |\n");
	printf("========================================================\n");
	SetCursorPosition(8, 36);
	printf("%d", HR);
	SetCursorPosition(12, 36);
	printf("%d", AL);
	SetCursorPosition(16, 36);
	printf("%d", LE);
}

int YearlyEmployeeLeaveEntitlement(char Option)
{
	SetCursorPosition(21, 44);
	Option = _getch();							//To capture an option
	Option = UserInputValidation2(Option);		//To validate the option

	if (Option == 69 || Option == 101)
	{
		EditHR();
	}
	else if (Option == 83 || Option == 115)
	{
		UpdateYearlyEmployeeLeaveEntitlement();
	}
	else if (Option == 82 || Option == 114)
	{
		return 'R';
	}
	return ' ';
}

int UserInputValidation2(char &Option)	//Validation message 
{
	while (Option != 69 && Option != 101 && Option != 83 && Option != 115 && Option != 82 && Option != 114)	//  69 = E , 83 = S ,  82 = R
	{
		SetCursorPosition(30, 18);
		printf("Invalid input pls type again\n");
		SetCursorPosition(21, 44);
		Option = _getch();
	}
	return Option;
}

void GetYearlyEmployeeLeaveEntitlementRecord()
{
	FILE *fptr;
	char FHR[3];	// Human Resource 
	char FAL[3];	// Academic Leader
	char FLE[3];	// Lecturer
	char comma[2];

	// Read Yearly Employee Leave Entitlement Records
	fptr = fopen("F:\\junmingelms\\YearlyEmployeeLeaveEntitlement.txt", "r");

	if (fptr == NULL)
	{
		SetCursorPosition(10, 2);
		printf("YearlyEmployeeLeaveEntitlement FILE DOES NOT EXIST! ... CONTACT ADMINSTRATOR, PRESS ANY KEY TO CONT");
		_putch(7);
		_getch();
		exit(0);
	}

	fgets(FHR, 3, fptr);			// Get HR Description
	fgets(comma, 2, fptr);
	fgets(FHR, 3, fptr);			// Get HR Leave Entitlement
	fgets(comma, 2, fptr);

	fgets(FAL, 3, fptr);			// Get AL Description
	fgets(comma, 2, fptr);
	fgets(FAL, 3, fptr);			// Get AL Leave Entitlement
	fgets(comma, 2, fptr);

	fgets(FLE, 3, fptr);			// Get LE Description
	fgets(comma, 2, fptr);
	fgets(FLE, 3, fptr);			// Get LE Leave Entitlement
	fgets(comma, 2, fptr);

	fclose(fptr);

	// Convert from CHAR to INT
	HR = atoi(FHR);
	AL = atoi(FAL);
	LE = atoi(FLE);
}

void UpdateYearlyEmployeeLeaveEntitlement()
{
	fptr = fopen("F:\\junmingelms\\YearlyEmployeeLeaveEntitlement.txt", "r+");

	if (fptr == NULL)
	{
		printf("File does not exist!");
		_getch();
	}

	fseek(fptr, 3, SEEK_CUR);
	fputs(FHR, fptr);

	fseek(fptr, 4, SEEK_CUR);
	fputs(FAL, fptr);

	fseek(fptr, 4, SEEK_CUR);
	fputs(FLE, fptr);

	fclose(fptr);

	SetCursorPosition(30, 18);
	printf("Yearly Employee Leave Entitlement UPDATED Successfully\n");
	_putch(7);
}

void EditHR()
{
	InputEntry2(8, 36, 2, 'N',0);		//  Capture HR Leave Entitlement
	strncpy(FHR, Input, 2);
	InputEntry2(12, 36, 2, 'N',0);		//  Capture AL Leave Entitlement
	strncpy(FAL, Input, 2);
	InputEntry2(16, 36, 2, 'N',0);		//  Capture LE Leave Entitlement
	strncpy(FLE, Input, 2);
}


// Function to Accept X Character or Number AND Validate Them Ensuring Correct Values Are Captured
void InputEntry2(int row, int col, int maxdigit, char type, int validationtype)
{
	SetCursorPosition(row, col);
	char  ch;
	int i = 0;

	while (1)
	{
		ch = _getch();										// Get ONE char/digit input from the User
		if (ch == 13)										// Carriage Return (Enter) - 13 - To EXIT from the WHILE
			break;

		if (i == maxdigit && ch != 8)						// Check for MAX Entered is 10 char/digit and BEEP
		{
			_putch(7);
			continue;
		}

		if (ch == 8)										// BACKSPACE Key is pressed  - 8
		{
			if (i == 0)										// Check to see Cursor at Position 1, Then BEEP SOUND
			{
				_putch(7);
				continue;
			}

			if (i == 1)										// Check to see Cursor at Position 1, Then BEEP SOUND
			{
				SetCursorPosition(row, col + (i - 1));
				_putch(7);
				i--;
				continue;
			}
			else											// Move Cursor Position Back by One space - Backward
			{
				SetCursorPosition(row, col + (i - 1));
				_putch(' ');
				SetCursorPosition(row, col + (i - 1));
				{
					Input[i - 1] = ' ';						// Store SPACE into Variable Input
				}
				i--;
				continue;
			}
		}

		// To Check & Validation For Type is only numeric number 0 To 9 digit
		if (type == 'N' && (ch < 48 || ch > 57))
		{
			_putch(7);
			continue;
		}

		// To Check & Validation For Type is only Character A TO Z OR a TO z
		if (type == 'C' && !((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)))
		{
			_putch(7);
			continue;
		}

		Input[i++] = ch;						// Store character entered into Input Variable
		_putch(Input[i - 1]);
	}
}
