#pragma once 

#ifndef SIMPLELINKEDLISTTEMPLATEHPP
#define SIMPLELINKEDLISTTEMPLATEHPP

#include <iostream>
#include "simpleLinkedListTemplate.h"
using namespace std;


template <class T>
ListNode<T>::ListNode(T n)
{
	_item = n;
	_next = NULL;
}

template <class T>
void List<T>::insertHead(T n)
{
	ListNode<T> *aNewNode = new ListNode<T>(n);
	aNewNode->_next = _head;
	_head = aNewNode;
	_size++;
};

template <class T>
void List<T>::removeHead()
{
	if (_size > 0) {
		ListNode<T> *temp = _head;
		_head = _head->_next;
		delete temp;
		_size--;
	}
}

template <class T>
void List<T>::print(bool withNL) {

	ListNode<T> *temp = _head;
	while (temp) {
		cout << temp->_item;
		if (withNL)
			cout << endl;
		else
			cout << " ";
		temp = temp->_next;
	}
	cout << endl;
	  
}

template <class T>
bool List<T>::exist(T n) {

	// implementing linear search to check if item exists
	for (auto listNodePtr = _head; listNodePtr != NULL; listNodePtr = listNodePtr->_next) {
		if (listNodePtr->_item == n) {
			return true;
		}
	}
	return false; 
}

template <class T>
T List<T>::headItem()
{
	if (_size)
		return *_head;
}

template <class T>
T List<T>::extractMax()
{

	// if there are duplicates maximas in the list, return the leftmost one (the one closest to the _head)

	// return immediately if there is only one item in the list
	cout << "printing size: " << _size << endl;
	if (_size == 1) {
		T output(_head->_item);
		delete _head;
		cout << output << endl;
		return output;
	}

	//first determine position and max item
	ListNode<T> *maximum = _head;
	int index = 0;
	int maxIndex = 0;

	for (ListNode<T>* listNodePtr = _head; listNodePtr != NULL; listNodePtr = listNodePtr->_next) {
		if (listNodePtr->_item > maximum->_item) {
			maximum = listNodePtr;
			maxIndex = index;
		}
		index++;
	}

	// access node just before the max in the list
	ListNode<T> *beforeMaximum = _head;
	for (int i = 0; i < maxIndex - 1; ++i) {
		beforeMaximum = beforeMaximum->_next;
	}


	// point node before max to the node after max
	

	if (beforeMaximum == _head) { // edge case if the max item is the first in the list
		_head = maximum->_next;
	} else {
		beforeMaximum->_next = maximum->_next;
	}
	// reduce size 
	_size --;
	
	// instantiate an output then delete maximum
	T output(maximum->_item);
	delete maximum;

	// should we free up the memory to extract?
	cout << "printing output from extractMax(): " << output << endl;
	return output;
}

template <class T>
void List<T>::reverseOp() {

}



template <class T>
List<T>::~List()
{
	while (_head)
		removeHead();
};


#endif
