#include "libFiles.h"
#include "libErrors.h"

void CreateFile(std::ofstream& createFile, std::string passedName)
{
	//name of a file that is being created
	char fileName[30];

	if (passedName.length() != 0)
		strcpy_s(fileName, passedName.c_str());
	else {
		std::cin >> fileName;
		CheckFileName(fileName);
	}
	createFile.open(fileName);

	if (!createFile.is_open()) {
		throw EXCEPTION_CODE::fileCreateError;
	}

}

void OpenFile(std::ifstream& openFile, std::string passedName)
{
	//name of a file that is being opened
	char fileName[30];
	if (passedName.length() != 0)
		strcpy_s(fileName, passedName.c_str());
	else {
		std::cin >> fileName;
		CheckFileName(fileName);
	}
	openFile.open(fileName);

	if (!openFile.is_open()) {
		throw EXCEPTION_CODE::fileOpenError;
	}
}

void CheckFileName(char fileName[30])
{
	for (int i = 0; i <30; i++) {
		if (fileName[i] == '.')
		{
			if (fileName[i + 4] != NULL)
				for (int j = i + 4; j < 30; j++)
					fileName[j] = NULL;
			if (fileName[i + 1] == 't' and fileName[i + 2] == 'x' and fileName[i + 3] == 't') {
				return;
			}
			else if (fileName[i + 1] != 't' or fileName[i + 2] != 'x' or fileName[i + 3] != 't') {
				fileName[i + 1] = 't';
				fileName[i + 2] = 'x';
				fileName[i + 3] = 't';
				fileName[i + 4] = NULL;
				std::cout << "corrected file name: " << fileName << std::endl; 
				return;
			}
		}
		else if (fileName[i] == NULL) {
			fileName[i] = '.';
			fileName[i + 1] = 't';
			fileName[i + 2] = 'x';
			fileName[i + 3] = 't';
			fileName[i + 4] = NULL;
			std::cout << "corrected file name: " << fileName << std::endl;
			return;
		}
	}
}


