#ifndef LIBFILES_H
#define LIBFILES_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

/*
Function creates new file
@param createFile stream used to create a new file
@param passedName passed name of file to be created
*/
void CreateFile(std::ofstream& createFile, std::string passedName="");

/*
Function opens a file
@param openFile stream used to open a file
*/
void OpenFile(std::ifstream& openFile, std::string passedName = "");

/*
Function checks if given file name has correct extension and if not corrects it
@param fileName[30] variable containing file name
*/
void CheckFileName(char fileName[30]);

/*
Write values from array to file
@param arr - write values from this array
@param size - size of an array
@param writeToFile - write to this file
*/
template <class T> void WriteArrayToFile(T* arr, int size, std::ofstream& writeToFile)
{
	for (int i = 0; i < size; i++)
		writeToFile << arr[i] << "\n";
}

#endif
