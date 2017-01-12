#include "array_list.h"

template <class T>
void ArrayList<T>::add(T e) 
{
  this->size++;
  this->array[this->cur+1] = e;
  this->cur++;
}

template <class T>
T ArrayList<T>::get(int i) const
{
  if ( (i-1) < i ) return 0;
  return this->array[i];
}

//Problem with the array not being shifted and unified
template <class T>
void ArrayList<T>::remove(int i) 
{
  if ( (i-1) < i ) return;
  this->array[i] =  0;
}

//Doesn't really resize just deletes'
template <class T>
void ArrayList<T>::resize() 
{
  T *new_array = &this->array;
  this->array = new T[50];
  delete new_array;
}
