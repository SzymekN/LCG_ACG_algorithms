#include "libLCG_ACG.h"

int GCD(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;

	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}

	return a;

}

int SetIncrement(int m)
{
	int c = time(0) % m;
	while (GCD(c, m) != 1 and c < m)
		c++;

	//if no c was found set it to 1
	if (c == m)
		c = 1;
	return c;
}

std::vector<int> FindPrimeFactors(int a)
{
    std::vector<int> v;

	//divide until finding all prime factors
    for (int i = 2; i <= a/2; i++)
    {
		if (i > 2 and i % 2 == 0)
			i++;
        while (a % i == 0)
        {
            v.push_back(i);
            a = a / i;
        }
    }

	//if a!=0 a must be a prime number
    if (a > 1)
        v.push_back(a);

    return v;
}

int SetMultiplier(int m)
{
	int greatestLambda{};
	int bestA = -1;
	std::vector<int> aFactor;
	std::vector<int> mPrimeFactors;
	
	for (int i = 2; i < m; i++) {
		if (GCD(i, m) == 1) {
			int lambda = 1;
			unsigned long long power = (pow(i, lambda));
			//calculate until value didn't overflow unsigned long long size
			while (power > 0) {
				if (power % m == 1) {
					//if new greatest lambda found save it, and search for others equal to it
					if (lambda > greatestLambda) {
						greatestLambda = lambda;
						aFactor.resize(0);
						aFactor.push_back(i);
					}
					//if new lambda equal to greates found yet add it to vector
					else if (lambda == greatestLambda) {
						aFactor.push_back(i);
					}
					break;
				}
				lambda++;
				power = (pow(i, lambda));
			}
		}
	}

	mPrimeFactors = FindPrimeFactors(m);
	for (int a : aFactor) {
		//check if a is divisable by all prime factors of m
		if (CheckDivisibility(a, mPrimeFactors)){
			//if m is divisable by 4 than a-1 also must be
			if (m % 4 == 0) {
				if ((a - 1) % 4 == 0) {
					bestA = a;
				}
			}
			else
			bestA = a;
		}
	}

	//if no a passes above conditions best 'a' is the greates 'a'
	if (bestA == -1)
		bestA = aFactor.back();
	return bestA;
}

bool CheckDivisibility(int a, std::vector<int> mPrimeFactors)
{
	a--;
	bool divisable = true;
	for (int factor : mPrimeFactors) {
		//if this factor doesn't divide a set return value to false and break
		if (a % factor != 0) {
			divisable = false;
			break;
		}
	}
	return divisable;
}

int* LCG(int n, int m, int x0)
{
	//if m wasn't passed in function set it
	if (m == 0) {
		std::cout << "Max number: ";
		std::cin >> m;
		m++;
	}

	//if x0 wasn't passed set it
	if (x0 == 0) {
		x0 = time(0) % m;
	}
	
	//set generator parameters
	int c = SetIncrement(m);
	int a = SetMultiplier(m);

	//set if conditions are met
	if (m < 0 or (a < 0 or a >= m) or (c < 0 or c >= m) or (x0 < 0 or x0 >= m))
		throw EXCEPTION_CODE::valueOutOfBoundaries;

	int* arr;
	arr = CreateArray<int>(n);

	//generate random numbers
	for (int i = 0; i < n; i++) {
		arr[i] = (a * x0 + c) % m;
		x0 = arr[i];
	}
	return arr;
}

void SetBestPair(int& j, int& k, int n, std::ifstream& readFromFile)
{
	int tempJ{}, tempK{};
	while (readFromFile.peek()!=EOF) {
		readFromFile >> tempJ;
		readFromFile >> tempK;
		//read until k is lesser than n
		if (tempK >= n)
			break;
		if (tempK > k) {
			j = tempJ;
			k = tempK;
		}
	}
}

int* ACG(int n)
{
	int m;
	int j{};
	int k{};
	std::ifstream readFromFile;

	//open file and set best j,k pairs
	OpenFile(readFromFile, "in.txt");
	SetBestPair(j, k, n, readFromFile);
	readFromFile.close();

	std::cout << "modulus: ";
	std::cin >> m;

	//m can't be < 0
	if(m<0)
		throw EXCEPTION_CODE::valueOutOfBoundaries;

	//fill array with random numbers using LCG algorithm
	int* randomNumbers = LCG(n,m);
	FlipArray(randomNumbers, n);


	//Generate using ACG algorithm
	k--;
	j--;
	for (int i = n - 1; i >= 0; i--) {
		randomNumbers[i] = (randomNumbers[j] + randomNumbers[k]) % m;
		k--;
		j--;
		if (k == -1)
			k = n-1;
		else if (j == -1)
			j = n-1;
	}

	return randomNumbers;
}
