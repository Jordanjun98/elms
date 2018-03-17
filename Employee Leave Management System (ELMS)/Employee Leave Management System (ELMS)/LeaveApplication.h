#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "header.h"	

char EmpLeaveType[2];
char EmpLeaveDateFrom[11];
char EmpLeaveDateTo[11];
char EmpReasonLine1[51];
char EmpReasonLine2[51];
char DDFrom[3];
char MMFrom[3];
char YYYYFrom[5];
char DDTo[3];
char MMTo[3];
char YYYYTo[5];
char EmpLeaveDays[3];
int  Days;
char RecordStatus[2];

int MonthsDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char EmpUserID[11];
char EmpLeaveBal[3];


void DoLeaveApplication();
int ManageLeaveApplication(char Option);
int UserInputValidationLeaveApplication(char &Option);
void SetCursorPosition(int  row, int  col);
void DoApplyLeave();
void RefreshAllValues2();
int CheckValidDate(int ValidStatus, char Day[3], char Month[3], char Year[5]);
int CheckDateFromToValidRange(int ValidStatus);
void CalTotalDaysApplied();
void SubmitLeaveApplication();
void UpdateEmpLeaveBalance();
void RefreshScreen();
void ClearErrorMessage();
void DisplayLeaveApplicationScreen();
void GetNDisplayLeaveBalance();
void InputEntry3(int row, int col, int maxdigit, char type, int validationtype);

// Function to Do Leave Application
void DoLeaveApplication()
{
	char Option = ' ';
	DisplayLeaveApplicationScreen();

	while (Option != 'C')
	{
		Option = ManageLeaveApplication(Option);
	}

}

// Function to Management Leave Application
int ManageLeaveApplication(char Option)
{
	SetCursorPosition(23, 20);
	Option = _getch();											//To capture an option
	Option = UserInputValidationLeaveApplication(Option);		//To validate the option
	ClearErrorMessage();

	if (Option == 65 || Option == 97)							// Apply Leave "A"
	{
		DoApplyLeave();
	}
	else if ((Option == 83 || Option == 115) && strcmp(RecordStatus, "A") == 0) 	// Apply Leave "A" and Option = "S"
	{
		SubmitLeaveApplication();
	}
	else if (Option == 82 || Option == 114)  	// Refresh Screen Option = "R"
	{
		RefreshScreen();
	}
	else if (Option == 67 || Option == 99)  	// Refresh Screen Option = "C"
	{
		return 'C';
	}

	return 0;
}

// Function to Check Input Validation Option 
int UserInputValidationLeaveApplication(char &Option)					//Validation message 
{
	ClearErrorMessage();
	while (Option != 65 && Option != 97 && Option != 83 && Option != 115 && Option != 82 && Option != 114 &&
		Option != 67 && Option != 99)  // Input Validation
	{
		SetCursorPosition(26, 18);
		printf("Invalid input pls type again\n");
		SetCursorPosition(23, 20);
		Option = _getch();
	}
	return Option;
}

