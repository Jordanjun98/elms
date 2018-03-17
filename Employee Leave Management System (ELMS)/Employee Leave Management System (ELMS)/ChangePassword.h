#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "header.h"	

char OldPassword[11] = { NULL };
char NewPassword[11] = { NULL };
char RepeatPassword[11] = { NULL };

void Get_Password(int row, int col, char Input[10]);
void Password_Change();

// Function For Change Password
void ChangePassword()
{
	SetCursorPosition(1, 18);
	puts("CHANGE PASSWORD");
	SetCursorPosition(2, 18);
	puts("===============");

	SetCursorPosition(6, 18);
	printf("Enter Current Password :   [          ]");
	SetCursorPosition(6, 46);

	memset(Input, ' ', 10);
	memset(OldPassword, ' ', 10);
	memset(NewPassword, ' ', 10);
	memset(RepeatPassword, ' ', 10);

 	Get_Password(6, 46, OldPassword);   // Get old Password

	if (strcmp(OldPassword,Password) != 0)
	{
		SetCursorPosition(12, 05);
		printf("Invalid Current Password. Password does not Match Login Password!!  ");
		system("pause");
	}
	else 
	{
		SetCursorPosition(8, 18);
		printf("Enter New Password     :   [          ]");
		SetCursorPosition(8, 46);

		Get_Password(8, 46, NewPassword);		// Get New Password

		SetCursorPosition(10, 18);
		printf("Repeat Same Password   :   [          ]");
		SetCursorPosition(10, 46);
		 
		Get_Password(8, 46, RepeatPassword);	// Recheck the New Password

		if (strcmp(NewPassword, RepeatPassword) != 0)
		{
			SetCursorPosition(12, 05);
			printf("Invalid New Password. Password does not Match!!  ");
			system("pause");
		}
		else
		{
			Password_Change();
			SetCursorPosition(12, 05);
			printf("Password Changed Successfully!! ");
			system("pause");
		}
	}
}

// To Valid Each Input Entry by User
void Get_Password(int row, int col, char Input[10])
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
				Input[i - 1] = ' ';						// Store SPACE  into Variable Password
				i--;
				continue;
			}
		}

		Input[i++] = ch;						// Store character entered into Variable Password	ch = '*';
		_putch('*');

	}
}

// Function To Change and Update the New Password
void Password_Change() 
{
	char comma[120];
	char FUserID[11];
	char FPassword[11];

	int i = 0;
	FILE *fptr;

	// Read Login User Profile File
	fptr = fopen("F:\\junmingelms\\Login2.txt", "r+");

	if (fptr == NULL)
	{
		SetCursorPosition(12, 2);
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
		fgets(comma , 3, fptr);

		if (strcmp(FUserID, UserID) == 0 && strcmp(FPassword, OldPassword) == 0)	// If UserID & Password is valid ID in the system
		{
			fseek(fptr, -11, SEEK_CUR);
			fputs(NewPassword, fptr);
			break;
		}
	}
	fclose(fptr);

	fptr = fopen("F:\\junmingelms\\EmployeeProfile.txt", "r+");

	if (fptr == NULL)
	{
		printf("File does not exist!");
		_getch();
	}

	char FType[3];
	char FNum[5];

	while (!feof(fptr))
	{
		fgets(FUserID, 11, fptr);
		fgets(comma, 2, fptr);
		fgets(FPassword, 11, fptr);

		fgets(comma, 117, fptr);

		if (strcmp(FUserID, UserID) == 0 && strcmp(FPassword, OldPassword) == 0)	// If UserID & Password is valid ID in the system
		{
			fseek(fptr, -100, SEEK_CUR);
			fputs(NewPassword, fptr);
			strcpy(Password, NewPassword);
			break;
		}
	}
	fclose(fptr);
}


