#include "dHeap.h"

template <typename T>
dHeap<T>::dHeap(int d) {
	
	this->dValue = d;
	this->heapSize = 10;
	this->values = new T[heapSize];
}

template <typename T>
dHeap<T>::~dHeap() {

}

template <typename T>
void dHeap<T>::push(const T & item) {

}

template <typename T>
T dHeap<T>::pop() {

}

template <typename T>
T dHeap<T>::peek() const{

}

template <typename T>
int dHeap<T>::size() const {
	return this->heapSize;
}

template <typename T>
int dHeap<T>::getdValue() const{
	return this->dValue();
}