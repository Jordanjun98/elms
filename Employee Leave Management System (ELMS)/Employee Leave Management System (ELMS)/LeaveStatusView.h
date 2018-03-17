#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include "header.h"	
using namespace std;

void Leave_Status_Menu();							//Function Prototypes
// bool Employee_Type_Validation(char Employee_Type[]);
// bool Employee_Number_Validation(char Employee_Number[]);
void LeaveStatus_File(char employ_type[], char employ_number[]);
void SetColorAndBackground(int ForgC, int BackC);
void LeaveStatusView();

// Function to View Leave Status of the Application
void LeaveStatusView()
{
	system("cls");

	char Employ_Type[3], Employ_Number[5];
	strncpy(Employ_Type, EmpType, 3);
	strncpy(Employ_Number, EmpNumber, 5);

	Leave_Status_Menu();

	SetCursorPosition(3, 24);
	printf(Employ_Type);
	SetCursorPosition(4, 24);
	printf(Employ_Number);

	SetCursorPosition(5, 24);
	LeaveStatus_File(Employ_Type, Employ_Number);
	SetCursorPosition(20, 30);

	system("pause:");
}

void Leave_Status_Menu()		//Function to draw Leave Status Menu
{
	cout << "       PENDING LEAVE APPLICATION STATUS" << endl << endl;
	cout << "     -------------------------------------------------------------------------------------------------------------" << endl;
	cout << "     | Employee Type   [  ]                                                                                      |" << endl;
	cout << "     | Employee Number [    ]                                                                                    |" << endl;
	cout << "     | Employee Name   [                                        ]                                                |" << endl;
	cout << "     |-----------------------------------------------------------------------------------------------------------|" << endl;
	cout << "     |       APPLIED DATE      |               |              |                                                  |" << endl;
	cout << "     |-------------------------| APPROVAL DATE | LEAVE STATUS |                   LEAVE REASON                   |" << endl;
	cout << "     |    FROM    |     TO     |               |              |                                                  |" << endl;
	cout << "     |------------|------------|---------------|--------------|--------------------------------------------------|" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     |            |            |               |              |                                                  |" << endl;
	cout << "     -------------------------------------------------------------------------------------------------------------" << endl;
}

void LeaveStatus_File(char employ_type[], char employ_number[])		//Function to open Leave Status file
{
	int  row = 11;
	char FType[3], FNum[5], comma[143], EmpName[41], To_Date[11];
	char From_Date[11], Status_Date[11], Leave_Type[3], Approval_Status[3], Leave_Reason1[51], Leave_Reason2[51];

	FILE *fptr;												//Finding name of searched Employee
	fptr = fopen("F:\\junmingelms\\EmployeeProfile.txt", "r+");	//Open file named "EmployeeProfile"

	if (fptr == NULL)														//Check whether file successfully opened or not
	{
		printf("File does not exist!");
		_getch();
	}

	while (!feof(fptr))														//Reading Employee Type and Number throughout the entire file
	{
		fgets(comma, 36, fptr);
		fgets(FType, 3, fptr);
		fgets(comma, 2, fptr);
		fgets(FNum, 5, fptr);
		fgets(comma, 71, fptr);

		if (strcmp(FType, employ_type) == 0 && strcmp(FNum, employ_number) == 0)	//Comparing captured input with data in file
		{
			fseek(fptr, -70, SEEK_CUR);
			fgets(EmpName, 41, fptr);
			printf(EmpName);										//Printing out Employee name based on Employee Type and Number
			break;
		}
	}
	fclose(fptr);

	FILE *fptr2;												//Finding name of searched Employee
															//Finding leave status for searched Employee
	fptr2 = fopen("F:\\junmingelms\\LeaveApplication.txt", "r");	//Open file named "

	if (fptr2 == NULL)
	{
		printf("File does not exist!");
		_getch();
	}

	while (!feof(fptr2))
	{
		fgets(FType, 3, fptr2);
		fgets(comma, 2, fptr2);
		fgets(FNum, 5, fptr2);
		fgets(comma, 2, fptr2);
		fgets(From_Date, 11, fptr2);								//Read "From date"
		fgets(comma, 2, fptr2);
		fgets(To_Date, 11, fptr2);									//Read "To date"
		fgets(comma, 5, fptr2);
		fgets(Leave_Type, 3, fptr2);								//Read "Leave Type"
		fgets(comma, 2, fptr2);
		fgets(Leave_Reason1, 51, fptr2);							//Read "Leave Reason"
		fgets(comma, 2, fptr2);
		fgets(Leave_Reason2, 51, fptr2);							//Read "Leave Reason"
		fgets(comma, 2, fptr2);
		fgets(Approval_Status, 2, fptr2);							//Read "Approval Status"
		fgets(comma, 3, fptr2);
 
		if (strcmp(FType, employ_type) == 0 && strcmp(FNum, employ_number) == 0)	//Comparing captured input with data in file
		{
			SetCursorPosition(row, 7);
			printf(To_Date);										//Display "To date"
			SetCursorPosition(row, 20);
			printf(From_Date);										//Display "From date"
			SetCursorPosition(row, 34);
			printf(From_Date);										//Display "Status date"
			SetCursorPosition(row, 54);
			printf(Approval_Status);								//Display "Approval Status"

			SetCursorPosition(row, 63);
			printf(Leave_Reason1);

			SetCursorPosition(row + 1, 63);
			printf(Leave_Reason2);

			row = row + 2;
		}
 	}
	fclose(fptr);
}

