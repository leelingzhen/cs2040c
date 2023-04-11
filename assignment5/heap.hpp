#pragma once
#include <math.h>
#include "heap.h"
#include <iostream>

#ifndef HEAPHPP
#define HEAPHPP

using namespace std;

template <class T>
int Heap<T>::_parent_index(int i) { 
    return floor(i - 1) / 2;
}

template <class T>
int Heap<T>::_larger_child_index (int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (_heap[left] > _heap[right] and left < _n) {
	return left;
    } else if (right < _n){
	return right;
    } else {
	return -1;
    }
}

template <class T>
void Heap<T>::_swap (int i, int j) {
    T temp = _heap[i];
    _heap[i] = _heap[j];
    _heap[j] = temp;
}


template <class T>
void Heap<T>::_bubbleUp(int index) {
    int parentIndex = _parent_index(index);
    while (_heap[index] > _heap[parentIndex]){
	// swapping parent with child nodes
	_swap(parentIndex, index);
	index = parentIndex;
	parentIndex = _parent_index(index);
    }

}

template <class T>
void Heap<T>::_bubbleDown(int index) {
    int child = _larger_child_index(index);


    while (_heap[child] > _heap[index] and child != -1){
	_swap(child, index);
	index = child;
	child = _larger_child_index(index);
    }

}

template <class T>
void Heap<T>::insert(T item) {
    if (_n == DEFAULTHEAPSIZE) { 
	std::cout << "heap max sized reached, unable to add element" << std::endl;
	return;
    }
    int i = _n;
    _heap[i] = item;
    _bubbleUp(i);
    _n ++;
}

template <class T>
T Heap<T>::extractMax() {
    T max_item = _heap[0];
    deleteItem(max_item);
    return max_item;

}


template <class T>
void Heap<T>::printHeapArray() {
	for (int i = 0; i < _n; i++)
		cout << _heap[i] << " ";
	cout << endl;
}

template <class T>
int Heap<T>::_lookFor(T x){ // not a very good implementation, but just use this for now.
    int i;
    for(i=0;i<_n;i++)
        if (_heap[i] == x)
            return i;
    
    return -1;
}

template <class T>
void Heap<T>::decreaseKey(T from, T to)
{
    int pos = _lookFor(from);
    _heap[pos] = to;
    _bubbleDown(pos);
}


template <class T>
void Heap<T>::increaseKey(T from, T to)
{
    int pos = _lookFor(from);
    _heap[pos] = to;
    _bubbleUp(pos);
}

template <class T>
void Heap<T>::deleteItem(T x)
{
    int pos = _lookFor(x);
    T last_item = _heap[_n -1];
    _swap(pos, _n - 1);
    _n --;
    if (x > last_item) {
	_bubbleDown(pos);
    } else {
	_bubbleUp(pos);
    }
}

template <class T>
void Heap<T>::printTree() {
    int parity = 0;
	if (_n == 0)
		return;
	int space = pow(2,1 + (int) log2f(_n)),i;
	int nLevel = (int) log2f(_n)+1;
	int index = 0,endIndex;
    int tempIndex;
	
	for (int l = 0; l < nLevel; l++)
	{
		index = 1;
        parity = 0;
		for (i = 0; i < l; i++)
			index *= 2;
		endIndex = index * 2 - 1;
		index--;
        tempIndex = index;
        while (index < _n && index < endIndex) {
            for (i = 0; i < space-1; i++)
                cout << " ";
            if(index==0)
                cout << "|";
            else if (parity)
                cout << "\\";
            else
                cout << "/";
            parity = !parity;
            for (i = 0; i < space; i++)
                cout << " ";
			index++;
		}
        cout << endl;
        index=tempIndex;
		while (index < _n && index < endIndex) {
			for (i = 0; i < (space-1-((int) log10(_heap[index]))); i++)
				cout << " ";
			cout << _heap[index];
			for (i = 0; i < space; i++)
				cout << " ";
			index++;
		}
		
		cout << endl;
		space /= 2;
	}

}






#endif
