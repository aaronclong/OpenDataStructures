#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

//List backed by an Array Interface
template <class T> 
class ArrayList
{
  public:
    virtual void add(T e) = 0;
    virtual void set(T e, int i) = 0;
    virtual T get(int i) const = 0;
    //Overloading methods to better accomodate more instances
    virtual void remove() = 0;
    virtual void remove(int i) = 0;

  protected:
    T *array;
    unsigned int length;
    unsigned int size;
    virtual void resize() = 0;
};

#endif  // ARRAY_LIST_H_
