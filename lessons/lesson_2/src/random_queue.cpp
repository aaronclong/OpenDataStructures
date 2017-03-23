#include "inc/array_list.h"
#include "inc/random_queue.h"
#include <algorithm>
#include <stdlib.h>
#include <iostream> 
#include <cstdlib> //random

template <class T>
RandomQueue<T>::RandomQueue()
{
  this->array = new T[10];
      //Serves as J on delete entries
      this->cur = 0; //Marks the next element to be deleted
      this->length = 10; //The length of the array structure
      this->size = 0; //How many elements are currently being stored
}

template <class T>
RandomQueue<T>::~RandomQueue()
{
  delete this->array;
}

//Single addition 
template <class T>
void RandomQueue<T>::add(T e)
{
  std::cout << "This is happening" << std::endl;
  if ((this->size+1) >= this->length) this->resize();
  this->array[(this->cur+this->size) % this->length] = e;
  this->size++;
}

template <class T>
void RandomQueue<T>::add(int len, T a[])
{
  std::cout << "The Begining" << std::endl;
  std::cout << this->size << std::endl;
  std::cout << this->length << std::endl;
  std::cout << "Size and length: ";
  std::cout << (this->size + len) << std::endl;
  if ((this->size + len) >= this->length) resize(); // Maybe not expanding as soon enough, check soon?
  for(int i = 0; i < (this->size + len); i++)
  {
     std::cout << "In the loop: "; 
     std::cout << i << std::endl;
     std::cout << this->size << std::endl;
     this->array[(this->cur+this->size+i)] = a[i];
  }
  this->size += len;
}

template <class T>
T RandomQueue<T>::get(int i) const
{
  if (i > this->length) return 0;
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
    //std::copy(this->array+(check+1),
              //this->array+this->length,
              //this->array+(random);
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

template class RandomQueue<int>;