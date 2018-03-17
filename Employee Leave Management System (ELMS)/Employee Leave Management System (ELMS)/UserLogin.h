#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"

//GLOBAL VALUE DECLARATION
char UserID[11]		= "          ";
char Password[11]	= "          ";
char * UserType		= " ";
char * ValidUser	= " ";
char EmpType[3];
char EmpNumber[5];
char EmpName[41];

int HR = 0, AL = 0, LE = 0;

void SetCursorPosition(int  row, int  col);
void Get_Password();
void Validate_User();
void Entry_Validation(int row);
void GetUserDetails();

// Function to Capture UserID  Password
int UserIDs()
{
	SetCursorPosition(1, 18);
	puts("ELMS SYSTEM LOGIN SCREEN");
	SetCursorPosition(2, 18);
	puts("========================");

	SetCursorPosition(4, 18);
	puts("Enter UserID :     [          ]");
	SetCursorPosition(4, 38);

	Entry_Validation(4);

	UserID[10] = '\0';

	Get_Password();
	return 0;
}

// Function to Capture Password
void Get_Password()
{
	SetCursorPosition(6, 18);
	puts("Enter password :   [          ]");
	SetCursorPosition(6, 38);

	Entry_Validation(6);

	Password[10] = '\0';

	Validate_User();
}

// To Valid Each Input Entry by User
void Entry_Validation(int row)
{
	char  ch;
	int i = 0;

	while (1)
	{
		ch = _getch();										// Get ONE char/digit input from the User
		if (ch == 13)										// Carriage Return (Enter) - 13 - To EXIT from the WHILE
			break;

		if (i == 10 && ch != 8)								// Check for MAX Entered is 10 char/digit and BEEP
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
				SetCursorPosition(row, 38 + (i - 1));
					_putch(7);
			i--;
				continue;
			}
			else											// Move Cursor Position Back by One space - Backward
			{
				SetCursorPosition(row, 38 + (i - 1));
				_putch(' ');
				SetCursorPosition(row, 38 + (i - 1));
				if (row == 4)
				{
					UserID[i - 1] = ' ';					// Store SPACE into Variable User ID
				}
				else
				{
					Password[i - 1] = ' ';						// Store SPACE  into Variable Password
				}
				i--;
				continue;
			}
		}

		if (row == 4)
		{
			UserID[i++] = ch;						// Store character entered into Variable User ID
			_putch(UserID[i - 1]);
		}
		else
		{
			Password[i++] = ch;						// Store character entered into Variable Password	ch = '*';
			_putch('*');
		}
	}
}

// Validate User Entry Against The Login File
void Validate_User()
{
	char comma[2];
	char comma2[3];
	char FUserID[11];
	char FPassword[11];
	int i = 0;
	FILE *fptr;

	// Read Login User Profile File
	fptr = fopen("F:\\junmingelms\\Login2.txt", "r");

	if (fptr == NULL)
	{
		SetCursorPosition(10, 2);	
		printf("SYSTEM LOGIN FILE DOES NOT EXIST! ... CONTACT ADMINSTRATOR, PRESS ANY KEY TO CONT");
		_putch(7);
		_getch();
		exit(0);
	}

	while (!feof(fptr))
	{
		fgets(FUserID, 11, fptr);
		fgets(comma, 2, fptr);
		fgets(FPassword, 11, fptr);
		fgets(comma2, 3, fptr);
		

		if (strcmp(UserID, FUserID) == 0 && strcmp(Password, FPassword) == 0)	// If UserID & Password is valid ID in the system
		{
			if (strcmp(FUserID, "HRADMIN   ") == 0)			// IF UserID is valid System Adminstrator ID
			{
				UserType = "A";						// Set User Type to ADMINSTRATOR "A"
				ValidUser = "Y";					// Set Valid User to Yes "Y"
				break;
			}
			else
			{
				UserType = "N";						// Set User Type to Normal "N"
				ValidUser = "Y";					// Set Valid User to Yes  "Y"
				GetUserDetails();
				break;
			}
		}
	}
	comma[0] = ' ';
	fclose(fptr);

	if (*ValidUser == ' ')
	{
		SetCursorPosition(10, 18);
		printf("INVALID USER ID OR PASSWORD...Press any key To Continue");
		_putch(7);
		_getch();
		// Clear Screen
		system("cls");

	}
}

void GetUserDetails()
{
	char comma[40];
	char FUserID[11];
	char FPassword[11];
	char FType[3];
	char FNum[5];
	char FName[41];

	int i = 0;
	FILE *fptr;

	// Read Login User Profile File
	fptr = fopen("F:\\junmingelms\\EmployeeProfile.txt", "r");

	while (!feof(fptr))
	{
		fgets(FUserID, 11, fptr);
		fgets(comma, 2, fptr);
		fgets(FPassword, 11, fptr);
		fgets(comma, 15, fptr);
		fgets(FType, 3, fptr);
		fgets(comma, 2, fptr);
		fgets(FNum,  5, fptr);
		fgets(comma, 2, fptr);
		fgets(FName, 41, fptr);
		fgets(comma, 31, fptr);


		if (strcmp(FUserID, UserID) == 0 && strcmp(FPassword, Password) == 0)	// If UserID & Password is valid ID in the system
		{
			strncpy(EmpName, FName, 40);
			strncpy(EmpType, FType, 2);
			strncpy(EmpNumber, FNum, 4);
			break;
		}
	}
	comma[0] = ' ';
	fclose(fptr);
}