#ifndef DHEAP_H
#define DHEAP_H

#include "IHeap.h"

template <typename T>
class dHeap : public IHeap<T>
{
private:
	int heapSize;
	int dValue;
	T *elements;
	int nrOfelements;

	//Heap functions
	int getParent(int index);
	int getChild(int index, int childPlace);
	int findBiggestChild(int index);

public:
	
	dHeap(int d);
	//constructer with size for HeapAscendingSort
	dHeap(int d, int size);
	~dHeap();
	
	//consrtuct&overide
	dHeap(const dHeap &other);
	void operator=(const dHeap &other);

	//Extend heapsize
	void extend();

	//imp-functions
	void push(const T & item);
	T pop();
	T peek() const;
	int size() const;
	int getdValue() const;

	//Extras
	bool isEmpty() const;
};

template <typename T>
dHeap<T>::dHeap(const dHeap &other) {
	this->dValue = other.dValue;
	this->heapSize = other.heapSize;
	this->nrOfelements = other.nrOfelements;

	this->elements = new T[this->heapSize];

	for (int i = 0; i < this->nrOfelements; i++) {
		this->elements[i] = other.elements[i];
	}

}

template <typename T>
void dHeap<T>::operator=(const dHeap &other) {
	if (this != &other) {
		this->dValue = other.dValue;
		this->heapSize = other.heapSize;
		this->nrOfelements = other.nrOfelements;

		delete[] this->elements;
		this->elements = new T[this->heapSize];

		for (int i = 0; i < this->nrOfelements; i++) {
			this->elements[i] = other.elements[i];
		}

	}
}

template <typename T>
void dHeap<T>::extend() {
	T *temp = new T[(this->heapSize+10)];
	for (int i = 0; i < this->heapSize;i++) {
		temp[i] = this->elements[i];
	}
	delete[] this->elements;
	elements = temp;
	this->heapSize = (this->heapSize + 10);
}

template <typename T>
dHeap<T>::dHeap(int d) {
	
	//d(d >1).
	if (d > 1) {
		this->dValue = d;
	}
	else {
		this->dValue = 2;
	}

	//init private-variables
	this->heapSize = 5;
	this->nrOfelements = 0;
	this->elements = new T[heapSize];
}

template <typename T>
dHeap<T>::dHeap(int d, int size) {

	//d(d >1).
	if (d > 1) {
		this->dValue = d;
	}
	else {
		this->dValue = 2;
	}

	//init private-variables
	this->heapSize = size;
	this->nrOfelements = 0;
	this->elements = new T[heapSize];
}

template <typename T>
dHeap<T>::~dHeap() {
	delete[] this->elements;
}

template <typename T>
void dHeap<T>::push(const T & item) {
	//If heap is full = extend
	if (this->nrOfelements == this->heapSize) {
		this->extend();
	}

	//Get index of the last parent
	int parentIndex = this->getParent(this->nrOfelements);

	//if this is not the first parent
	if (parentIndex != -1) {

		int newItemIndex = this->nrOfelements;
		//place at the end
		this->elements[newItemIndex] = item;

		//Swap until heap priority
		while (parentIndex != -1 && item > this->elements[parentIndex]) {

			this->elements[newItemIndex] = this->elements[parentIndex];
			this->elements[parentIndex] = item;

			newItemIndex = parentIndex;
			parentIndex = this->getParent(newItemIndex);

		}

	}
	//in case of first inserted item
	else {
		this->elements[0] = item;
	}

	this->nrOfelements++;
}

template <typename T>
T dHeap<T>::pop() {
	
	//If heap is empty
	if (this->isEmpty()) {
		return -1;
	}

	T returnItem = this->elements[0];
	this->elements[0] = this->elements[this->nrOfelements - 1];
	this->nrOfelements--;

	int parentIndex = 0;
	int biggestChild = this->findBiggestChild(parentIndex);
	T tempChild;

	while (biggestChild != -1 && this->elements[biggestChild] > this->elements[parentIndex]) {
		tempChild = this->elements[biggestChild];
		this->elements[biggestChild] = this->elements[parentIndex];
		this->elements[parentIndex] = tempChild;
		parentIndex = biggestChild;
		biggestChild = this->findBiggestChild(parentIndex);
	}

	return returnItem;

}

template <typename T>
T dHeap<T>::peek() const {

	if (this->isEmpty()) {
		return -1;
	}
	return this->elements[0];
}

template <typename T>
int dHeap<T>::size() const {
	return this->nrOfelements;
}

template <typename T>
int dHeap<T>::getdValue() const {
	return this->dValue;
}

//Private functions

template <typename T>
int dHeap<T>::getParent(int index) {
	/*
	Parent = ((index-1)/d)
	*/

	int returnVal = 0;

	//In-case of index is parent/root
	if (index == 0) {
		returnVal = -1;
	}
	else {

		returnVal = (index - 1) / this->dValue;

	}

	return returnVal;
}

template <typename T>
int dHeap<T>::getChild(int index, int childPlace) {
	/*
		Left/right child
		Child = index*2+1
	*/

	int returnVal = 0;
	
	if (childPlace < 1 || childPlace > this->dValue) {
		childPlace = 1;
	}

	returnVal = index * this->dValue + childPlace;
	
	//In case of non-complete parent
	if (returnVal >= this->nrOfelements) {
		returnVal = -1;
	}
	return returnVal;
}

template <typename T>
int dHeap<T>::findBiggestChild(int index) {
	
	int biggestChild = this->getChild(index,1);
	int nextChild = 0;

	if (biggestChild != -1) {
		//Min > 2
		for (int i = 2; i <= this->dValue && nextChild != -1; i++) {
			nextChild = this->getChild(index, i);
			if (nextChild != -1) {
				//this->elements[biggestChild] > this->elements[nextChild]
				if (this->elements[biggestChild] < this->elements[nextChild]) {
					biggestChild = nextChild;
				}
			}
		}
	}

	return biggestChild;
}

//Extras
template <typename T>
bool dHeap<T>::isEmpty() const {
	if (this->nrOfelements == 0) {
		return true;
	}
	return false;
}

#endif 
