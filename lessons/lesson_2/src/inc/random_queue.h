#ifndef RANDOM_QUEUE_H_
#define RANDOM_QUEUE_H_

#include <algorithm>
#include "array_list.h"
#include <cstdlib> //random

template <class T>
class RandomQueue: public ArrayList<T>
{
  public:
    //Constructor
    RandomQueue()
    {
      this->array = new T[10];
      //Serves as J on delete entries
      this->cur = 0; //Marks the next element to be deleted
      this->length = 10; //The length of the array structure
      this->size = 0; //How many elements are currently being stored
    }
    //Destructor
    ~RandomQueue()
    {
      delete this->array;
    }

    T *getAll() const;

    //Implementing the interfaces
    virtual void add(T e); //single element 
    virtual void add(T a[]); //add an array
    virtual T get(int i) const;
    virtual void remove();
    virtual void remove(int i);
    virtual void set(T e, int i);

  private:
    unsigned int cur;
    //Fills gaps in the backing array
    //void shift();
  protected:
    virtual void resize();
};

#endif  // RANDOM_QUEUE_H_
