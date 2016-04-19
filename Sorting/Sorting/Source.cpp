#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;
long int ARRAY_SIZE = 32000;
int stringLength = 7;
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
		for (int i = 0; i < togo; i++)
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
int * insertionSort(int * toSort, int lo, int hi)
{
	int temp;
	for (int i = lo+1; i < hi; i++)
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
void insertionSortOneAssignment(int toSort[], int size)
{
	int temp;
	int j;
	for (int i = 1; i < size; i++)
	{
		temp = toSort[i];
			j = i - 1;
		while ((j >= 0) && (toSort[j] > temp))
		{
			toSort[j + 1] = toSort[j];
			j = j - 1;
		}
				toSort[j + 1] = temp;
		}
	
	}
int * shellSortCiura(int * toSort, int size)
{
	int gaps[] = { 701, 301, 132, 57, 23, 10, 4, 1 };
	int gapsLength = 8;
	int temp;
	int j;
		
	for(int gap = 0;gap < gapsLength;gap++)
	{
			for (int i = gaps[gap]; i < size; i++)
			{
				
				temp = toSort[i];
					for (j = i; (j >= gaps[gap]) && (toSort[j - gaps[gap]] > temp); j -= gaps[gap])
					{
						toSort[j] = toSort[j - gaps[gap]];
						
					}
					toSort[j] = temp;
			}
	}
		return toSort;
}
int * shellSortShell(int * toSort, int size)
{
	int gaps[22];
	int gapsLength;
	int temp;
	int gaps_iterator = 0;
	int k = 1;
	int j;
	int shellGap;
	while (gaps[gaps_iterator-1] != 1)
	{
		gaps[gaps_iterator] = round(size / (pow(2, k)));
		k++;
		gaps_iterator++;

	}
	gapsLength = gaps_iterator;

	for (int gap = 0; gap < gapsLength; gap++)
	{
		for (int i = gaps[gap]; i < size; i++)
		{

			temp = toSort[i];
			for (j = i; (j >= gaps[gap]) && (toSort[j - gaps[gap]] > temp); j -= gaps[gap])
			{
				toSort[j] = toSort[j - gaps[gap]];

			}
			toSort[j] = temp;
		}
	}
	return toSort;
}
int partitionLeftmost(int tablica[], int p, int r) 
{
	int x = tablica[p]; 
	int i = p, j = r, w; 
	while (true) 
	{
		while (tablica[j] > x) 
			j--;
		while (tablica[i] < x) 
			i++;
		if (i < j) 
		{
			w = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = w;
			i++;
			j--;
		}
		else 
			return j;
	}
}
void quickSortLeftmost(int tablica[], int p, int r) 
{
	int q;
	if (p < r)
	{
		q = partitionLeftmost(tablica, p, r); 
		quickSortLeftmost(tablica, p, q); 
		quickSortLeftmost(tablica, q + 1, r); 
	}
}
int partitionMiddle(int tablica[], int p, int r)
{
	int x = tablica[(p+r)/2];
	int i = p, j = r, w;
	while (true)
	{
		while (tablica[j] > x)
			j--;
		while (tablica[i] < x)
			i++;
		if (i < j)
		{
			w = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = w;
			i++;
			j--;
		}
		else
			return j;
	}
}
void quickSortMiddle(int tablica[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = partitionMiddle(tablica, p, r);
		quickSortMiddle(tablica, p, q);
		quickSortMiddle(tablica, q + 1, r);
	}
}
int partitionRandom(int tablica[], int p, int r)
{
	int x = tablica[(rand() % ((r-p)+ 1) + p)];
	int i = p, j = r, w;
	while (true)
	{
		while (tablica[j] > x)
			j--;
		while (tablica[i] < x)
			i++;
		if (i < j)
		{
			w = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = w;
			i++;
			j--;
		}
		else
			return j;
	}
}
void quickSortRandom(int tablica[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = partitionRandom(tablica, p, r);
		quickSortRandom(tablica, p, q);
		quickSortRandom(tablica, q + 1, r);
	}
}
void quickSortWithInsertion(int tablica[], int p, int r)
{
	int q;
	if (p < r)
	{
		q = partitionMiddle(tablica, p, r);
		if ((q < ((r - p) / 10)))
		{
			insertionSort(tablica, p, q);
			quickSortMiddle(tablica, q + 1, r);
		}
		else if (q > (r - ((r - p) / 10)))
		{
			quickSortMiddle(tablica, p, q);
			insertionSort(tablica, q + 1, r);
		}
		else
		{
			quickSortMiddle(tablica, p, q);
			quickSortMiddle(tablica, q + 1, r);
		}
	}
}
void checkIfSorted(int table[], int size)
{
	bool sorted = true;
	for (int i = 0; i < size-1; i++)
	{
		if (table[i + 1] < table[i])
		{
			sorted = false;
			break;
		}
	}
	if (sorted)
	{
		cout << "Table is sorted" << endl;
	}
	else
	{
		cout << "Table is unsorted" << endl;
	}
}
//string sorting
void copyString(char * destination, char * source,int length)
{
	for (int i = 0; i < length; i++)
	{
		destination[i] = source[i];
	}
}
char ** generateStrings(int noOfStrings, int stringLength)
{
	char ** stringTable = new char*[noOfStrings];
	for (int i = 0; i < noOfStrings; i++)
	{
		stringTable[i] = new char[stringLength];
	}
	for (int j = 0; j < noOfStrings; j++)
	{
		for (int k = 0; k < stringLength; k++)
		{
			stringTable[j][k] = (rand() % ((122 - 97) + 1) + 97);
		}
		
	}
	
	return stringTable;
}
bool checkIfBigger(char * string1, char * string2, int stringLength)
{
	bool bigger = false;
		for (int i = 0; i < stringLength; i++)
		{
			if (string1[i] > string2[i])
			{
				bigger = true;
				break;
				
			}
			else if (string1[i] == string2[i])
			{
				bigger = false;
			}
			else if ((string1[i] == string2[i]) && (i == (stringLength - 1)))
			{
				bigger = false;
			}
			else
			{
				bigger = false;
				break;
			}
			

		}
		return bigger;

}
bool checkIfSmaller(char * string1, char * string2, int stringLength)
{
	bool smaller = false;
	for (int i = 0;(( i < stringLength)); i++)
	{
		if (string1[i] < string2[i])
		{
			smaller = true;
			break;
			
		}
		else if (string1[i] == string2[i])
		{
			smaller = false;
		}
		else if ((string1[i] == string2[i]) && (i == (stringLength - 1)))
		{
			smaller = false;
			
		}
		else
		{
			smaller = false;
			break;
			
		}
	}
	return smaller;
}
void checkIfSorted(char ** toCheck, int size)
{
	bool sorted = true;
	for (int i = 0; i < size - 1; i++)
	{
		if (checkIfSmaller(toCheck[i + 1],toCheck[i],stringLength))
		{
			sorted = false;
			break;
		}
	}
	if (sorted)
	{
		cout << "Table is sorted" << endl;
	}
	else
	{
		cout << "Table is unsorted" << endl;
	}
}
void swapStrings(char * string1, char * string2, int stringLength)
{
	char temp;
	for (int i = 0; i < stringLength; i++)
	{
		temp = string1[i];
		string1[i] = string2[i];
		string2[i] = temp;
	}
}
void bubbleSort(char ** toSort, int size)
{
	bool unsorted = true;
	while (unsorted)
	{
		unsorted = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (checkIfBigger(toSort[i], toSort[i + 1],stringLength))
			{
				swapStrings(toSort[i], toSort[i + 1],stringLength);
				unsorted = true;

			}

		}
		

	}
	
}
void coctailShakerSort(char ** toSort, int size)
{
	int temp;
	bool unsorted = true;
	while (unsorted)
	{
		unsorted = false;
		for (int i = 0; i < size - 2; i++)
		{
			if (checkIfBigger(toSort[i],toSort[i + 1],stringLength))
			{
				swapStrings(toSort[i + 1], toSort[i], stringLength);
				unsorted = true;

			}

		}
		for (int i = size - 2; i >= 0; i--)
		{
			if (checkIfBigger(toSort[i], toSort[i + 1], stringLength))
			{
				swapStrings(toSort[i + 1], toSort[i], stringLength);
				unsorted = true;
			}

		}

	}
	
}
void bubbleSortLastChange(char ** toSort, int size)
{
	int temp;
	int lastChange = 0;
	int togo = ARRAY_SIZE - 1;
	int i = 0;
	bool unsorted = true;

	while (unsorted)
	{
		unsorted = false;
		for (int i = 0; i < togo; i++)
		{
			if (checkIfBigger(toSort[i],toSort[i + 1],stringLength))
			{
				swapStrings(toSort[i], toSort[i + 1], stringLength);
				unsorted = true;

				lastChange = i;
				if (i == togo - 1)
				{
					togo = lastChange;
				}


			}

		}


	}
	
}
void selectionSort(char ** toSort, int size)
{
	int temp;


	int i, j;


	for (j = 0; j < size - 1; j++) {

		int iMin = j;

		for (i = j + 1; i < size; i++) {

			if (checkIfSmaller(toSort[i],toSort[iMin],stringLength)) 
			{

				iMin = i;
			}
		}

		if (iMin != j) {
			swapStrings(toSort[j], toSort[iMin], stringLength);
		}
	}
	

}
void insertionSort(char ** toSort, int lo, int hi)
{
	int temp;
	for (int i = lo + 1; i < hi; i++)
	{
		int j = i;
		while (j > 0 && checkIfBigger(toSort[j - 1],toSort[j],stringLength))
		{
			swapStrings(toSort[j], toSort[j - 1],stringLength);
			j = j - 1;
		}
	}
	
}
void insertionSortOneAssignment(char ** toSort, int size)
{
	char * temp = new char[stringLength];
	int j;
	for (int i = 1; i < size; i++)
	{
		copyString(temp,toSort[i],stringLength);
		j = i - 1;
		while ((j >= 0) && checkIfBigger(toSort[j],temp,stringLength))
		{
			copyString(toSort[j + 1],toSort[j],stringLength);
			j = j - 1;
		}
		copyString(toSort[j + 1],temp,stringLength);
	}

}
void shellSortCiura(char ** toSort, int size)
{
	int gaps[] = { 701, 301, 132, 57, 23, 10, 4, 1 };
	int gapsLength = 8;
	char * temp = new char[stringLength];
	int j;

	for (int gap = 0; gap < gapsLength; gap++)
	{
		for (int i = gaps[gap]; i < size; i++)
		{

			copyString(temp,toSort[i],stringLength);
			for (j = i; (j >= gaps[gap]) && (checkIfBigger(toSort[j - gaps[gap]],temp,stringLength)); j -= gaps[gap])
			{
				copyString(toSort[j], toSort[j - gaps[gap]],stringLength);

			}
			copyString(toSort[j],temp,stringLength);
		}
	}
	
}
void shellSortShell(char ** toSort, int size)
{
	int gaps[22];
	int gapsLength;
	char * temp = new char[stringLength];
	int gaps_iterator = 0;
	int k = 1;
	int j;
	int shellGap;
	while (gaps[gaps_iterator - 1] != 1)
	{
		gaps[gaps_iterator] = round(size / (pow(2, k)));
		k++;
		gaps_iterator++;

	}
	gapsLength = gaps_iterator;

	for (int gap = 0; gap < gapsLength; gap++)
	{
		for (int i = gaps[gap]; i < size; i++)
		{

			copyString(temp, toSort[i], stringLength);
			for (j = i; (j >= gaps[gap]) && (checkIfBigger(toSort[j - gaps[gap]], temp, stringLength)); j -= gaps[gap])
			{
				copyString(toSort[j], toSort[j - gaps[gap]], stringLength);

			}
			copyString(toSort[j], temp, stringLength);
		}
	}
	
}
int partitionLeftmost(char ** tablica, int p, int r)
{
	char * x = new char[stringLength];
	copyString(x,tablica[p],stringLength);
	int i = p, j = r;
	while (true)
	{
		while (checkIfBigger(tablica[j],x,stringLength))
			j--;
		while (checkIfSmaller(tablica[i],x,stringLength))
			i++;
		if (i < j)
		{
			swapStrings(tablica[i], tablica[j], stringLength);
			i++;
			j--;
		}
		else
			return j;
	}
}
void quickSortLeftmost(char ** tablica, int p, int r)
{
	int q;
	if (p < r)
	{
		q = partitionLeftmost(tablica, p, r);
		quickSortLeftmost(tablica, p, q);
		quickSortLeftmost(tablica, q + 1, r);
	}
}
int partitionMiddle(char ** tablica, int p, int r)
{
	char * x = new char[stringLength];
	copyString(x, tablica[(p + r) / 2], stringLength);
	int i = p, j = r;
	while (true)
	{
		while (checkIfBigger(tablica[j], x, stringLength))
			j--;
		while (checkIfSmaller(tablica[i], x, stringLength))
			i++;
		if (i < j)
		{
			swapStrings(tablica[i], tablica[j], stringLength);
			i++;
			j--;
		}
		else
			return j;
	}
}
void quickSortMiddle(char ** tablica, int p, int r)
{
	int q;
	if (p < r)
	{
		q = partitionMiddle(tablica, p, r);
		quickSortMiddle(tablica, p, q);
		quickSortMiddle(tablica, q + 1, r);
	}
}
int partitionRandom(char ** tablica, int p, int r)
{
	char * x = new char[stringLength];
	copyString(x, tablica[(rand() % ((r - p) + 1) + p)], stringLength);
	int i = p, j = r;
	while (true)
	{
		while (checkIfBigger(tablica[j], x, stringLength))
			j--;
		while (checkIfSmaller(tablica[i], x, stringLength))
			i++;
		if (i < j)
		{
			swapStrings(tablica[i], tablica[j], stringLength);
			i++;
			j--;
		}
		else
			return j;
	}
}
void quickSortRandom(char ** tablica, int p, int r)
{
	int q;
	if (p < r)
	{
		q = partitionRandom(tablica, p, r);
		quickSortRandom(tablica, p, q);
		quickSortRandom(tablica, q + 1, r);
	}
}
void quickSortWithInsertion(char ** tablica, int p, int r)
{
	int q;
	if (p < r)
	{
		q = partitionMiddle(tablica, p, r);
		if ((q < ((r - p) / 10)))
		{
			insertionSort(tablica, p, q);
			quickSortMiddle(tablica, q + 1, r);
		}
		else if (q >(r - ((r - p) / 10)))
		{
			quickSortMiddle(tablica, p, q);
			insertionSort(tablica, q + 1, r);
		}
		else
		{
			quickSortMiddle(tablica, p, q);
			quickSortMiddle(tablica, q + 1, r);
		}
	}
}



