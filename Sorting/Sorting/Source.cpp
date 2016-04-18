#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;
const long int ARRAY_SIZE = 32000;
int * bubbleSort(int * toSort, int size)
{
	int temp;
	bool unsorted = true;
	while (unsorted)
	{
		unsorted = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (toSort[i] > toSort[i + 1])
			{
				temp = toSort[i + 1];
				toSort[i + 1] = toSort[i];
				toSort[i] = temp;
				unsorted = true;

			}

		}

	}
	return toSort;
}
int * coctailShakerSort(int * toSort, int size)
{
	int temp;
	bool unsorted = true;
	while (unsorted)
	{
		unsorted = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (toSort[i] > toSort[i + 1])
			{
				temp = toSort[i + 1];
				toSort[i + 1] = toSort[i];
				toSort[i] = temp;
				unsorted = true;

			}

		}
		for (int i = size - 1; i >= 0; i--)
		{
			if (toSort[i] > toSort[i + 1])
			{
				temp = toSort[i + 1];
				toSort[i + 1] = toSort[i];
				toSort[i] = temp;
				unsorted = true;

			}

		}


	}
	return toSort;
}
int * bubbleSortLastChange(int * toSort, int size)
{
	int temp;
	int lastChange = 0;
	int togo = ARRAY_SIZE - 1;
	int i = 0;
	bool unsorted = true;

	while (unsorted)
	{
		unsorted = false;
		for (int i = 0; i < togo - 1; i++)
		{
			if (toSort[i] > toSort[i + 1])
			{
				temp = toSort[i + 1];
				toSort[i + 1] = toSort[i];
				toSort[i] = temp;
				unsorted = true;

				lastChange = i;
				if (i == togo - 1)
				{
					togo = lastChange;
				}


			}

		}


	}
	return toSort;
}
int * selectionSort(int * toSort, int size)
{
	int temp;


	int i, j;


	for (j = 0; j < size - 1; j++) {

		int iMin = j;

		for (i = j + 1; i < size; i++) {

			if (toSort[i] < toSort[iMin]) {

				iMin = i;
			}
		}

		if (iMin != j) {
			//swap(toSort[j], toSort[iMin]);
			temp = toSort[j];
			toSort[j] = toSort[iMin];
			toSort[iMin] = temp;
		}
	}
	return toSort;

}
int * insertionSort(int * toSort, int size)
{
	int temp;
	for (int i = 1; i < size; i++)
	{
		int j = i;
		while (j > 0 && toSort[j - 1] > toSort[j])
		{
			temp = toSort[j];
			toSort[j] = toSort[j - 1];
			toSort[j - 1] = temp;
			//swap(toSort[j], toSort[j - 1]);
				j = j - 1;
		}
	}
	return toSort;
}
int * insertionSortOneAssignment(int * toSort, int size)
{
	int temp;
	int j;
	for (int i = 2; i < size; i++)
	{
		temp = toSort[i];
			j = i - 1;
		while ((j > 0) && (toSort[j] > temp))
		{
			toSort[j + 1] = toSort[j];
			j = j - 1;
		}
				toSort[j + 1] = temp;
		}
	return toSort;
	}


int main()
{
	srand((int)time(NULL));
	int toSort[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		toSort[i] = rand();
	}
	cout << "BubbleSort: ";
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	bubbleSort(toSort, ARRAY_SIZE);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(t2 - t1).count();
	float time = duration / (float)1000;
	cout << time << "ms" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		toSort[i] = rand();
	}
	cout << "BubbleSortWithLastChange: ";
	t1 = high_resolution_clock::now();
	bubbleSortLastChange(toSort, ARRAY_SIZE);
	t2 = high_resolution_clock::now();

	duration = duration_cast<microseconds>(t2 - t1).count();
	time = duration / (float)1000;
	cout << time << "ms" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		toSort[i] = rand();
	}
	cout << "CoCtailShakerSort: ";
	t1 = high_resolution_clock::now();
	coctailShakerSort(toSort, ARRAY_SIZE);
	t2 = high_resolution_clock::now();

	duration = duration_cast<microseconds>(t2 - t1).count();
	time = duration / (float)1000;
	cout << time << "ms" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		toSort[i] = rand();
	}
	cout << "SelectionSort: ";
	t1 = high_resolution_clock::now();
	selectionSort(toSort, ARRAY_SIZE);
	t2 = high_resolution_clock::now();

	duration = duration_cast<microseconds>(t2 - t1).count();
	time = duration / (float)1000;
	cout << time << "ms" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		toSort[i] = rand();
	}
	cout << "InsertionSort: ";
	t1 = high_resolution_clock::now();
	insertionSort(toSort, ARRAY_SIZE);
	t2 = high_resolution_clock::now();

	duration = duration_cast<microseconds>(t2 - t1).count();
	time = duration / (float)1000;
	cout << time << "ms" << endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		toSort[i] = rand();
	}
	cout << "InsertionSortwith one assignment: ";
	t1 = high_resolution_clock::now();
	insertionSortOneAssignment(toSort, ARRAY_SIZE);
	t2 = high_resolution_clock::now();

	duration = duration_cast<microseconds>(t2 - t1).count();
	time = duration / (float)1000;
	cout << time << "ms" << endl;


	system("pause");
	return 0;
}