#ifndef MIN_PQ_H
#define MIN_PQ_H

#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class min_pq_error : public std::logic_error
{
public:
  explicit min_pq_error(const std::string& what_arg = "")
    : std::logic_error(what_arg) {}
};

// MinPQ class
//
// CONSTRUCTION: with an optional capacity (that defaults to 100)
//
// ******************PUBLIC OPERATIONS*********************
// void insert(x)       --> Insert x
// deleteMin(minItem)   --> Remove (and optionally return) smallest item
// Comparable findMin() --> Return smallest item
// bool isEmpty()       --> Return true if empty; else false
// void makeEmpty()     --> Remove all items
// ******************ERRORS********************************
// Throws min_pq_error as warranted

template <typename Comparable>
class MinPQ
{
public:

  explicit MinPQ(int capacity = 100)
    : array(capacity + 1), currentSize(0), orderOK(true) {}

  explicit MinPQ(const vector<Comparable> & items)
    : array(items.size() + 10), currentSize(items.size(), orderOK(false))
  {
    for(int i = 0; i < items.size(); i++)
      array[i + 1] = items[i];
    fixHeap();
  }

  bool isEmpty() const
  {
    return currentSize == 0;
  }

  /**
   * Find the smallest item in the priority queue.
   * Return the smallest item, or throw min_pq_error if empty.
   */
  const Comparable & findMin()
  {
    if(isEmpty())
      throw min_pq_error("findMin: tom heap");
      
    if(!orderOK)
    {
        fixHeap();
    }
    
    return array[1];
  }

  /**
   * Insert item x, maintaining heap order.
   * Duplicates are allowed.
   */
  void insert(const Comparable & x)
  {
    checkSize();

    // Percolate up
    int hole = ++currentSize;
    for( ; hole > 1 && x < array[hole / 2]; hole /= 2)
      array[hole] = array[hole / 2];
    array[hole] = x;
  }

  /**
   * Insert item x, without maintaining heap order.
   *  Duplicates are allowed.
   */
  void toss(const Comparable & x)
  {
    checkSize();
    array[++currentSize] = x;

    if(currentSize != 1 && orderOK)
    {
        if(array[currentSize/2] > x)
        {
            orderOK = false;
        }
    }
  }
   
  /**
   * Remove the minimum item and place it in minItem.
   * Throws min_pq_error if empty.
   */
  void deleteMin(Comparable & minItem)
  {
    if(isEmpty())
      throw min_pq_error("deleteMin: tom heap");

    minItem = findMin();
    array[1] = array[currentSize--];
    percolateDown(1);
  }

  void makeEmpty()
  { currentSize = 0; }

private:
  int                currentSize;  // Number of elements in heap
  bool               orderOK;      // True if heap order is guaranteed
  vector<Comparable> array;        // The heap array


  /**
   * Establish heap order property from an arbitrary
   * arrangement of items. Runs in linear time.
   */
  void fixHeap()
  {
    for(int i = currentSize / 2; i > 0; i--)
      percolateDown(i);
    orderOK = true;
  }

  /**
   * Internal method to percolate down in the heap.
   * hole is the index at which the percolate begins.
   */
  void percolateDown(int hole)
  {
    int child;
    Comparable tmp = array[hole];

    for( ; hole * 2 <= currentSize; hole = child)
      {
	child = hole * 2;
	if(child != currentSize && array[child + 1] < array[child])
	  child++;
	if(array[child] < tmp)
	  array[hole] = array[child];
	else
	  break;
      }
    array[hole] = tmp;
  }

  /**
   * Doubles the heap array if full
   */
  void checkSize()
  {
    if(currentSize == array.size() - 1)
      array.resize(array.size() * 2);
  }
};

#endif
