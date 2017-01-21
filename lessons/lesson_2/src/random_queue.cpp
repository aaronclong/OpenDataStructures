#include "array_list.h"
#include "random_queue.h"
#include <algorithm>
#include <cstdlib> //random

//Single addition 
template <class T>
void RandomQueue<T>::add(T e)
{
  if ((this->size+1) >= this->length) this->resize();
  this->array[(this->cur+this->size) % this->length] = e;
  this->size++;
}

template <class T>
void RandomQueue<T>::add(T a[])
{
  //Function argument's length
  int the_length = sizeof(a) / sizeof(int);
  if ((this->size + the_length) >= this->length)
  {
    resize();
    add(a); // to double check that the length is sutable 
    return;
  }
  for(int i = 0; i < the_length; i++)
  {
     this->array[(this->cur+this->size+i)] = a[i];
     this->size++;
  }
}

template <class T>
T RandomQueue<T>::get(int i) const
{
  if (i > this->length) return;
  return this->array[(this->cur+this->size) % i];
}

//Will copy internal array and return it
//TODO: Double check if copy is working
template <class T>
T * RandomQueue<T>::getAll() const
{
  T *array_buff = new T[this->length];
  std::copy(this->array, this->array+this->length, array_buff);
  return array_buff;
}

template <class T>
void RandomQueue<T>::remove()
{

  int random = std::rand() % this->size;
  //Overwrite the array from the deleted element 
  //Check which side the shift should happen
  if ((this->size-this->cur) < (this->length/2))
    //left shift
  {
    std::copy(this->array+this->cur,
            this->array+(random+1),
            this->array+(this->cur+1));
    //Update incrementors
    this->cur++;
    this->size--;
  }
  else
  //Right Shift
  {
    std::copy(this->array+(1+random),
              this->array+this->length,
              this->array+random);
    //Update Incrementor
    this->size--;
  }
}

//Remove based on specify index
template<class T>
void RandomQueue<T>::remove(int i)
{
  //Checks the current position of elements
  int check = (this->size-this->size+i) % this->length;
  if (check < (this->length/2))
    //left shift
  {
    std::copy(this->array+this->cur,
            this->array+(check+1),
            this->array+(this->cur+1));
    //Update incrementors
    this->cur++;
    this->size--;
  }
  else
  //Right Shift
  {
    std::copy(this->array+(check+1),
              this->array+this->length,
              this->array+random);
    //Update Incrementor
    this->size--;
  }
}

//Expand or contract the backing array
template <class T>
void RandomQueue<T>::resize()
{
  T *resized_array = new T[this->length*2];
  //Fast copy for all items in the array until the end
  std::copy(this->array+this->cur,
            this->array+(this->length),
            resized_array);
  for(int i = 0; i < this->cur; i++) 
  {
    resized_array[this->length-this->cur+i] = this->array[i];
  }
  this->length = this->length * 2;
  T *buff = this->array;
  this->array = resized_array;
  delete buff;
}

template <class T>
void RandomQueue<T>::set(T e, int i)
{
  if (i > this->length) return;
  this->array[(this->cur+this->size+i) % this->length] = e;
}
