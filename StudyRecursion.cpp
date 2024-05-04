#include <iostream>
using namespace std;

int factorial(int n)
{
	if (n == 0)		return 1;
	return factorial(n - 1) * n;
}

int sumAll(int n)
{
	if (n == 0)		return 0;
	// otherwise... if (n == 1)	return 1;
	return sumAll(n-1) + n;
}

int fibo(int n)
{
	if (n == 0)		return 0;
	if (n == 1)		return 1;
	return fibo(n-2) + fibo(n-1);
}

int even_sum(int n)
{
	if (n == 0)		return 0;
	if (n == 1)		return 0;
	if (n % 2 == 1)
		return even_sum(n - 1);
	else
		return n + even_sum(n - 2);
}

int arraySum(int arr[], int n)	// n; the number of elements
{
	if (n == 1)		return arr[0];
	return arr[n-1] + arraySum(arr, n-1);
}

int permutation(int n, int r)
{
	if (r == 0)		return 1;
	if (r == 1)		return n;
	if (n == 1)		return 1;
	return permutation(n-1, r-1) * n;
}

void sortNum(int* haveToBig, int* haveToSmall)
{
	if (*haveToBig < *haveToSmall)
	{
		int temp = *haveToBig;
		*haveToBig = *haveToSmall;
		*haveToSmall = temp;
	}
}

int gcd(int num1, int num2)
{
	sortNum(&num1, &num2);		// num1 has to be bigger than num2
	if (num2 == 0)		return num1;
	return gcd(num2 % num1, num1 % num2);
}

void palindrome(string word)
{
	if (word.length() == 1)
		cout << "Palindrome!" << endl;
	else if (word.length() == 0)
		cout << "Palindrome!" << endl;
	
	return palindrome(word);
}

int main()
{
	int arr[5] = {3, 9, 2, 10, 6};
	cout << "Recursion function result is... " << permutation(8, 0) << endl;
}