#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

//List backed by an Array
template <class T> 
class ArrayList
{
  public:
  //constructor
    ArrayList()
    {
     array = new T[10];
     size = 0;
     cur = 0;
    }
    void add(T e);
    T get(int i) const;
    void remove(int i);
    void resize();

  private:
    T *array;
    unsigned int cur;
    unsigned int size;
};

#endif  // ARRAY_LIST_H_