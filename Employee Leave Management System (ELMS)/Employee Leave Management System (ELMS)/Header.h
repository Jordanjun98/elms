#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <dos.h>
#include "UserLogin.h"
#include "YearlyEmployeeLeaveEntitlement.h"
#include "LeaveApplication.h"
#include "LeaveStatusView.h"
#include "ApproveLeaveApplication.h"
#include "FAQ.h"
#include "ChangePassword.h"
#include "UpLoad Public University Holiday.h"
using namespace std;

void SetCursorPosition(int  row, int  col);
void DisplayHeaderInfo();
void GetNDisplayLeaveBalance();
void DisplayLeaveApplicationScreen();
void ClearErrorMessage();
int UserInputValidation(char &Option);					
int MainOption;
void InputEntry(int row, int col, int maxdigit, char type, int validationtype);

fstream dataFile;

int  EmpNumber2, RecFindStatus;
char Input2[51] = { NULL };
char EmpLastNumber[5], EmpName2[41], EmpICPart1[7], EmpICPart2[3], EmpICPart3[5], EmpNewICNo[13];
char EmpPassword[11], EmpPassword2[11], EmpDateCreated[11] = "", EmpDateUpdated[11] = "", EmpRecStatus[2];
char EmpLeaveEntitle[3];

int ManageEmployeeProfile(char Option);
void SetCursorPosition(int  row, int  col);
int UserInputValidation3(char &Option);	//Validation message 
void ClearErrorMessage();
void PrintErrorMessage(int Msg);
void AddEmployeeRecord();
void InputEntry(int row, int col, int maxdigit, char type, int validationtype);
void DisplayEmployeeNumber();
int FindLastNumber(int LastEmpNum);
void DisplayDepartmentName();
void DisplayUserIDPassword();
void DisplayRecordStatusDateCreated();
void SaveEmployeeRecord();
void StoreEmpLastNumberInChar(int LastEmpNum);
void UpdateLastEmployeeRecordNUmber();
void DisplayMessage(int MsgID);
void EditEmployeeRecord(int Option);
void SaveEditEmployeeRecord();
void DisplayRecordDateCreatedUpdated();
void FindEmployeeRecord();
void RefreshAllValues();
void FindEmployeeRecordInput();
void GetEmployeeRecord();
void DisplayEmployeeRecord();
void RefreshScreenNRecord();
void DeleteEmployeeRecord();
void MarkRecordForDeletion();
void SaveDeleteEmployeeRecord();
void DisplayDateLastUpdate();
void LeaveEntitlement();
void DoEmployeeProfile();
void UpdateLoginFile();

// Set Windows Console Display Screen Size
void WindowsConsoleSetting()
{
	HWND console = GetConsoleWindow(); 
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 1160, 500, TRUE); // 1160 width, 500 height
}

// Function to Point the Cursor to the desired location in the screen displayed
void SetCursorPosition(int  row, int  col)
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Pos = { col , row };
	SetConsoleCursorPosition(output, Pos);
}

// Function to Set Color and Background Color
void SetColorAndBackground(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	HWND console = GetConsoleWindow();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
	return;
}

//Open and read File By Line and Display on Screen
void Disp_ReadFileByLine(char * File)
{
	system("cls");								// Clear Screen


	fstream dataFile;							// file object
	string buffer;								// Used to read line from file

	dataFile.open(File, ios::in);				// Open the file for input.

	while (dataFile)
	{
		getline(dataFile, buffer);				// Read a line into a buffer and print the line.   
		cout << buffer << endl;
		getline(dataFile, buffer);				// Read a second line and print it.                 
		cout << buffer << endl;
	}
	dataFile.close();							// Close the file.                 
}

// Login Validation
void Login_Validation()
{
	system("cls");
	int counter;
	for (counter = 0; counter < 3; counter++)
	{
		UserIDs();
		if (*ValidUser == 'Y')
			break;
	}

}

