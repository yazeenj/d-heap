#include <iostream>
#include <cassert>
#include <random>
#include <chrono>
#include <iomanip>
#include "dHeap.h"

const int STARTSIZE = 1000;
const int INCREMENT = 1000;
const int STOPSIZE = 100000;
const int width = 20;

void fillWithRandomNumbers(int arr[], int size);

template <typename T>
bool isSortedAscending(const T arr[], int size);

template <typename T>
void bubbleSortAscending(T arr[], int size);

template <typename T>
void sortWithHeapAscending(T arr[], int size);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int * nrs1 = new int[STOPSIZE];
	int * nrs2 = new int[STOPSIZE];

    std::cout << std::setw(width) << std::left << "Bubble sort" << "\t" << std::setw(width) << std::left << "Sorting with heap" << "\t" << "n\n";
    std::cout << "------------------------------\n";

    for (int n = STARTSIZE; n < STOPSIZE; n += INCREMENT)
    {
        /* Generating random numbers */
		fillWithRandomNumbers(nrs1, n);
		// Copy
		for (int i = 0; i < n; i++)
			nrs2[i] = nrs1[i];

        /* Bubble sort */
        auto t1_start = std::chrono::steady_clock::now(); // start clock
        bubbleSortAscending(nrs1, n);
        auto t1_end = std::chrono::steady_clock::now(); // end clock
        auto diff1 = t1_end - t1_start;

        /* Sorting with heap */
        auto t2_start = std::chrono::steady_clock::now(); // start clock
        sortWithHeapAscending(nrs2, n);
        auto t2_end = std::chrono::steady_clock::now(); // end clock
        auto diff2 = t2_end - t2_start;

        /* Assertion and printing out time */
        assert(isSortedAscending<int>(nrs1, n) == true);
        std::cout << std::setw(width) << std::left <<  std::chrono::duration<double, std::milli>(diff1).count() << "\t";
        assert(isSortedAscending<int>(nrs2, n) == true);
        std::cout << std::setw(width)<< std::left << std::chrono::duration<double, std::milli>(diff2).count() << "\t";

        std::cout << std::setw(width) << std::right << n << std::endl;
    }

	std::cout  << std::endl << "Done Sorting" << std::endl;

    /* deallocating memory */
    delete [] nrs1;
    delete [] nrs2;
    return 0;
}

void fillWithRandomNumbers(int arr[], int size)
{
    std::random_device rd;
    std::uniform_int_distribution<int> uniformDistribution(0, size);

    for (int i = 0; i < size; i++)
        arr[i] = uniformDistribution(rd);
}

template <typename T>
bool isSortedAscending(const T arr[], int size)
{
    bool isSorted = true;
    for (int i = 0; i < size - 1 && isSorted == true; i++)
    {
        if (arr[i] > arr[i + 1])
            isSorted = false;
    }
    return isSorted;
}

template <typename T>
void bubbleSortAscending(T arr[], int size)
{
	/* Your implementation of bubble sort */

	bool swap = true;
	for (int a = 0; a < size; a++) {
		swap = false;
		for (int i = 0; i < (size-1); i++) {
			if (arr[i] > arr[i + 1]) {
				//swap
				T temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swap = true;
			}
		}
		if (swap == false) {
			break;
		}

	}

}

template <typename T>
void sortWithHeapAscending(T arr[], int size)
{
	/* Your implementation */
	// Make sure that your heap does not expand
	dHeap<T> heap(2, size);
	
	for (int i = 0; i < size; i++)
	{
		heap.push(arr[i]);
	}
	
	//i = (size - 1); i > 0;
	for (int i = (size - 1); i >= 0; i--)
	{
		arr[i] = heap.pop();
	}

}
