#ifndef RANDOM_QUEUE_H_
#define RANDOM_QUEUE_H_

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
      this->cur = 0;
      this->length = 10; //The length of the array structure
      this->size = 0;
    }
    //Destructor
    ~RandomQueue()
    {
      delete this->array;
    }

    T *getAll();

    //Implementing the interfaces
    virtual void add(T e) const;
    virtual T *get(int i);
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
