#include <iostream>
#include "bootLoader.h"

using namespace std;

int main()
{
	string fileName;

	// Simple dialog with user
	while (1)
	{
		cout << "Please enter disk name. (One letter: A, B, C)" << endl;
		fileName = cin.get();
		if (fileName.length() == 1)
		{
			break;
		}
	}
	//Converting to string with right format
	string fileNameFormated = "\\\\.\\" + fileName + ":";

	//Struct call
	BOOT_NTFS pBootRecord;

	//Function call
	if (bootInfo(fileNameFormated, &pBootRecord))
	{
		PrintBootSectInfo(pBootRecord);
	}

}
