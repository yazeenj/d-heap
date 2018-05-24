#ifndef DHEAP_H
#define DHEAP_H

#include "IHeap.h"
#include <iostream>

template <typename T>
class dHeap : public IHeap<T>
{
private:
	int heapSize;
	int dValue;
	T *elements;
	int nrOfelements;

public:
	dHeap(int d);
	~dHeap();

	void extend();

	//imp-functions
	void push(const T & item);
	T pop();
	T peek() const;
	int size() const;
	int getdValue() const;

};


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

	this->dValue = d;
	this->heapSize = 5;
	this->nrOfelements = 0;
	this->elements = new T[heapSize];
}

template <typename T>
dHeap<T>::~dHeap() {
	delete[] this->elements;
}

template <typename T>
void dHeap<T>::push(const T & item) {
	if (this->nrOfelements == this->heapSize) {

		this->extend();

		this->elements[this->nrOfelements] = item;
		this->nrOfelements++;

	}
	else {
		this->elements[this->nrOfelements] = item;
		this->nrOfelements++;
	}

}

template <typename T>
T dHeap<T>::pop() {
	if (this->nrOfelements == 0) {
		return -1;
	}
	T temp = this->elements[0];
	this->elements[0] = this->elements[this->nrOfelements - 1];
	this->nrOfelements--;
	return temp;
}

template <typename T>
T dHeap<T>::peek() const {

	if (this->nrOfelements == 0) {
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


#endif 
