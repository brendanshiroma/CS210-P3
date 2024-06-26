/*
  HeapSort.h
  Usage:

  // Sort ascending into a vector
  vector<int> ascendingVector(heapSort(someHeap, true));
 
  // Sort descending into a vector
  vector<int> descendingVector(heapSort(someHeap, false));
*/
#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "Heap.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
vector<T> heapSort(Heap<T> heap, int increasingOrder)
{

  // Initialising the array to 
  // store elements
  vector<int> v;

  while (heap.getSize() > 0) {
    T element = heap.remove();
    v.push_back(element);
  }
  if (!increasingOrder) {
    reverse(v.begin(), v.end());
  }

  return v;
}
#endif