// Function to Apply Leave Application
void DoApplyLeave()
{
	RefreshAllValues2();					// Refresh Screen and Initial all Values
	InputEntry3(13, 13, 1, 'N', 3);		// Capture Leave Type
	strncpy(EmpLeaveType, Input, 2);

	bool ValidDate = true;
	while (ValidDate)
	{
		InputEntry3(15, 13, 2, 'N', 0);		// Capture Leave Day
		strncpy(DDFrom, Input, 2);

		InputEntry3(15, 16, 2, 'N', 0);		// Capture Leave Month
		strncpy(MMFrom, Input, 2);

		InputEntry3(15, 19, 4, 'N', 0);		// Capture Leave Year
		strncpy(YYYYFrom, Input, 4);

		if (CheckValidDate(0, DDFrom, MMFrom, YYYYFrom) == 1)
			continue;
		else
		{
			InputEntry3(15, 29, 2, 'N', 0);		// Capture Leave Day
			strncpy(DDTo, Input, 2);

			InputEntry3(15, 32, 2, 'N', 0);		// Capture Leave Month
			strncpy(MMTo, Input, 2);

			InputEntry3(15, 35, 4, 'N', 0);		// Capture Leave Year
			strncpy(YYYYTo, Input, 4);

			if (CheckValidDate(0, DDTo, MMTo, YYYYTo) == 1)
				continue;
			else if (CheckDateFromToValidRange(0) == 1)
				continue;
			else
			{
				CalTotalDaysApplied();				// Function to calculate Total Day Applied

				if ((atoi(EmpLeaveBal) - (Days + 1)) < 0)
				{
					SetCursorPosition(26, 05);
					printf("ERROR!! Leave Balance Cannot Be Less Than Zero!");
				}
				else ValidDate = false;
			}
		}
	}
	InputEntry3(17, 13, 50, 'C', 0);		// Capture Leave Type
	strncpy(EmpReasonLine1, Input, 50);
	InputEntry3(18, 13, 50, 'C', 0);		// Capture Leave Type
	strncpy(EmpReasonLine2, Input, 50);
	strncpy(RecordStatus, "A", 2);		// To indicate Record is in ADD Mode Successfully
}

// Function to Refresh ALL Values of Employee Record
void RefreshAllValues2()
{
	memset(Input, NULL, 50);
	memset(EmpLeaveType, NULL, 1);
	memset(EmpLeaveDateFrom, NULL, 10);
	memset(EmpLeaveDateTo, NULL, 10);
	memset(EmpReasonLine1, NULL, 50);
	memset(EmpReasonLine2, NULL, 50);
}

// Check for Valid Date Entry
int CheckValidDate(int ValidStatus, char Day[3], char Month[3], char Year[5])
{
	SetCursorPosition(26, 05);
	printf("                                                                                       ");
	SetCursorPosition(26, 05);

	if (atoi(Day) > 31)															//  Check for DAY > 31
	{
		printf("Invalid Day Entered!! Day cannot be more than 31 days!!");
		return 1;
	}
	else if (atoi(Month) > 12)														//  Check for MONTH > 12
	{
		printf("Invalid Month Entered!! Month cannot be more than 12 Months!!");
		return 1;
	}
	else if (atoi(Year) < 2017 || atoi(Year) > 2018)						//  Check for YEAR < 2017 OR > 2018
	{
		printf("Invalid Year Entered!! Year cannot be Less than 2017 and More Than 2018 !!");
		return 1;
	}
	else if (atoi(Day) > (MonthsDays[atoi(Month)]) && (atoi(Month) != 2))		// Check for DAYS & MONTH is according to days i.e. 30 or 31 DAYS
	{
		printf("Invalid Day Entered!! Date cannot be more than 30 days !!");
		return 1;
	}
	else if (atoi(Month) == 2 && atoi(Day) >= 28 && (atoi(Year) % 4) != 0)   // Check for Leap Years DAYS
	{
		printf("Invalid Day Entered!! Date cannot be more than 29 days !!");
		return 1;
	}
	else return 0;
}

// Function To Check Valida Date Ranges Checking
int CheckDateFromToValidRange(int ValidStatus)
{
	if (atoi(YYYYFrom)> atoi(YYYYTo))
	{
		printf("ERROR!! TO Year cannot be more than FROM YEAR");
		return 1;
	}
	else if (atoi(MMFrom) > atoi(MMTo))
	{
		printf("ERROR!! TO MONTH cannot be more than FROM MONTH");
		return 1;
	}
	else if (atoi(DDFrom) > atoi(DDTo) && atoi(MMFrom) >= atoi(MMTo))
	{
		printf("ERROR!! TO DAY cannot be more than FROM DAY");
		return 1;
	}
	else return 0;
}

