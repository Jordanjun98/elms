//=======================================================================================
// EMPLOYEE LEAVE MANAGEMENT SYSTEM (ELMS) 
// ASIA PACIFIC UNIVERSITY COLLEGE OF TECHNOLOGY AND INNOVATION 
// 
// AUTHOR		: LOOK JUN MING
// DATE			: 20 November 2017
//======================================================================================

#include "Header.h"
#include <time.h>

using namespace std;


// Main
int main()
{
	WindowsConsoleSetting();	// Set Windows Console Display Screen Size	
	SetColorAndBackground(14, 0);

	SetCursorPosition(02, 05);
	char * File = "F:\\junmingelms\\Introduction01.txt";
	Disp_ReadFileByLine(File);
	system("pause");

	Login_Validation();

	if (strcmp(ValidUser, "Y") == 0)
	{
		Display_MainMenu();

		while (MainOption != 57)   // Do while Option is NOT 57 (9) Quit System
		{
			Display_MainMenu();
		}
	}
	return 0;
}

