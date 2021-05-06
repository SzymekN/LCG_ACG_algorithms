#ifndef LIBTABLES_H
#define LIBTABLES_H
#include <iomanip>
#include <iostream>
#include "libErrors.h"

/*
Show contents of array
@param arr - show contents of this array
@param size - size of this array
*/
template <class T> void ShowArray(T* arr, int size) {
	for (int i = 0; i < size; i++)
		std::cout << std::setw(2) << arr[i] << std::setw(2) << " ";
	std::cout << std::endl;
}

/*
Function creates dynamic array of wanted type
@param size size
@return array of wanted type
*/
template <class T> T* CreateArray(int size){
	T* arr = nullptr;
	try {
		arr = new T[size];
	}
	catch (std::bad_alloc) {
		throw EXCEPTION_CODE::allocationError;
	}

	return arr;
}
/*
Function deletes array
@param arr array that will be deleted
*/
template <class T> void DeleteArray(T* arr) {
	try {
		delete[]arr;
	}
	catch (std::bad_alloc) {
		throw EXCEPTION_CODE::allocationError;
	}
};


/*
Copy array values
@param arr1 - copy to this array
@param arr2 - copy from this array
@param size - size of arrays
*/
template <class T> void CopyArray(T* arr1, T* arr2, int size) {
	for (int i = 0; i < size; i++) {
		arr1[i] = arr2[i];
	}
}

/*
Reverse values in array 
@param arr - flip this array
@param size - size of an array
*/
template <class T> void FlipArray(T* arr, int size) {
	T* temp = CreateArray<T>(size);
	CopyArray(temp, arr, size);
	for (int i = 0; i < size; i++) {
		arr[i] = temp[size - i - 1];
	}
}

#endif // !LIBTABLES_H
