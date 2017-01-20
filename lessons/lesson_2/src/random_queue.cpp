#include "array_list.h"
#include "random_queue.h"
#include <algorithm>
#include <cstdlib> //random

//Random Addition in the Queue
template <class T>
void RandomQueue<T>::add(T e) const
{
  //Need to rewrite to accomidate circular array
  if ((this->size+1) >= this->length) this->resize();
  this->array[(this->cur+this->size) % this->length] = e;
  this->size++;
}

template <class T>
void RandomQueue<T>::remove()
{
  int random = std::rand() % this->size;
  //Overwrite the array from the deleted element 
  //TODO: Test to see if was done correctly
  //TODO: Rewrite to better accomodate quicker shift
  int shift = this->size -this->cur;
  std::copy(this->array+(1+random),
            this->array+this->length,
            this->array+random);
  this->array[random];
  this->size--;
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

//template <class T>
//void RandomQueue::shift()
//{}

//Will copy internal array and return it
//TODO: Double check if copy is working
template <class T>
T * RandomQueue<T>::getAll()
{
  T *array_buff = new T[this->length];
  std::copy(this->array, this->array+this->length, array_buff);
  return array_buff;
}