int main()
{
	int noOfIntsSlow[5] = { 8000,16000,32000,64000,128000 };
	int noOfIntsFast[5] = { 128000,512000,1024000,2048000,4096000 };
	int noOfStringsSlow[5] = { 2000,4000,8000,16000,32000 };
	int noOfStringsFast[5] = { 32000,64000,128000,512000,1024000 };
	float overallTime = 0;

	long long duration;
	high_resolution_clock::time_point t1;
	high_resolution_clock::time_point t2;
	srand((int)time(NULL));
	
	cout << "Slow sorting algorithms - integers" << endl;
	for (int i = 0; i < 5; i++)
	{
		ARRAY_SIZE = noOfIntsSlow[i];
		cout << endl << "Testing for " << ARRAY_SIZE << " ints" << endl << endl;
		int * toSort = new int[ARRAY_SIZE];
		cout << "BubbleSort: ";
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				toSort[i] = rand();
			}

			t1 = high_resolution_clock::now();
			bubbleSort(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
		cout << "BubbleSortWithLastChange: ";
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				toSort[i] = rand();
			}

			t1 = high_resolution_clock::now();
			bubbleSortLastChange(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
		cout << "CoCtailShakerSort: ";
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				toSort[i] = rand();
			}

			t1 = high_resolution_clock::now();
			coctailShakerSort(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
		cout << "SelectionSort: ";
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				toSort[i] = rand();
			}

			t1 = high_resolution_clock::now();
			selectionSort(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();

			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
		cout << "InsertionSort: ";
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				toSort[i] = rand();
			}

			t1 = high_resolution_clock::now();
			insertionSort(toSort, 0, ARRAY_SIZE);
			t2 = high_resolution_clock::now();

			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
		cout << "InsertionSortwith one assignment: ";
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				toSort[i] = rand();
			}

			t1 = high_resolution_clock::now();
			insertionSortOneAssignment(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();

			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
	}
	cout << "Fast sorting algorithms - integers" << endl;
	for (int i = 0; i < 5; i++)
	{
		ARRAY_SIZE = noOfIntsFast[i];
		cout << "Testing for " << ARRAY_SIZE << "ints" << endl << endl;
		int * toSort = new int[ARRAY_SIZE];
		cout << "ShellSortCiura: ";
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				toSort[i] = rand();
			}

			t1 = high_resolution_clock::now();
			shellSortCiura(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();

			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
		cout << "ShellSortShell: ";
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				toSort[i] = rand();
			}

			t1 = high_resolution_clock::now();
			shellSortShell(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();

			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
		cout << "QuickSort leftmost as pivot: ";
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				toSort[i] = rand();
			}

			t1 = high_resolution_clock::now();
			quickSortLeftmost(toSort, 0, ARRAY_SIZE - 1);
			t2 = high_resolution_clock::now();

			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
		cout << "QuickSort middle as pivot: ";
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				toSort[i] = rand();
			}

			t1 = high_resolution_clock::now();
			quickSortMiddle(toSort, 0, ARRAY_SIZE - 1);
			t2 = high_resolution_clock::now();

			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
		cout << "QuickSort random as pivot: ";
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				toSort[i] = rand();
			}

			t1 = high_resolution_clock::now();
			quickSortRandom(toSort, 0, ARRAY_SIZE - 1);
			t2 = high_resolution_clock::now();

			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
		cout << "QuickSort with InsertionSort: ";
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				toSort[i] = rand();
			}

			t1 = high_resolution_clock::now();
			quickSortWithInsertion(toSort, 0, ARRAY_SIZE - 1);
			t2 = high_resolution_clock::now();

			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
	}

	cout << "Slow sorting algorithms - strings" << endl;
	for (int i = 0; i < 5; i++)
	{
		char ** toSort;
		ARRAY_SIZE = noOfStringsSlow[i];
		cout << "No of strings: " << ARRAY_SIZE << endl << endl;

		cout << "Selection sort: ";
		for (int j = 0; j < 3; j++)
		{
			toSort = generateStrings(ARRAY_SIZE, stringLength);
			
			t1 = high_resolution_clock::now();
			selectionSort(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
		
		cout << "Insertion sort: ";
		for (int j = 0; j < 3; j++)
		{
			toSort = generateStrings(ARRAY_SIZE, stringLength);
			
			t1 = high_resolution_clock::now();
			insertionSort(toSort,0, ARRAY_SIZE);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);

		cout << "Insertion sort with one assignment: ";
		for (int j = 0; j < 3; j++)
		{
			toSort = generateStrings(ARRAY_SIZE, stringLength);
			
			t1 = high_resolution_clock::now();
			insertionSortOneAssignment(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);

		cout << "Bubble sort: ";
		for (int j = 0; j < 3; j++)
		{
			toSort = generateStrings(ARRAY_SIZE, stringLength);
		
			t1 = high_resolution_clock::now();
			bubbleSort(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);

		cout << "Bubble sort last change: ";
		for (int j = 0; j < 3; j++)
		{
			toSort = generateStrings(ARRAY_SIZE, stringLength);
		
			t1 = high_resolution_clock::now();
			bubbleSortLastChange(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);

		cout << "Coctail shaker sort: ";
		for (int j = 0; j < 3; j++)
		{
			toSort = generateStrings(ARRAY_SIZE, stringLength);
			cout << endl;
			t1 = high_resolution_clock::now();
			coctailShakerSort(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
		
	}

	cout << "Fast sorting algorithms - strings" << endl;
	for (int i = 0; i < 5; i++)
	{
		char ** toSort;
		ARRAY_SIZE = noOfStringsFast[i];
		cout << "No of strings: " << ARRAY_SIZE << endl << endl;

		cout << "Quicksort leftmost: ";
		for (int j = 0; j < 3; j++)
		{
			toSort = generateStrings(ARRAY_SIZE, stringLength);

			t1 = high_resolution_clock::now();
			quickSortLeftmost(toSort,0, ARRAY_SIZE-1);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);

		cout << "Quicksort middle: ";
		for (int j = 0; j < 3; j++)
		{
			toSort = generateStrings(ARRAY_SIZE, stringLength);

			t1 = high_resolution_clock::now();
			quickSortMiddle(toSort, 0, ARRAY_SIZE-1);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);

		cout << "Quicksort random: ";
		for (int j = 0; j < 3; j++)
		{
			toSort = generateStrings(ARRAY_SIZE, stringLength);

			t1 = high_resolution_clock::now();
			quickSortRandom(toSort,0, ARRAY_SIZE-1);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);
		

		cout << "Quicksort with insertion: ";
		for (int j = 0; j < 3; j++)
		{
			toSort = generateStrings(ARRAY_SIZE, stringLength);
			
			t1 = high_resolution_clock::now();
			quickSortWithInsertion(toSort,0, ARRAY_SIZE-1);
			
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);

		cout << "Shellsort Ciura: ";
		for (int j = 0; j < 3; j++)
		{
			toSort = generateStrings(ARRAY_SIZE, stringLength);

			t1 = high_resolution_clock::now();
			shellSortCiura(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);

		cout << "Shellsort Shell: ";
		for (int j = 0; j < 3; j++)
		{
			toSort = generateStrings(ARRAY_SIZE, stringLength);

			t1 = high_resolution_clock::now();
			shellSortShell(toSort, ARRAY_SIZE);
			t2 = high_resolution_clock::now();
			duration = duration_cast<microseconds>(t2 - t1).count();
			overallTime = overallTime + duration / (float)1000;

		}
		cout << overallTime / 3 << "ms" << endl;
		overallTime = 0;
		checkIfSorted(toSort, ARRAY_SIZE);

	}

	system("pause");
	return 0;
}