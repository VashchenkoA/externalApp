#include <iostream>
#include "bootLoader.h"

using namespace std;

int main()
{
	WCHAR fileName;

	// Simple dialog with user
	while (1)
	{
		cout << "Please enter disk name. (One letter: A, B, C)" << endl;
		fileName = getchar();
		if (wcslen(&fileName) == 1)
		{
			break;
		}
	}

	WCHAR buffer[11];
	wcscat_s(buffer, L"\\\\.\\");
	wcscat_s(buffer, &fileName);

	//Converting to string with right format
	const WCHAR fileNameFormated = wcscat_s(buffer,L":");
	
	wprintf(&fileNameFormated);

	//Struct call
	BOOT_NTFS pBootRecord;

	//Function call
	if (bootInfo(&fileNameFormated, &pBootRecord))
	{
		PrintBootSectInfo(pBootRecord);
	}
	
	system("pause");
	return 0;
}
