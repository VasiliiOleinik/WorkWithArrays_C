// DynArrays.cpp:
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <windows.h>

using std::cin;
using std::cout;
using std::setw;

void Show(int *x, int n);
int *Fill(int n, int a = -6, int b = 11);
void AddLast(int **x, int *n, int value);
void AddFirst(int **x, int *n, int value);
void AddAfterEven(int **x, int *n, int value);
void DeleteValue(int **x, int *n, int value);

int _tmain(int argc, _TCHAR *argv[])
{
	int n; // Current array size
	int i;
	srand(GetTickCount());
	SetConsoleOutputCP(1251);

	cout << "n? ";
	cin >> n;

	int *x = Fill(n);
	Show(x, n);

	// Add a new element to the end of the array x
	AddLast(&x, &n, 777);
	Show(x, n);

	// Add a new element to the beginning of the array x
	AddFirst(&x, &n, 888);
	Show(x, n);

	// Add after each odd element value
	AddAfterEven(&x, &n, 1414);
	Show(x, n);

	// Delete All Elements Set To 1414
	DeleteValue(&x, &n, 1414);
	Show(x, n);
	return 0;
} // _tmain

// Display array to screen
void Show(int *x, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(6) << x[i];
	} // for i
	cout << "\n";
} // Show

// Create an array and fill it with random numbers
int *Fill(int n, int a, int b)
{
	int *x = new int[n];
	for (int i = 0; i < n; i++)
		x[i] = a + rand() % (b - a + 1);
	return x;
} // Fill

// Add a new element to the end of the array
void AddLast(int **x, int *n, int value)
{
	int i;

	int *t = new int[*n + 1];
	for (i = 0; i < *n; i++)
		t[i] = (*x)[i];
	t[*n] = value;

	delete[] * x;
	*x = t;
	(*n)++;
} // AddLast

// Add a new element to the beginning of the array
void AddFirst(int **x, int *n, int value)
{
	int *t = new int[*n + 1];
	t[0] = value;
	int i, j = 1;
	for (i = 0; i < *n; i++, j++)
		t[j] = (*x)[i];

	delete[] * x;
	*x = t;
	(*n)++;
} // AddFirst

// Insert value after each odd
void AddAfterEven(int **x, int *n, int value)
{
	int j, i, n1 = 0;
	for (i = 0; i < *n; i++)
	{
		if ((*x)[i] % 2 != 0)
			n1++;
	} // for i

	int *t = new int[*n + n1];
	for (i = j = 0; i < *n; i++, j++)
	{
		t[j] = (*x)[i];
		if ((*x)[i] % 2 != 0)
		{
			t[++j] = value;
		} // if
	}	 // for i, j

	delete[] * x;
	*x = t;
	*n = *n + n1;
} // AddAfterEven

// Remove all elements equal to the value of the array
void DeleteValue(int **x, int *n, int value)
{
	int j, i, n1 = 0;
	for (i = 0; i < *n; i++)
	{
		if ((*x)[i] == value)
			n1++;
	} // for i

	int *t = new int[*n - n1];
	for (i = j = 0; i < *n; i++)
	{
		if ((*x)[i] == value)
			continue;
		t[j++] = (*x)[i];
	} // for i, j

	delete[] * x;
	*x = t;
	*n = *n - n1;
} // DeleteValue