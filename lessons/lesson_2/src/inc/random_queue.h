#ifndef RANDOM_QUEUE_H_
#define RANDOM_QUEUE_H_

#include <algorithm>
#include "array_list.h"
#include <cstdlib> //random

template <class T>
class RandomQueue
{
  public:
    //Constructor
    RandomQueue();
    //Destructor
    ~RandomQueue();

    T *getAll() const;

    //Implementing the interfaces
    void add(T e); //single element 
    void add(int length, T a[]); //add an array
    T get(int i) const;
    void remove();
    void remove(int i);
    void set(T e, int i);

  private:
    unsigned int cur;
    //Fills gaps in the backing array
    //void shift();
  protected:
    T *array;
    unsigned int length;
    unsigned int size;
    void resize();
};

//template class RandomQueue<int>;
#endif  // RANDOM_QUEUE_H_