// Function to Calculate Total Days Leave Applied
void CalTotalDaysApplied()
{
	if (atoi(MMFrom) == atoi(MMTo))
	{
		Days = atoi(DDTo) - atoi(DDFrom);
		_itoa((Days + 1), EmpLeaveDays, 10);
		SetCursorPosition(15, 63);
		printf("%02s", EmpLeaveDays);
	}
}

// Function to Submit Leave Application Update
void SubmitLeaveApplication()
{
	FILE *fptr;
	fptr = fopen("F:\\junmingelms\\LeaveApplication.txt", "a");

	if (fptr == NULL)
	{
		printf("File does not exist!");
		_getch();
	}

	fputs(EmpType, fptr);
	fputs(",", fptr);
	fputs(EmpNumber, fptr);
	fputs(",", fptr);
	fputs(DDFrom, fptr);
	fputs("/", fptr);
	fputs(MMFrom, fptr);
	fputs("/", fptr);
	fputs(YYYYFrom, fptr);
	fputs(",", fptr);
	fputs(DDTo, fptr);
	fputs("/", fptr);
	fputs(MMTo, fptr);
	fputs("/", fptr);
	fputs(YYYYTo, fptr);
	fputs(",", fptr);
	fprintf(fptr, "%02s", EmpLeaveBal);
	fputs(",", fptr);
	fprintf(fptr, "%02s", EmpLeaveDays);
	fputs(",", fptr);
	fprintf(fptr, "%-50s", EmpReasonLine1);
	fputs(",", fptr);
	fprintf(fptr, "%-50s", EmpReasonLine2);
	fputs(",", fptr);
	fputs("P", fptr);
	fputs(",\n", fptr);

	fclose(fptr);

	
	if (strcmp(EmpLeaveType , "1") == 0)
	{
		UpdateEmpLeaveBalance();
	}

	SetCursorPosition(26, 05);
	printf("LEAVE SUBMITTED SUCCESSFULLY! ");
	system("pause");

	RefreshScreen();
}

// Function to Update Employee Leave Balance
void UpdateEmpLeaveBalance()
{
	FILE *fptr;
	fptr = fopen("F:\\junmingelms\\EmployeeProfile.txt", "r+");

	if (fptr == NULL)
	{
		printf("File does not exist!");
		_getch();
	}

	char FType[3];
	char FNum[5];
	char comma[72];

	while (!feof(fptr))
	{
		fgets(comma, 36, fptr);
		fgets(FType, 3, fptr);
		fgets(comma, 2, fptr);
		fgets(FNum, 5, fptr);
		fgets(comma, 71, fptr);

		if (strcmp(FType, EmpType) == 0 && strcmp(FNum, EmpNumber) == 0)
		{
			fseek(fptr, -5, SEEK_CUR);
			int a = atoi(EmpLeaveBal) - atoi(EmpLeaveDays);
			_itoa(a, EmpLeaveBal, 10);
			fprintf(fptr, "%02s", EmpLeaveBal);		// Update Leave Balance
			break;
		}
	}

	fclose(fptr);
	GetNDisplayLeaveBalance();
}

// Function to Refresh Leave Application Screen
void RefreshScreen()
{
	memset(EmpLeaveType, NULL, 2);
	memset(EmpLeaveDateFrom, NULL, 11);
	memset(EmpLeaveDateTo, NULL, 11);
	memset(EmpReasonLine1, NULL, 51);
	memset(EmpReasonLine2, NULL, 51);
	memset(DDFrom, NULL, 3);
	memset(MMFrom, NULL, 3);
	memset(YYYYFrom, NULL, 5);
	memset(DDTo, NULL, 3);
	memset(MMTo, NULL, 3);
	memset(YYYYTo, NULL, 5);
	memset(EmpLeaveDays, NULL, 3);
	memset(RecordStatus, NULL, 2);
	memset(Input, NULL, 51);
	memset(EmpLeaveBal, NULL, 3);
	int  Days = 0;
	DisplayLeaveApplicationScreen();
}

