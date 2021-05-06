#include <iostream>
#include "libs/libLCG_ACG.h"

int main()
{
	int choice{};	//choose number generation algorithm
	int n{};	//how many numbers to generate
	int returnCode = 1;	
	int* randomNumbers{};	//array with numbers
	std::ofstream writeToFile;	//write results using this stream

	try {
		std::cout << "1. LCG\n2. ACG\n";
		std::cin >> choice;

		std::cout << "How many numbers: ";
		std::cin >> n;

		if (n <= 0)
			throw EXCEPTION_CODE::valueOutOfBoundaries;

		switch (choice)
		{
		case 1:
			CreateFile(writeToFile, "LCG_out.txt");
			randomNumbers = LCG(n);
			break;
		case 2:
			CreateFile(writeToFile, "ACG_out.txt");
			randomNumbers = ACG(n);
			break;
		default:
			std::cout << "Unknown";
			exit(-1);
			break;
		}

		ShowArray(randomNumbers, n);
		WriteArrayToFile(randomNumbers, n, writeToFile);
		writeToFile.close();
		DeleteArray(randomNumbers);
	}
	catch (EXCEPTION_CODE err) {
		ShowException(err);
		returnCode = -1;
	}

	return returnCode;
}
