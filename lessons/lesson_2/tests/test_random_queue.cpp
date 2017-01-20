#include "gtest/gtest.h"
#include "random_queue.h"

//Tests Better add multiple elements
TEST(RandomQueue, add_array_of_elements)
{
  //class instance
  RandomQueue<int> que;
  int array_one[5] = { 2, 5, 7, 8, 0 };
  int array_two[7] = { 10, 45, 60, 77, 55, 67, 89 };
  que.add(array_one);
  //remove some elements
  que.remove(); que.remove();
  que.add(array_two);
  //Checking backing array
  int *buff 
}

//Tests Random Removal
TEST(RandomQueue, Random_remove)
{
  int array[5] = { 1, 14, 20, 90, 75 };
  //class instance
  RandomQueue<int> que;
  que.add(array);
  int *buff = que.getAll();
  //change this
  EXPECT_TRUE(q.getAll()[0] != 10);
  EXPECT_TRUE(q.getAll()[2] != 20);
}