void Display_MainMenu() 
{
	system("cls");

	SetCursorPosition(4, 0);
	printf("		*==============================================*\n");
	printf("		| EMPLOYEE LEAVE MANAGEMENT SYSTEM (ELMS)      |\n");
	printf("		*==============================================*\n");
	printf("		|                                              |\n");
	printf("		|0. Change User Password                       |\n");
	printf("		|                                              |\n");
	printf("		|1. Maintain Employee information              |\n");
	printf("		|                                              |\n");
	printf("		|2. Maintain Yearly Employee Leave Entitlement |\n");
	printf("		|                                              |\n");
	printf("		|3. Upload Public/Univerity holiday            |\n");
	printf("		|                                              |\n");
	printf("		|4. Upload FAQ , Introduction                  |\n");
	printf("		|                                              |\n");
	printf("		|5. Leave Application                          |\n");
	printf("		|                                              |\n");
	printf("		|6. Approve Leave Application                  |\n");
	printf("		|                                              |\n");
	printf("		|7. Check Leave Status                         |\n");
	printf("		|                                              |\n");
	printf("		|8. FAQ                                        |\n");
	printf("		|                                              |\n");
	printf("		|9. Exit                                       |\n");
	printf("		|                                              |\n");
	printf("		|SELECT OPTION <0 to 9> [ ]                    |\n");
	printf("		*==============================================*\n");

	char Option;
	SetCursorPosition(28, 41);
	Option = _getch();							//To capture an option
	Option =  UserInputValidation(Option);		//To validate the option

	switch (Option)
	{
	case 48:				// 0
		system("cls");
		ChangePassword();
		break;
	case 49:				// 1
		DoEmployeeProfile();
		break;	
	case 50:				// 2
		OptionYearlyEmployeeLeaveEntitlementMenu();
		break;
	case 51:				// 3
		UpLoad_Public_University_Holiday();
		break;
	case 52:				// 4
		FAQ();
		break;
	case 53:				// 5
		DoLeaveApplication();
		break;
	case 54:				// 6
		system("cls");
		Leave_Approving_Menu();
		LeaveStatus_File();
		break;
	case 55:				// 7
		LeaveStatusView();
		break;
	case 56:				// 8
 		DisplayFAQ();
		break;
	case 57:				// 9
		MainOption = '9';
		break;
	default:
		break;
	}
}

int UserInputValidation(char &Option)	//Validation message 
{
	while (Option < 48 || Option > 57)
	{
		SetCursorPosition(32, 18);
		printf("Invalid input pls type again\n");
		SetCursorPosition(28, 41);
		Option = _getch();
	}
	return Option;
}


//----------------------------------------------
//For Leave Application

// Function to Display Leave Application Screen
void DisplayLeaveApplicationScreen()
{
	system("cls");					// Clear Screen

	printf("*********************************************************************************************\n");
	printf("| LEAVE APPLICATION                                                                         |\n");
	printf("*********************************************************************************************\n");
	printf("| Employee[      ]                                                                          |\n");
	printf("| Name    [                                        ]                                        |\n");
	printf("| User ID [           ]           Leave Balance [  ]                                        |\n");
	printf("|                                                                                           |\n");
	printf("*********************************************************************************************\n");
	printf("| LEAVE APPLICATION DETAILS                                                                 |\n");
	printf("*********************************************************************************************\n");
	printf("| Choose Leave Type                                                                         |\n");
	printf("| 1 - Annual , 2 - Compassionate, 3 - Marriage 4 - No Pay, 5 - Medical, 6 - Hospitalization |\n");
	printf("|                                                                                           |\n");
	printf("| LEAVE TYPE[ ]                                                                             |\n");
	printf("|                                                                                           |\n");
	printf("| DATE FROM [  /  /    ] TO [  /  /    ]       Leave Duration [  ]                          |\n");
	printf("|                                                                                           |\n");
	printf("|    REASON [                                                  ]                            |\n");
	printf("|           [                                                  ]                            |\n");
	printf("|                                                                                           |\n");
	printf("*********************************************************************************************\n");
	printf("|    <A>pply Leave   <S>ubmit Leave For Approval   <R>efresh Screen   <C>lose & Return      |\n");
	printf("|                                                                                           |\n");
	printf("|    SELECT OPTION [ ]                                                                      |\n");
	printf("*********************************************************************************************\n");
	printf("|                                                                                           |\n");
	printf("|                                                                                           |\n");
	printf("|                                                                                           |\n");
	printf("*********************************************************************************************\n");
	DisplayHeaderInfo();
}

// Function To Clear Message Line
void ClearErrorMessage()
{
	SetCursorPosition(30, 3);
	printf("                                                                               ");
}


void DisplayHeaderInfo()
{
	SetCursorPosition(3, 11);
	printf(EmpType);
	printf(EmpNumber);
	SetCursorPosition(4, 11);
	printf(EmpName);
	SetCursorPosition(5, 11);
	printf(UserID);
	GetNDisplayLeaveBalance();
}

