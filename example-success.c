#include "test.h"

BEGIN_TEST();

#define true 1
#define false 0

void test_bools()
{
  ASSERT(1 == true);
  ASSERT(0 == false);
}

void test_ints()
{
  ASSERT(1 == 1);
  ASSERT(2 == 2);
}

int main(void)
{
  TEST(bools);
  TEST(ints);
  TEST_REPORT();
  return TEST_RESULT();
}
