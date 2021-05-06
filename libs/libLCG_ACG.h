#ifndef LIBLCG_H
#define LIBLCG_H
#include <vector>
#include <iostream>
#include <fstream>
#include "libArrays.h"
#include "libFiles.h"

/*
Find greates common divisor
@param a - first number
@param b - second number
@return greates common divisor
*/
int GCD(int a, int b);

/*
Set parameter c for LCG generator
@param m - modulus / greatest number 
@return parameter c 
*/
int SetIncrement(int m);

/*
Divides given number to prime factors
@param a - number to find its primes
@return vector with all prime factors
*/
std::vector<int> FindPrimeFactors(int a);

/*
Set parameter a of LCG generator
@param m - modulus / greatest number 
@return parameter a
*/
int SetMultiplier(int m);

/*
Chcecks if first value is divisable by all values in vector
@param a - check if it is divisable
@param mPrimeFacotrs - vector containing divisors
@return true if a divisable by all values in vector
*/
bool CheckDivisibility(int a, std::vector<int> mPrimeFactors);

/*
LCG algorithm
@param n - how many numbers to generate
@param m - modulus / greates number
@param x0 - seed
@return pointer to array with generated random values
*/
int* LCG(int n, int m=0, int x0=0);

/*
Set best j,k pairs for ACG generator
@param j - first number in pair
@param k - second value in pair
@param n - how many numbers to generate / size of an array
@param readFrom file - search for pairs in this file
*/
void SetBestPair(int &j, int &k, int n, std::ifstream& readFromFile);

/*
ACG algorithm
@param n - how many numbers to generate
@return pointer to array with generated random values
*/
int* ACG(int n);

#endif // !_LIBLCG_H_
