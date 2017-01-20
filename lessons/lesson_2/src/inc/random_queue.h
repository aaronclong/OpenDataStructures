#ifndef RANDOM_QUEUE_H_
#define RANDOM_QUEUE_H_

#include "array_list.h"

template <class T>
class RandomQueue: public ArrayList
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

  private:
    unsigned int cur;
    //Fills gaps in the backing array
    //void shift();
};

#endif  // RANDOM_QUEUE_H_
