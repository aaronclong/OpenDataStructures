#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

//List backed by an Array Interface
template <class T> 
class ArrayList
{
  public:
    //overload add for arrays and more
    virtual void add(T e) = 0;
    virtual void add(T a[]) = 0;

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

// explicit instantiations
template class ArrayList<int>;
//template class ArrayList<int>;

#endif  // ARRAY_LIST_H_
