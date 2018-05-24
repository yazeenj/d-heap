#include <iostream>
#include "dHeap.h"

using namespace std;

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	int arr[9] = {3,1,5,2,4,9,8,7,6};
	/*
	cout << "Unsorted: " << endl;
	for (int i = 0; i < 9; i++) {
		cout << arr[i] << " ";
	}

	bool swap = true;
	for (int a = 0; a < 9;a++) {
		swap = false;
		for (int i = 0; i < 8; i++) {
			if (arr[i] > arr[i + 1]) {
				//swap
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swap = true;
			}
		}
		if (swap == false) {
			break;
		}
		
	}

	cout << endl << "Sorted: " << endl;
	for (int i = 0; i < 9; i++) {
		cout << arr[i] << " ";
	}
	*/
		

	dHeap <int> test(5);
	for (int i = 0; i < 1000;i++) {
		test.push(i);
	}

	
	
	cout << endl;

	return 0;
}