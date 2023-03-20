#pragma once
#define DEFAULTHEAPSIZE 1023
template <class T> class Heap {
protected:
  T *_heap;
  int _n;
  void _bubbleUp(int index);
  void _bubbleDown(int index);
  void _swap(int i , int j);
  int _lookFor(
      T x); // return the index of the item x, return -1 if not found
            // it is not a good/usual implementation, so we hide it from public
  int _parent_index(int i);
  int _larger_child_index (int i);

public:
  Heap() {
    _heap = new T[DEFAULTHEAPSIZE];
    _n = 0;
  };

  // int size() {return _n;};
  void insert(T);
  bool empty() { return _n == 0; };
  T extractMax();
  T peekMax() { return _heap[0]; };
  void printHeapArray();
  void printTree();
  void increaseKey(T from, T to);
  void decreaseKey(T from, T to);
  void deleteItem(T);

  ~Heap() { delete[] _heap; };
};

#include "heap.hpp"