// Function to Accept X Character or Number AND Validate Them Ensuring Correct Values Are Captured
void InputEntry3(int row, int col, int maxdigit, char type, int validationtype)
{
	SetCursorPosition(row, col);
	char  ch;
	int i = 0;

	memset(Input, NULL, 50);

	while (1)
	{
		ch = toupper(_getch());								// Get ONE char/digit input from the User
		if (ch == 13)										// Carriage Return (Enter) - 13 - To EXIT from the WHILE
		{
			if (validationtype == 0 || validationtype == 3 || validationtype == 4)
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
		if (type == 'N' && ((ch < 48 || ch > 57) || (validationtype == 3 && (ch < 49 || ch > 54))))
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

void GetNDisplayLeaveBalance()
{
	SetCursorPosition(5, 49);

	FILE *fptr;
	fptr = fopen("F:\\junmingelms\\EmployeeProfile.txt", "r");

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
		fgets(comma, 2, fptr);
		fgets(EmpName, 41, fptr);
		fgets(comma, 30, fptr);

		if (strcmp(FType, EmpType) == 0 && strcmp(FNum, EmpNumber) == 0)
		{
			fseek(fptr, -5, SEEK_CUR);
			fgets(EmpLeaveBal, 3, fptr);
			printf("%2s", EmpLeaveBal);
			break;
		}
	}

	fclose(fptr);
}

//==================================================
// Maintain Employee
//

// Function to Display Employee Profile Screen
void DisplayEmployeeProfileScreen()
{
	system("cls");					// Clear Screen

	printf("*****************************************************************\n");
	printf("| Employee Profile                                              |\n");
	printf("*****************************************************************\n");
	printf("|                                                               |\n");
	printf("|    Employee Type   [  ]                                       |\n");
	printf("|                                                               |\n");
	printf("|    Employee Number [    ]                                     |\n");
	printf("|                                                               |\n");
	printf("| 3. Employee Name   [                                        ] |\n");
	printf("|                                                               |\n");
	printf("| 4. New IC Number   [      -  -    ]                           |\n");
	printf("|                                                               |\n");
	printf("|    Department      [                   ]                      |\n");
	printf("|                                                               |\n");
	printf("|    User ID         [          ]                               |\n");
	printf("|                                                               |\n");
	printf("|    Password        [          ] Leave Balance [  ]            |\n");
	printf("|                                                               |\n");
	printf("|    Date Created    [  /  /    ] Date Last Update [  /  /    ] |\n");
	printf("|                                                               |\n");
	printf("|    Record Status   [         ]                                |\n");
	printf("|                                                               |\n");
	printf("*****************************************************************\n");
	printf("|  <F>ind Record          <A>dd New Record      <D>elete Record |\n");
	printf("|                                                               |\n");
	printf("|  <3>or<4> Edit Record   <R>efresh Screen      <S>ave Record   |\n");
	printf("|                                                               |\n");
	printf("|  <C>lose & Return       SELECT OPTION[ ]                      |\n");
	printf("*****************************************************************\n");
	printf("|                                                               |\n");
	printf("|                                                               |\n");
	printf("*****************************************************************\n");
}

// Function to Control Do Employee Profile WHILE NOT = "C"
void DoEmployeeProfile()
{
	char TempType[3];
	int x = 0;
	while (x < 2) {
		TempType[x] = UserID[x];
		x++;
	}
	TempType[x] = '\0';

	if (strcmp(TempType, "HR") != 0)
	{
		PrintErrorMessage(7);
		system("pause");
	}
	else
	{
		char Option = ' ';
		DisplayEmployeeProfileScreen();

		while (Option != 'C')
		{
			Option = ManageEmployeeProfile(Option);
		}
	}
}

// Function to Manage Employee Profile For Input Action
int ManageEmployeeProfile(char Option)
{
	SetCursorPosition(27, 40);
	Option = _getch();									//To capture an option
	Option = UserInputValidation3(Option);				//To validate the option
	ClearErrorMessage();

	if (Option == 70 || Option == 102)					// Finding Existing Record "FI"
	{
		strncpy(RecordStatus, "  ", 2);
		if (strcmp(RecordStatus, "  ") == 0)
		{
			FindEmployeeRecord();
			strncpy(RecordStatus, "FI", 2);
		}
	}
	else if (Option == 65 || Option == 97)				//  Adding NEW Record "AD"
	{
		if (strcmp(RecordStatus, "") == 0)
		{
			AddEmployeeRecord();
			strncpy(RecordStatus, "AD", 2);
		}
		else
		{
			PrintErrorMessage(2);
		}
	}
	else if (Option == 51 || Option == 52)				// Edit Existing Record once added or Find record already
	{
		// Edit Record but it is NEW and not saved  "AD"
		if ((strncmp(RecordStatus, "AD", 2) == 0) || (strncmp(RecordStatus, "ED", 2) == 0) || (strncmp(RecordStatus, "FI", 2) == 0))
		{
			EditEmployeeRecord(Option);
		}
		else
		{
			PrintErrorMessage(3);
		}
	}
	else if (Option == 68 || Option == 100)				// Record Deletion
	{
		if (strncmp(RecordStatus, "FI", 2) == 0)
		{
			DeleteEmployeeRecord();
			strncpy(RecordStatus, "DE", 2);
		}
		else
		{
			PrintErrorMessage(4);
		}
	}
	else if (Option == 82 || Option == 114)				// Refresh Screen
	{
		RefreshScreenNRecord();
	}
	else if (Option == 83 || Option == 115)				// Save Record
	{
		if (strncmp(RecordStatus, "AD", 2) == 0)		// Save Record for NEW Record
		{
			SaveEmployeeRecord();
			strncpy(RecordStatus, "SA", 2);
			DisplayMessage(1);
		}
		else if (strncmp(RecordStatus, "FI", 2) == 0)	// Save Record for FIND Record
		{
			SaveEditEmployeeRecord();
			strncpy(RecordStatus, "FI", 2);
			DisplayMessage(1);
		}
		else if (strncmp(RecordStatus, "DE", 2) == 0)	// Save Record for DELETE Record
		{
			SaveDeleteEmployeeRecord();
			strncpy(RecordStatus, "DE", 2);
			DisplayMessage(1);
		}
		else
		{
			PrintErrorMessage(5);
		}
	}
	else if (Option == 67 || Option == 99)				// Close and Return
	{
		return 'C';
	}
	return ' ';
}

// Function to Check Input Validation Option 
int UserInputValidation3(char &Option)					//Validation message 
{
	ClearErrorMessage();
	while (Option != 70 && Option != 102 && Option != 65 && Option != 97 && Option != 51 && Option != 52 &&
		Option != 82 && Option != 114 && Option != 83 && Option != 115 && Option != 67 && Option != 99 &&
		Option != 68 && Option != 100)  // Input Validation
	{
		SetCursorPosition(30, 18);
		printf("Invalid input pls type again\n");
		SetCursorPosition(27, 40);
		Option = _getch();
	}
	return Option;
}

// Function to Print Error Message for Input Option
void PrintErrorMessage(int Msg)
{
	SetCursorPosition(30, 3);
	switch (Msg)
	{
	case 1:
		printf("Press Refresh Screen And Click Find Record");
		break;
	case 2:
		printf("Press Refresh Screen And Click Add Record");
		break;
	case 3:
		printf("Find Or Add Record First Before Press Edit Record");
		break;
	case 4:
		printf("Find Record First Before Press Delete Record");
		break;
	case 5:
		printf("Find Record First Before Press Save Record");
		break;
	case 6:
		printf("SEARCH RECORD NOT FOUND!!. TRY AGAIN!!");
		break;
	case 7:
		printf("ERROR. Only HR Personnel can access Employee Profile Maintenance!");
		break;
	}
}

// Function Routine to ADD Employee Record
void AddEmployeeRecord()
{
	RefreshAllValues();					// Refresh Screen and Initial all Values

	DisplayRecordStatusDateCreated();	// Display Record Status & Date Created
	InputEntry(4, 22, 2, 'C', 1);		// Capture Employee Type
	strncpy(EmpType, Input, 2);
	DisplayEmployeeNumber();			// Find & Display Employee Number
	DisplayDepartmentName();

	InputEntry(8, 22, 40, 'C', 0);		// Capture Employee Name
	strncpy(EmpName, Input, 40);
	strcat(EmpName, "                                         ");	// Store Spaces To The Blanks After The Name
	strncpy(EmpName2, EmpName, 40);


	InputEntry(10, 22, 6, 'N', 0);		// Capture Employee New IC yymmdd
	strncpy(EmpICPart1, Input, 6);
	strcat(EmpNewICNo, EmpICPart1);
	InputEntry(10, 29, 2, 'N', 0);		// Capture Employee New IC -99-
	strncpy(EmpICPart2, Input, 2);
	strcat(EmpNewICNo, EmpICPart2);
	InputEntry(10, 32, 4, 'N', 0);		// Capture Employee New IC 9999
	strncpy(EmpICPart3, Input, 4);
	strcat(EmpNewICNo, EmpICPart3);

	DisplayUserIDPassword();			// Display Default User ID Anad Password

	LeaveEntitlement();					// Get Leave Entitlement & Display
}

// Display Employee Number
void DisplayEmployeeNumber()
{
	int LastEmpNum = 0;

	SetCursorPosition(6, 22);
	printf("%04d", FindLastNumber(LastEmpNum));
}

// Display Department Name
void DisplayDepartmentName()
{
	SetCursorPosition(12, 22);
	if (strcmp(EmpType, "AD") == 0)
		printf("System Administrator");
	else if (strcmp(EmpType, "HR") == 0)
		printf("Human Resource");
	else if (strcmp(EmpType, "AL") == 0)
		printf("Academic Leader");
	else printf("Lecturer");
}

// Display User ID
void DisplayUserIDPassword()
{
	// Merge User ID and Display
	SetCursorPosition(14, 22);
	memset(EmpUserID, NULL, 10);
	strncpy(EmpUserID, EmpType, 2);
	strncat(EmpUserID, EmpICPart1, 6);
	strncat(EmpUserID, "  ", 2);
	printf("%.10s", EmpUserID);

	// Display Default Password
	SetCursorPosition(16, 22);
	strncpy(EmpPassword, EmpUserID, 10);
	printf("%.10s", EmpPassword);
	int i = 10;
	for (i = 0; i < 10; i++)
	{
		EmpPassword2[i] = EmpPassword[i];
	}
	EmpPassword2[10] = '\0';
}

// Display Record Status and Date Created
void DisplayRecordStatusDateCreated()
{
	SetCursorPosition(20, 22);
	printf("Active");
	strncat(EmpRecStatus, "A", 2);

	DisplayRecordDateCreatedUpdated();
}

// Function to Get and Display Date Created For Employee Profile
void DisplayRecordDateCreatedUpdated()
{
	SetCursorPosition(18, 22);
	int DD, MM, YYYY;
	char buffer[10];

	SYSTEMTIME str_t;
	GetSystemTime(&str_t);

	DD = str_t.wDay;
	MM = str_t.wMonth;
	YYYY = str_t.wYear;

	if (DD < 10)
	{
		strncat(EmpDateCreated, "0", 2);
	}
	strncat(EmpDateCreated, _itoa(DD, buffer, 10), 2);
	strncat(EmpDateCreated, "/", 1);

	if (MM < 10)
	{
		strncat(EmpDateCreated, "0", 2);
	}
	strncat(EmpDateCreated, _itoa(MM, buffer, 10), 2);
	strncat(EmpDateCreated, "/", 1);
	strncat(EmpDateCreated, _itoa(YYYY, buffer, 10), 4);

	printf(EmpDateCreated);

	strncat(EmpDateUpdated, EmpDateCreated, 10);
	SetCursorPosition(18, 52);
	printf(EmpDateUpdated);
}

// Find the Last User Number and add One
int FindLastNumber(int LastEmpNum)
{
	FILE *fptr;
	fptr = fopen("F:\\junmingelms\\LastRecord.txt", "r");

	if (fptr == NULL)
	{
		printf("File does not exist!");
		_getch();
	}

	char FType[3];
	char FNum[5];
	char comma[3] = ",";
	while (!feof(fptr) && strcmp(FType, EmpType) != 0)
	{
		fgets(FType, 3, fptr);
		fgets(comma, 2, fptr);                             
		fgets(FNum, 5, fptr);
		fgets(comma, 3, fptr);
	}

	LastEmpNum = atoi(FNum) + 1;

	StoreEmpLastNumberInChar(LastEmpNum);

	fclose(fptr);

	return LastEmpNum;
}

// Function to Add '000' zeros according to the Employee Last Number For Creation
void StoreEmpLastNumberInChar(int LastEmpNum)
{
	char buffer[10];
	memset(EmpLastNumber, NULL, 4);			// Store Spaces To The Blanks to EmpLastNumber	

	if (LastEmpNum <= 9)
		strncat(EmpLastNumber, "000", 3);
	else if (LastEmpNum <= 99)
		strncat(EmpLastNumber, "00", 2);
	else if (LastEmpNum <= 999)
		strncat(EmpLastNumber, "0", 2);

	strncat(EmpLastNumber, _itoa(LastEmpNum, buffer, 10), 4);
	EmpNumber2 = LastEmpNum;
}

// Function to Save ALL Employee Record (Information) to File EmployeeProfile
void SaveEmployeeRecord()
{
	FILE *fptr;
	fptr = fopen("F:\\junmingelms\\EmployeeProfile.txt", "a");

	if (fptr == NULL)
	{
		printf("File does not exist!");
		_getch();
	}

	fputs(EmpUserID, fptr);
	fputs(",", fptr);
	fputs(EmpPassword2, fptr);
	fputs(",", fptr);
	fputs(EmpRecStatus, fptr);
	fputs(",", fptr);
	fputs(EmpDateUpdated, fptr);
	fputs(",", fptr);
	fputs(EmpType, fptr);
	fputs(",", fptr);
	fputs(EmpLastNumber, fptr);
	fputs(",", fptr);
	fputs(EmpName2, fptr);
	fputs(",", fptr);
	fputs(EmpNewICNo, fptr);
	fputs(",", fptr);
	fputs(EmpDateCreated, fptr);
	fputs(",", fptr);
	fputs(EmpLeaveEntitle, fptr);
	fputs(",\n", fptr);

	fclose(fptr);

	UpdateLoginFile();
	UpdateLastEmployeeRecordNUmber();
	strncpy(RecordStatus, "SA", 2);				//  Set RecordStatus to "SAVED"
}
 
void UpdateLoginFile()
{
	FILE *fptr2;
	fptr2 = fopen("F:\\junmingelms\\Login2.txt", "a");

	if (fptr2 == NULL)
	{
		printf("File does not exist!");
		_getch();
	}

	fputs(EmpUserID, fptr2);
	fputs(",", fptr2);
	fputs(EmpPassword2, fptr2);
	fputs(",\n", fptr2);

	fclose(fptr2);
}



// Function to UPDATE Last Employee Number Counter to File LastRecord
void UpdateLastEmployeeRecordNUmber()
{
	FILE *fptr;
	fptr = fopen("F:\\junmingelms\\LastRecord.txt", "r+");

	if (fptr == NULL)
	{
		printf("File does not exist!");
		_getch();
	}

	char FType[3];
	char FNum[5];
	int LastEmpNum;
	char comma[3];
	while (!feof(fptr) && strcmp(FType, EmpType) != 0)
	{
		fgets(FType, 3, fptr);
		fgets(comma, 2, fptr);
		fgets(FNum, 5, fptr);
		fgets(comma, 3, fptr);
	}

	if (strcmp(FType, EmpType) == 0)
	{
		fseek(fptr, -7, SEEK_CUR);
		LastEmpNum = atoi(FNum) + 1;
		StoreEmpLastNumberInChar(LastEmpNum);
		fprintf(fptr, "%04d", LastEmpNum);
	}

	fclose(fptr);
}

// Function to Display  Message on Status of the Record
void DisplayMessage(int MsgID)
{
	SetCursorPosition(30, 05);
	switch (MsgID)
	{
	case 1:
		printf("Employee %11s Record Saved Successfully!!", EmpUserID);
	}
}

// Function to Edit Record
void EditEmployeeRecord(int Option)
{
	if (((strcmp(RecordStatus, "AD") == 0) || (strcmp(RecordStatus, "FI") == 0)) && Option == 51)
	{
		memset(EmpName, ' ', 40);			// Store Spaces To The Blanks After The Name
		InputEntry(8, 22, 40, 'C', 0);		// Capture Employee Name
		strncpy(EmpName, Input, 40);
		strcat(EmpName, "                                         ");	// Store Spaces To The Blanks After The Name
		strncpy(EmpName2, EmpName, 40);

	}
	else if ((strcmp(RecordStatus, "AD") == 0) && Option == 52)
	{
		memset(EmpNewICNo, NULL, 40);			// Store Spaces To The Blanks After The Name
		InputEntry(10, 22, 6, 'N', 0);		// Capture Employee New IC yymmdd
		if (strcmp(Input, Input2) != 0)
			strncpy(EmpICPart1, Input, 6);
		else strcat(EmpNewICNo, EmpICPart1);

		InputEntry(10, 29, 2, 'N', 0);		// Capture Employee New IC -99-
		if (strcmp(Input, Input2) != 0)
			strncpy(EmpICPart2, Input, 2);
		else strcat(EmpNewICNo, EmpICPart2);

		InputEntry(10, 32, 4, 'N', 0);		// Capture Employee New IC 9999
		if (strcmp(Input, Input2) != 0)
			strncpy(EmpICPart3, Input, 4);
		else strcat(EmpNewICNo, EmpICPart3);

		DisplayUserIDPassword();			// Display Default User ID Anad Password
											//		memset(EmpRecStatus, 'A', 1);		// Set EmpRecStatus to E - EDIT
	}
	else
	{
		SetCursorPosition(30, 05);
		printf("Once Record Saved, New IC-No Cannot be changed!!");
	}
}

// Function To Update Employee Record
void SaveEditEmployeeRecord()
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
//	int LastEmpNum;
	char comma[72];

	while (!feof(fptr))
	{
		fgets(comma, 36, fptr);
		fgets(FType, 3, fptr);
		fgets(comma, 2, fptr);
		fgets(FNum, 5, fptr);
		fgets(comma, 70, fptr);

		if (strcmp(FType, EmpType) == 0 && strcmp(FNum, EmpLastNumber) == 0)
		{
			fseek(fptr, -67, SEEK_CUR);
			fprintf(fptr, "%-40s,", EmpName2);
			break;
		}
	}
	fclose(fptr);
}

// Funtion To Display and Find Employee Record
void FindEmployeeRecord()
{
	DisplayEmployeeProfileScreen();
	RefreshAllValues();
	FindEmployeeRecordInput();
	DisplayEmployeeRecord();
}

// Function to Refresh ALL Values of Employee Record
void RefreshAllValues()
{
	memset(Input, NULL, 40);
	memset(Input2, NULL, 40);
	memset(EmpType, NULL, 3);
	EmpNumber2 = 0;
	memset(EmpLastNumber, NULL, 5);
	memset(EmpName, NULL, 41);
	memset(EmpName2, NULL, 41);
	memset(EmpICPart1, NULL, 7);
	memset(EmpICPart2, NULL, 3);
	memset(EmpICPart3, NULL, 5);
	memset(EmpNewICNo, NULL, 13);
	memset(EmpUserID, NULL, 11);
	memset(EmpPassword, NULL, 11);
	memset(EmpPassword2, NULL, 11);
	memset(EmpDateCreated, NULL, 11);
	memset(EmpDateUpdated, NULL, 11);
	memset(EmpRecStatus, NULL, 2);
	memset(RecordStatus, NULL, 2);
}

// Function To Find Record Input
void FindEmployeeRecordInput()
{
	InputEntry(4, 22, 2, 'C', 1);		// Capture Employee Type
	strncpy(EmpType, Input, 2);
	InputEntry(6, 22, 4, 'N', 0);		// Capture Employee Number
	strncpy(EmpLastNumber, Input, 4);
	GetEmployeeRecord();
}

// Function to Get Employee Record (FIND)
void GetEmployeeRecord()
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
	char comma[2];
	char comma2[3];
	RecFindStatus = 0;

	while (!feof(fptr))
	{
		fgets(EmpUserID, 11, fptr);
		fgets(comma, 2, fptr);
		fgets(EmpPassword, 11, fptr);
		fgets(comma, 2, fptr);
		fgets(EmpRecStatus, 2, fptr);
		fgets(comma, 2, fptr);
		fgets(EmpDateUpdated, 11, fptr);
		fgets(comma, 2, fptr);
		fgets(FType, 3, fptr);
		fgets(comma, 2, fptr);
		fgets(FNum, 5, fptr);
		fgets(comma, 2, fptr);
		fgets(EmpName, 41, fptr);
		fgets(comma, 2, fptr);
		fgets(EmpICPart1, 7, fptr);
		fgets(EmpICPart2, 3, fptr);
		fgets(EmpICPart3, 5, fptr);
		fgets(comma, 2, fptr);
		fgets(EmpDateCreated, 11, fptr);
		fgets(comma, 2, fptr);
		fgets(EmpLeaveEntitle, 3, fptr);
		fgets(comma2, 3, fptr);

		if (strcmp(FType, EmpType) == 0 && strcmp(FNum, EmpLastNumber) == 0)
		{
			RecFindStatus = 1;
			break;
		}
	}
}

