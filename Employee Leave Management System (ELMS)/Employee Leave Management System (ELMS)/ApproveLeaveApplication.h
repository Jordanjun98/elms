#pragma once
#include <iostream>
#include <conio.h>
#include "header.h"	
#include <windows.h>
#include <fstream>
using namespace std;

int  Row = 5;
void LeaveStatus_File();
void Leave_Approving_Menu();
void SetColorAndBackground(int ForgC, int BackC);
bool Leave_Approval_Validation(char Leave_Status[]);


void LeaveStatus_File()		//Function to open Leave Status file
{
	FILE *fptr, *fptr2;												//Finding name of searched Employee
	int  option, counter = 1;
	char FType2[3], FNum2[5];
	char FType[3], FNum[5], comma[140], EmpName[41], To_Date[11];
	char From_Date[11], Status_Date[11], Leave_Type[3], Approval_Status[2], Leave_Reason1[51], Leave_Reason2[51];

	fptr = fopen("F:\\junmingelms\\LeaveApplication.txt", "r+");	//Open file named "Leave types.txt"

	if (fptr == NULL)
	{
		printf("File does not exist!");
		_getch();
	}
	int row = 5;
	while (!feof(fptr))
	{
		fgets(FType, 3, fptr);									//Read "Employee type"
		fgets(comma, 2, fptr);
		fgets(FNum, 5, fptr);									//Read "Employee number"
		fgets(comma, 2, fptr);

		fptr2 = fopen("F:\\junmingelms\\EmployeeProfile.txt", "r+");	//Open file named "EmployeeProfile"

		if (fptr2 == NULL)														//Check whether file successfully opened or not
		{
			printf("File does not exist!");
			_getch();
		}

		while (!feof(fptr2))														//Reading Employee Type and Number throughout the entire file
		{
			fgets(comma, 36, fptr2);
			fgets(FType2, 3, fptr2);
			fgets(comma, 2, fptr2);
			fgets(FNum2, 5, fptr2);
			fgets(comma, 71, fptr2);

			if (strcmp(FType, FType2) == 0 && strcmp(FNum, FNum2) == 0)	//Finding name using Employee type and number
			{
				fseek(fptr2, -70, SEEK_CUR);
				fgets(EmpName, 41, fptr2);
				SetCursorPosition(row, 5);
				printf(EmpName);										//Printing out Employee name based on Employee Type and Number
				break;
			}
		}
		fclose(fptr2);

		fgets(From_Date, 11, fptr);								//Read "From date"
		fgets(comma, 2, fptr);
		fgets(To_Date, 11, fptr);								//Read "To date"
		fgets(comma, 2, fptr);
 		fgets(comma, 4, fptr);
		fgets(Leave_Type, 3, fptr);								//Read "Leave Type"
		fgets(comma, 2, fptr);
		fgets(Leave_Reason1, 51, fptr);							//Read "Leave Reason"
		fgets(comma, 2, fptr);
		fgets(Leave_Reason2, 51, fptr);							//Read "Leave Reason"
		fgets(comma, 2, fptr);
		fgets(Approval_Status, 2, fptr);						//Read "Approval Status"
		fgets(comma, 3, fptr);

		SetCursorPosition(row, 47);
		printf(To_Date);										//Display "To date"
		SetCursorPosition(row, 60);
		printf(From_Date);										//Display "From date"
		SetCursorPosition(row, 77);
		printf(Leave_Type);

		SetCursorPosition(row, 85);
		printf(Leave_Reason1);
		SetCursorPosition(row, 140);
		printf(Approval_Status);

		SetCursorPosition(row + 1, 85 );
		printf(Leave_Reason2);

		row = row + 2;
	}

	fclose(fptr);

	do
	{
		counter = 1;
		Row = 5;
		InputEntry3(29, 9, 1, 'N', 0);							//Choosing which record number to edit

		option = atoi(Input);

		fptr = fopen("F:\\junmingelms\\LeaveApplication.txt", "r+");	//Open file named "Leave types.txt"
		if (fptr == NULL)
		{
			printf("File does not exist!");
			_getch();
		}
		while (counter <= option)
		{
			if (counter == option)
			{
				while (!Leave_Approval_Validation(Input))				//Validating Employee Type 
				{
					SetCursorPosition(30, 0);
					printf("\007Invalid input. Please try again.");
				}
				fseek(fptr, +138, SEEK_CUR);
				fputs(Input, fptr);
				break;
			}
			fseek(fptr, +141, SEEK_CUR);

			counter++;
			Row += 2;
		}
		fclose(fptr);
	} while (option != 0);
}
void Leave_Approving_Menu()		//Function to draw Leave Status Menu
{
	printf("\n\n");
	printf(" --------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf(" |NO|               APPLICANT                |          DATE           | LEAVE TYPE |                   LEAVE REASON                   | DECISION |\n");
	printf(" |--|----------------------------------------|-------------------------|------------|--------------------------------------------------|----------|\n");
	printf(" | 1|                                        |            -            |            |                                                  |   [ ]    |\n");
	printf(" |  |                                        |                         |            |                                                  |          |\n");
	printf(" | 2|                                        |            -            |            |                                                  |   [ ]    |\n");
	printf(" |  |                                        |                         |            |                                                  |          |\n");
	printf(" | 3|                                        |            -            |            |                                                  |   [ ]    |\n");
	printf(" |  |                                        |                         |            |                                                  |          |\n");
	printf(" | 4|                                        |            -            |            |                                                  |   [ ]    |\n");
	printf(" |  |                                        |                         |            |                                                  |          |\n");
	printf(" | 5|                                        |            -            |            |                                                  |   [ ]    |\n");
	printf(" |  |                                        |                         |            |                                                  |          |\n");
	printf(" | 6|                                        |            -            |            |                                                  |   [ ]    |\n");
	printf(" |  |                                        |                         |            |                                                  |          |\n");
	printf(" | 7|                                        |            -            |            |                                                  |   [ ]    |\n");
	printf(" |  |                                        |                         |            |                                                  |          |\n");
	printf(" | 8|                                        |            -            |            |                                                  |   [ ]    |\n");
	printf(" |  |                                        |                         |            |                                                  |          |\n");
	printf(" | 9|                                        |            -            |            |                                                  |   [ ]    |\n");
	printf(" |  |                                        |                         |            |                                                  |          |\n");
	printf(" |10|                                        |            -            |            |                                                  |   [ ]    |\n");
	printf(" |  |                                        |                         |            |                                                  |          |\n");
	printf(" --------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf(" 01 = Annual leave             03 = Marriege Leave\n");
	printf(" 02 = Compasionate leave       04 = No Pay Leave             [A]pproved     [R]ejected     [D]eleted     [P]ending     [0]Return\n");
	printf(" 05 = Medical Leave            06 = Hospitalization\n");
	printf(" Option [ ]\n");
}
bool Leave_Approval_Validation(char Leave_Status[])
{
	InputEntry3(Row, 140, 1, 'C', 0);									//Getting and controlling Employee Type input
	if (Input[0] == 'A' || Input[0] == 'R' || Input[0] == 'D' || Input[0] == 'P')
	{
		SetCursorPosition(30, 0);
		printf("                                       ");
		return true;
	}
	else return false;
}

void InputEntry(int row, int col, int maxdigit, char type, int validationtype)		//Function for controlling input entered
{
	SetCursorPosition(row, col);
	char  ch;
	int i = 0;

	while (1)
	{
		ch = toupper(_getch());										// Get ONE char/digit input from the User
		if (ch == 13)												// Carriage Return (Enter) - 13 - To EXIT from the WHILE
		{
			if (validationtype == 0)
				break;
			else if (validationtype == 1 && (strcmp(Input, "HR") == 0 || strcmp(Input, "AL") == 0 || strcmp(Input, "LE") == 0))
				break;

		}
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
		if (type == 'C' && !((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || (ch = 32)))
		{
			_putch(7);
			continue;
		}

		Input[i++] = ch;						// Store character entered into Input Variable
		_putch(Input[i - 1]);
	}
}


