#include <algorithm>
#include "gtest/gtest.h"
#include "../src/inc/random_queue.h"

//Tests Better add multiple elements
TEST(RandomQueue, add_array_of_elements)
{
  //class instance
  RandomQueue<int> que;
  int array_one[5] = { 2, 5, 7, 8, 0 };
  int array_two[7] = { 10, 45, 60, 77, 55, 67, 89 };
  que.add(array_one);
  //remove some elements
  que.remove(0); que.remove(1);
  que.add(array_two);
  //Checking backing array
  int *buff = que.getAll();
  //Array to compare
  int cmp[10] = { 7, 8, 0, 10, 45, 60, 77, 55, 67, 89 };
  EXPECT_TRUE(std::equal(cmp, cmp+10, buff));
}

/* Tests Random Removal
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
*/