// Function to Display Employee Record
void DisplayEmployeeRecord()
{
	if (RecFindStatus == 1)
	{
		SetCursorPosition(8, 22);
		printf(EmpName);
		SetCursorPosition(8, 22);
		SetCursorPosition(10, 22);
		printf(EmpICPart1);
		SetCursorPosition(10, 29);
		printf(EmpICPart2);
		SetCursorPosition(10, 32);
		printf(EmpICPart3);
		DisplayDepartmentName();
		SetCursorPosition(14, 22);
		printf(EmpUserID);
		SetCursorPosition(16, 22);
		printf("**********");
		SetCursorPosition(18, 22);
		printf(EmpDateCreated);
		SetCursorPosition(18, 52);
		printf(EmpDateUpdated);
		SetCursorPosition(20, 22);
		if (strcmp(EmpRecStatus, "A") == 0)
			printf("Active");
		else if (strcmp(EmpRecStatus, "D") == 0)
			printf("Deleted");
		SetCursorPosition(16, 49);
		printf("%2d", atoi(EmpLeaveEntitle));
	}
	else PrintErrorMessage(6);
}

// Function To Fresh Screen
void RefreshScreenNRecord()
{
	DisplayEmployeeProfileScreen();
	RefreshAllValues();
}

//  Function To Delete Employee Record Status
void DeleteEmployeeRecord()
{
	MarkRecordForDeletion();
}

