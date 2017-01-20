#include "gtest/gtest.h"
#include "random_queue.h"

TEST(RandomQueue_random_add, RandomQueue_random_add_test)
{
  RandomQueue<int> que;
  que.add(10);
  que.add(20);
  int *buff = que.getAll();
  EXPECT_TRUE(q.getAll()[0] != 10);
  EXPECT_TRUE(q.getAll()[2] != 20);
}
