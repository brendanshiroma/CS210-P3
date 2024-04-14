/*
 * Max-heap data structure
 */
#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <stdexcept>
using namespace std;

template<typename T>
class Heap
{
public:
  Heap();
  Heap(bool isMinHeap);
  Heap(const T elements[], int arraySize);
  void add(const T& element);
  T remove();
  int getSize() const; 
  
private:
  vector<T> v;
  bool isMax = true;
  void _swap(int idx1, int idx2);
};

// Empty max-heap
template<typename T>
Heap<T>::Heap() { }

// Empty min-heap is boolean is true
template<typename T>
Heap<T>::Heap(bool isMinSort) : isMax(!isMinSort) { } 

// Initializes max-heap with elements in an array
template<typename T>
Heap<T>::Heap(const T elements[], int arraySize)
{
  for (int i = 0; i < arraySize; i++) {
    v.push_back(elements[i]);
  }
}

// Insert element into the heap and maintain the heap property
template<typename T>
void Heap<T>::add(const T& element)
{
  v.push_back(element);
  int currentIndex = v.size() - 1;
    while (currentIndex > 0) {
      int parentIndex = (currentIndex - 1) / 2;
      if (isMax) {
        if (v[currentIndex] > v[parentIndex]) {
          _swap(currentIndex, parentIndex);
        }
        else {
          break;
        }
      }
      else {
        if (v[currentIndex] < v[parentIndex]) {
          _swap(currentIndex, parentIndex);
        }
        else {
          break;
        }
      }
      currentIndex = parentIndex;
    }
}

// Exchange the elements in the vector at the given indexes
template<typename T>
void Heap<T>::_swap(int idx1, int idx2)
{
  T temp = v[idx1];
  v[idx1] = v[idx2];
  v[idx2] = temp;
}

// Remove the root from the heap
template<typename T>
T Heap<T>::remove()
{
  if (v.size() == 0) {
    throw runtime_error("Heap is empty");
  }
  T element = v[0];
	v[0] = v.back();
  v.pop_back();
  int currentIndex = 0;
  while (currentIndex < v.size()) {
    int leftChildIndex = 2 * currentIndex + 1;
    int rightChildIndex = 2 * currentIndex + 2;
    if (leftChildIndex >= v.size()) {
      break;
    }
    int targetIndex = 0;
    if (rightChildIndex < v.size()) {
      if (isMax) {
        if (v[leftChildIndex] > v[rightChildIndex]) {
          targetIndex = leftChildIndex;
        } else {
          targetIndex = rightChildIndex;
        }
      } else {
          if (v[leftChildIndex] < v[rightChildIndex]) {
            targetIndex = leftChildIndex;
          } else {
            targetIndex = rightChildIndex;
          }
      }
    } else {
      targetIndex = leftChildIndex;
      }
        if (isMax) {
            if (v[currentIndex] < v[targetIndex]) {
                _swap(currentIndex, targetIndex);
                currentIndex = targetIndex;
            } else {
                break;
            }
        } else {
            if (v[currentIndex] > v[targetIndex]) {
                _swap(currentIndex, targetIndex);
                currentIndex = targetIndex;
            } else {
                break;
            }
        }
    }
  return element;
}

// Get the number of elements in the heap
template<typename T>
int Heap<T>::getSize() const
{
   return v.size();
}

#endif