// Function To Delete Employee Record Status - MARK the record DELETED
void MarkRecordForDeletion()
{
	SetCursorPosition(20, 22);
	printf("Deleted");
	SetCursorPosition(20, 33);
	printf("Marked For Deletion. Press SAVE");
	strncpy(EmpRecStatus, "D", 2);
	strncpy(RecordStatus, "DE", 2);
}

// Function to SAVE record
void SaveDeleteEmployeeRecord()
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
		fgets(comma, 68, fptr);

		if (strcmp(FType, EmpType) == 0 && strcmp(FNum, EmpLastNumber) == 0)
		{
			fseek(fptr, -88, SEEK_CUR);
			fprintf(fptr, "%-1s,", EmpRecStatus);
			DisplayDateLastUpdate();
			fprintf(fptr, EmpDateUpdated);

			break;
		}
	}

	fclose(fptr);

	SetCursorPosition(20, 33);
	printf("                               ");
}

// Function to Display Date of Last Update for Employee Record
void DisplayDateLastUpdate()
{
	SetCursorPosition(18, 22);
	int DD, MM, YYYY;
	char buffer[10];

	SYSTEMTIME str_t;
	GetSystemTime(&str_t);

	DD = str_t.wDay;
	MM = str_t.wMonth;
	YYYY = str_t.wYear;

	memset(EmpDateUpdated, NULL, 11);			// Store Spaces To The Blanks After The Name
	strncpy(EmpDateUpdated, _itoa(DD, buffer, 10), 2);
	strncat(EmpDateUpdated, "/", 1);
	strncat(EmpDateUpdated, _itoa(MM, buffer, 10), 2);
	strncat(EmpDateUpdated, "/", 1);
	strncat(EmpDateUpdated, _itoa(YYYY, buffer, 10), 4);

	SetCursorPosition(18, 52);
	printf(EmpDateUpdated);
}

void LeaveEntitlement()
{
	FILE *fptr;
	fptr = fopen("F:\\junmingelms\\YearlyEmployeeLeaveEntitlement.txt", "r");

	if (fptr == NULL)
	{
		printf("File does not exist!");
		_getch();
	}

	char FType[3];
	char FNum[3];
	char comma[2];

	while (!feof(fptr))
	{
		fgets(FType, 3, fptr);
		fgets(comma, 2, fptr);
		fgets(FNum, 3, fptr);
		fgets(comma, 2, fptr);

		if (strcmp(FType, EmpType) == 0)
		{
			strncpy(EmpLeaveEntitle, FNum, 2);
			break;
		}
	}

	fclose(fptr);

	// Display Leave Entitlement
	SetCursorPosition(16, 49);
	printf("%2d", atoi(EmpLeaveEntitle));
}
