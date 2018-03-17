#pragma once
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "header.h"

// char FHRD[3];	// Human Resource 
// char FALD[3];	// Academic Leader
// char FLED[3];	// Lecturer
// char FHR[3];	// Human Resource 
// char FAL[3];	// Academic Leader
// char FLE[3];	// Lecturer
// char comma[2] = ",";
// char RecIndicator[2] = " SetCursorPosition
// int HR = 0, AL = 0, LE = 0;

int UserInputValidation2(char &Option);
void GetYearlyEmployeeLeaveEntitlementRecord();
int YearlyEmployeeLeaveEntitlement(char Option);
void SetCursorPosition(int  row, int  col);
// void EditYearlyEmployeeLeaveEntitlement();
void EditHR();
void InputEntry(int row, int col, int maxdigit, char type);
void UpdateYearlyEmployeeLeaveEntitlement();
void DisplayYearlyEmployeeLeaveEntitlementMenu();
void DoEmployeeProfile();

// DoEmployeeProfile




